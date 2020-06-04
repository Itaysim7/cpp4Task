#pragma once
#include "Soldier.hpp"
using namespace std;
class Sniper : public Soldier 
{
    public:
    Sniper(uint num) : Soldier(num,100,-50){ }
    void attack (vector<vector<Soldier*>>&,pair<int,int>) override;
};