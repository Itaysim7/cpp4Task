#include <iostream>
#include "Sniper.hpp"
#include "FootSoldier.hpp"
#include "Board.hpp"
#include "SniperCommander.hpp"
void SniperCommander::attack(vector<vector<Soldier*>> &b, pair<int,int> place)
{
    int row=b.size();
    int col=b[0].size();
    pair<pair<int,int>,Soldier*> ans=make_pair(make_pair(0,0),nullptr); //how the commander attack
    int strongestEnemy=0;
    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
             Soldier* tempSol=b[i][j];
             if(tempSol!=nullptr)
             {
                 if(tempSol->getPlayerNumber()!=this->playerNumber) //if ememy
                 {
                     if(b[i][j]->getHealth()>strongestEnemy)
                     {
                        strongestEnemy=b[i][j]->getHealth();
                        ans.first.first=i;ans.first.second=j;
                        ans.second=tempSol;
                     }
                 }
             }
        }
    }
    cout<<"i am sniper commander attackin"<<ans.first.first<<","<<ans.first.second<<endl;
    ans.second->setHealth(ans.second->getHealth()+damage);
    if(ans.second->getHealth()<=0)
    {
                    cout<<"sniper dead"<<ans.first.first<<","<<ans.first.second<<endl;

        b[ans.first.first][ans.first.second]=nullptr;
    }
    for(int i= 0; i< b.size(); ++i)
    {
        for(int j=0; j< b[i].size(); ++j)
        {
             Soldier* tempSol=b[i][j];
             if(tempSol!=nullptr&&tempSol->getPlayerNumber()==this->playerNumber)
             {
                 Sniper *fs=dynamic_cast<Sniper*>(tempSol); //if from my team and footSoldier
                 if(fs)
                     fs->attack(b,{i,j});
             }
        }
    }    
}
