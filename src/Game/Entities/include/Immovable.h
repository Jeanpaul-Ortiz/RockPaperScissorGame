#pragma once

#include "Object.h"
#include "Player.h"

class Immovable : public Object{
    protected:
    ofImage sprite1;
    ofImage sprite2;
    ofImage sprite3;
    Player *player;
    int RENDER_X = 1000;
    int RENDER_Y = 1000;


    public:
    Immovable(int ox, int oy);
    Player *getPlayer() {return player; };
    int getOX() { return ox; };
    int getOY() { return oy; }; 
    void inArea1Draw();
    void inArea2Draw();
    void inArea3Draw();
    void inOverworldUpdate();
    void setRENDER_X(int x) { RENDER_X = x; };
    void setRENDER_Y(int y) { RENDER_Y = y; };
};