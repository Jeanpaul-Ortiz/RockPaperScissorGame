#include "Immovable.h"


Immovable::Immovable(int ox, int oy) : Object(ox, oy, 250, 400){
    sprite1.load("images/entities/Immovable/Area1.png");
    
    sprite2.load("images/entities/Immovable/Area2.png");
    
    sprite3.load("images/entities/Immovable/Area3.png");

}



void Immovable::inArea1Draw() {
    sprite1.draw(RENDER_X, RENDER_Y, ow, oh);
}

void Immovable::inArea2Draw(){
    sprite2.draw(RENDER_X, RENDER_Y, ow, oh);
}

void Immovable::inArea3Draw(){
    sprite3.draw(RENDER_X, RENDER_Y, ow, oh);
}



