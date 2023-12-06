#pragma once

#include "ofMain.h"
enum Direction {left, right, up, down};

class Object{
    protected:
    int ox;
    int oy;
    int oh;
    int ow;
    ofImage overworldSprite;

    public:
    Object(int ox, int oy, int ow, int oh);
    virtual void inOverworldDraw();
    int getOX() { return ox; };
    int getOY() { return oy; };
    int getOW() { return ow; };
    int getOH() { return oh; };
    void setOX(int ox) { this->ox = ox; };
    void setOY(int oy) { this->oy = oy; };
    bool collides(Object* object);
    ofRectangle getBounds();
    ofRectangle getBounds(int ox, int oy);
};