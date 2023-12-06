#pragma once
#include "Object.h"
#include "Animation.h"
#include "Player.h"

class Friend : public Object {

    protected:
    Player *player;
    string message;
    int RENDER_X = 1000;
    int RENDER_Y = 1000;
    ofImage spriteRight;
    ofImage spriteLeft;
    ofImage spriteDown;
    ofImage spriteUp;
    ofImage overworldSprite;

    public: 
    Friend(int ox, int oy, string message);
    Player *getPlayer() {return player; };
    int getOX() { return ox; };
    int getOY() { return oy; }; 
    void inOverworldDraw();
    void inOverworldUpdate();
    void setRENDER_X(int x) { RENDER_X = x; };
    void setRENDER_Y(int y) { RENDER_Y = y; };

    bool friendInteract;

    void Pop_up();
    
    int moveTimer = 0;
    int speed = 8;
    bool walking = false;
    Animation *walkUp;
    Animation *walkDown;
    Animation *walkLeft;
    Animation *walkRight;
    Direction direction;

    int messageCounter = 0;

    string getMessage() {return message; };
    int getOx() {return ox; };
    int getOy() {return oy+3; };
};

