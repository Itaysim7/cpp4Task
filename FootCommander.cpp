#include <iostream>
#include "Board.hpp"
#include "FootCommander.hpp"
#include "FootSoldier.hpp"
#include <limits>
#include <string>

void FootCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> place) 
{
    int row=b.size();
    int col=b[0].size();
    pair<pair<int,int>,Soldier*> ans=make_pair(make_pair(0,0),nullptr); //how the commander attack
    double dis=std::numeric_limits<int>::max();
    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
             Soldier* tempSol=b[i][j];
             if(tempSol!=nullptr)
             {
                 if(tempSol->getPlayerNumber()!=this->playerNumber) //if ememy
                 {
                     double tempDis=distance(place.first,place.second,i,j);
                     if(tempDis<=dis)
                     {
                        dis=tempDis;
                        ans.first.first=i;ans.first.second=j;
                        ans.second=tempSol;
                     }
                 }
                 else
                 {
                     FootSoldier *fs=dynamic_cast<FootSoldier*>(tempSol); //if from my team and footSoldier
                     if(fs)
                         fs->attack(b,{i,j});
                 }
             }
        }
    }
    ans.second->setHealth(ans.second->getHealth()+damage);
    if(ans.second->getHealth()<=0)
        b[ans.first.first][ans.first.second]=nullptr;
}
