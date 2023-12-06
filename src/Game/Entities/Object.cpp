#include "Object.h"

Object::Object(int ox, int oy, int ow, int oh){
    this->ox = ox;
    this->oy = oy;
    this->ow = ow;
    this->oh = oh;
}

void Object::inOverworldDraw(){
    overworldSprite.draw(ox, oy, ow, oh);
}
ofRectangle Object::getBounds(){
    return ofRectangle(ox, oy, ow, oh);
}

ofRectangle Object::getBounds(int x, int y){
    return ofRectangle(x, y, ow, oh);
}
bool Object::collides(Object* object){
    return this->getBounds().intersects(object->getBounds());
}