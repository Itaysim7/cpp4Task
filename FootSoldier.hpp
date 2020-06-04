#pragma once
#include "Soldier.hpp"
using namespace std;
class FootSoldier : public Soldier 
{
    public:
    FootSoldier(uint num) : Soldier(num,100,-10) { }
    void attack (vector<vector<Soldier*>>&,pair<int,int>) override;
};