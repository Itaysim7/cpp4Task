#pragma once
#include "Soldier.hpp"
using namespace std;
class FootCommander : public Soldier 
{
    public:
    FootCommander (uint num) : Soldier(num,150,-20) { }
    void attack (vector<vector<Soldier*>>&,pair<int,int>) override;
};