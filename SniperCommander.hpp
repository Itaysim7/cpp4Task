#pragma once
#include "Soldier.hpp"
using namespace std;
class SniperCommander : public Soldier 
{
    public:
    SniperCommander(uint num) : Soldier(num,120,-100) { }
    void attack (vector<vector<Soldier*>>&,pair<int,int>) override;
};