#include <iostream>
#include "Board.hpp"
#include "Sniper.hpp"
void Sniper::attack(vector<vector<Soldier*>> &b, pair<int,int> location){
    int row = b.size();
    int col = b[0].size();
    pair<int, int> toAttack_index = make_pair(-1,-1);
    pair<double, Soldier*> toAttack =make_pair(0, nullptr);
    for(int i= 0; i<row; ++i){
        for(int j= 0; j<col; ++j){
            Soldier* s = b[i][j];
	        if(s != nullptr && s->getPlayerNumber() != playerNumber){
                double d = s->getHealth();//distance(location.first, location.second, i, j);
                if (d > toAttack.first) {
                    toAttack.first = d;
                    toAttack.second = s;
                    toAttack_index.first = i;
                    toAttack_index.second = j;
			    }
            }
        }
    }
    if( toAttack.second != nullptr) {
                int new_health = toAttack.second->getHealth() + damage;
                if(new_health <= 0) {
                    printf("Sniper killed: %p\n", toAttack.second);
                    b[toAttack_index.first][toAttack_index.second]=nullptr;
                    // delete toAttack.second;
                    
                }
                else {
                    printf("Sniper attacking [%d,%d], new heath: %d\n", toAttack_index.first, toAttack_index.second, new_health);
                    b[toAttack_index.first][toAttack_index.second]->setHealth(new_health);
                }
    }
    else {
            printf("There is no one to attack!\n");
    }
}        
