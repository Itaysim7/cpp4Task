#include <iostream>
#include "FootSoldier.hpp"
#include "Board.hpp"
#include <limits>

void FootSoldier::attack(vector<vector<Soldier*>> &b, pair<int,int> place)
{
    int row=b.size();
    int col=b[0].size();
    pair<pair<int,int>,Soldier*> ans=make_pair(make_pair(0,0),nullptr);
    double dis=std::numeric_limits<int>::max();
    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
             if(b[i][j]!=nullptr&&b[i][j]->getPlayerNumber()!=this->playerNumber)
             {
                 double temp=distance(place.first,place.second,i,j);
                 if(temp<=dis)
                 {
                     dis=temp;
                     ans.first.first=i; ans.first.second=j;
                     ans.second=b[i][j];
                 }
             }
        }
    }

    ans.second->setHealth(ans.second->getHealth()+damage);
    if(ans.second->getHealth()<=0)
        b[ans.first.first][ans.first.second]=nullptr;
}
