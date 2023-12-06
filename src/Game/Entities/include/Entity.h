#pragma once

#include "Object.h"



class Entity : public Object{
   protected:
    int health;
    int baseDamage;
    int fx, fy, fw, fh; // Fighting coordinates and dimensions
    ofImage fightingSprite;

   public:
    Entity(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage);
  
    virtual ~Entity();
    virtual void inOverworldUpdate() = 0;
    virtual void fightingUpdate() = 0;
    virtual void fightingDraw();
    void inOverworldDraw();
    int getOX() { return ox; };
    int getOY() { return oy; };
    int getOW() { return ow; };
    int getOH() { return oh; };
    int getHealth() { return health; };
    void setHealth(int health) { this->health = health; };
    int getDmg() { return baseDamage; };
    void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
};