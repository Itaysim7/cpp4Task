#include "Board.hpp"
#include <iostream>
using namespace std;
namespace WarGame
{
    Soldier*& Board::operator[](pair<int,int> location) 
    {
        return board[location.first][location.second];
    }
    
    Soldier* Board::operator[](pair<int,int> location) const
    {
    	return board[location.first][location.second];
    }
    
    void Board::move(uint player_number, pair<int,int> source, MoveDIR direction)
    {

        Soldier* brave = (*this)[source];
        if(brave==nullptr||brave->getPlayerNumber()!=player_number)
            throw invalid_argument("There is no soldier in that place on the board"); 
        pair<int, int> step;
		switch(direction)
		{
		    case Up:
		    {
		        step=make_pair(source.first+1,source.second);break;
		    }
		    case Down:
		    {
		        step=make_pair(source.first-1,source.second);break;
		    }
		    case Left:
		    {
		        step=make_pair(source.first,source.second-1);break;
		    }
		    case Right:
		    {
		        step=make_pair(source.first,source.second+1);break;
		    }
		    defalt :
		    {
		        throw invalid_argument("No such step"); 
		    }
		}
		if(step.first>board.size()-1||step.second>board.size()-1||step.first<0||step.second<0)
		    throw invalid_argument("Outside the board");
		if((*this)[step] != nullptr) 
			throw runtime_error("there is other player there!\n");
		 board[source.first][source.second]=nullptr;
		 board[step.first][step.second]=brave;
		 brave->attack(board,step);
    }
    bool Board::has_soldiers(uint player_number) const
    {
        for(int i= 0; i< board.size(); ++i)
        {
            for(int j=0; j< board[i].size(); ++j)
            {
                pair<int, int> place=make_pair(i,j);
                Soldier* brave=(*this)[place];
                if(brave!=nullptr&&brave->getPlayerNumber()==player_number)
                {
                    return true;
                }
            }
        }
        			
        return false;
    }
}