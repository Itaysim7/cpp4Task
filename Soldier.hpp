#pragma once
#include <math.h>
#include <vector>
using namespace std;
class Soldier
{
        
protected:
        uint playerNumber;
        int maxHealth;
        int health ;
        int damage;
        double distance(int p1x, int p1y, int p2x, int p2y)
        {
                return (abs(p1x - p2x) + abs(p1y - p2y));
        }
public:
        Soldier(uint num,int h,int d) : playerNumber(num), maxHealth(h), health(h), damage(d) { }
        virtual ~Soldier() {}
        int getPlayerNumber() { return playerNumber;}
        int getHealth() { return health;}
        void setHealth(int h)
        {
            if(h>maxHealth)
                health=maxHealth;
            else
                health=h;
        }
        int getDamage() { return damage;}
        virtual void attack (std::vector<std::vector<Soldier*>> &,pair<int,int>)=0 ;

};