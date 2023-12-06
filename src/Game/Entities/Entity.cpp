#include "Entity.h"

Entity::Entity(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage) : Object(ox, oy, ow, oh) {
    this->fx = fx;
    this->fy = fy;
    this->fh = fh;
    this->fw = fw;
    this->health = health;
    this->baseDamage = baseDamage;
}

Entity::~Entity(){}

void Entity::inOverworldDraw() {
    overworldSprite.draw(ox, oy, ow, oh);
}

void Entity::fightingDraw() {
    fightingSprite.draw(fx, fy, fw, fh);
}




