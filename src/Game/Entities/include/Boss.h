#pragma once
#include "Enemy.h"



class Boss : public Enemy {
    private:
    string entityName;
    string id;
    int lives;
    bool walking = true;
    ofImage fightingBoss;
    ofImage overworldBoss;
    Enemy* enemy;
    Animation *fighting;
    Animation *walkUp;
    Animation *walkDown;
    bool dead = false;


    public:
    Boss(string id, string entityName, int lives);
    int getOX() { return ox; };
    int getOY() { return oy; };
    bool isDead() { return dead; };
    void setRenderX(int x) { renderX = x; };
    void setRenderY(int y) { renderY = y; };
    void inOverworldUpdate();
    void fightingUpdate();
    void inOverworldDraw();
    Enemy *getEnemy() {return enemy;}
    void reset();
    int getLives() {return lives;}
    string getId() { return id; };
    ofImage getSprite() { return overworldBoss; };
    void setHealth(int health) {this->health = health;};
    void fightingDraw();
    void setLives(int lives) {this->lives = lives;};
    void kill();
    void revive();

};
