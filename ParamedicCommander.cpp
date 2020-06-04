#include "Paramedic.hpp"
#include "Board.hpp"
#include "ParamedicCommander.hpp"
void ParamedicCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> place)
{
    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
            if(b[i][j]!=nullptr&&b[i][j]->getPlayerNumber()==playerNumber)
            {
                Paramedic *pc=dynamic_cast<Paramedic*>(b[i][j]); //if from my team and footSoldier
                if(pc)
                    pc->attack(b,{i,j});
            }
        }
    }
    int row=place.first;
    int col=place.second;
    if(row+1<b.size())//Up
    {
        Soldier* up=b[row+1][col];
        if(up!=nullptr&&up->getPlayerNumber()==playerNumber) 
            up->setHealth(up->getHealth()+damage);
    }
    
    if(row-1>0) //Down
    {
        Soldier* down=b[row-1][col];
        if(down!=nullptr&&down->getPlayerNumber()==playerNumber) 
            down->setHealth(down->getHealth()+damage);
    }
    
    if(col+1<b[0].size()) //Right
    {
        Soldier* right=b[row][col+1];
        if(right!=nullptr&&right->getPlayerNumber()==playerNumber) 
            right->setHealth(right->getHealth()+damage);
    }
    
    if(col-1>0) //Left
    {
        Soldier* left=b[row][col-1];
        if(left!=nullptr&&left->getPlayerNumber()==playerNumber) 
            left->setHealth(left->getHealth()+damage);        
    }
}
