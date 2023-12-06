#pragma once

#include "Area.h"
#include "OverworldCamera.h"
#include "Player.h"
#include "State.h"
#include "Immovable.h"
#include "Boss.h"

class OverworldState : public State {
   private:
    ofImage overworldImage;
    Player *player;
    OverworldCamera *camera;
    Area *area;
    std::vector<Enemy *> enemies;
    Enemy *enemy;

    //Implemented Variables
    Immovable *immovable;
    Boss *boss;
    Friend *friends;
    std::vector<Immovable *> trees;
    ofImage pauseScreen;
    ofSoundPlayer hot;


   public:
    OverworldState(Player *player, Area *area);
    Player *getPlayer() { return player; };
    void setEnemy(Enemy *enemy) { this->enemy = enemy; };
    Enemy *getEnemy() { return enemy; };
    void loadArea(Area *Area);
    Area *getArea() { return area; };
    //Immovable entity
    Immovable *getImmovable() {return immovable; };
    Friend * getFriend() {return friends; };
    void setImmovable(Immovable *immovable) {this->immovable = immovable; };
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void reset();
    int timer = 0;
    void setBoss(Boss *boss){this->boss = area->getBoss();};
    //vector<Enemy*> getAllEnemies();
    bool friendInteract = false;
};