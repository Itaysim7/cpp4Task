#pragma once
#include "Soldier.hpp"
using namespace std;
class ParamedicCommander : public Soldier 
{
    public:
    ParamedicCommander(uint num) : Soldier(num,200,100) { }
    void attack (vector<vector<Soldier*>>&,pair<int,int>) override;
};