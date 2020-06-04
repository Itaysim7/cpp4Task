#pragma once
#include "Soldier.hpp"
using namespace std;
class Paramedic : public Soldier 
{
    public:
    Paramedic(uint num) : Soldier(num,100,300) { }
    void attack (vector<vector<Soldier*>>&,pair<int,int>) override;
};