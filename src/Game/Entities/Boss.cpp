#include "Boss.h"


Boss :: Boss(string id, string entityName, int lives) : Enemy( id, health, baseDamage, entityName, 4 * 250, 4 * 250){
    this->ow = 275;
    this->oh = 300;
    this->health = 40;
    this->baseDamage = 5;
    this->fx = 350;
    this->fy = 160;
    this->fh = 180;
    this->fw = 250;
    this->lives = lives;
    overworldBoss.load("images/entities/enemy/boss.png");
    fightingBoss.load("images/entities/enemy/bossFight.png");

    vector <ofImage> downFrames;
    vector<ofImage> upFrames;
    
    downFrames.push_back(overworldBoss);
    upFrames.push_back(fightingBoss);

    walkDown = new Animation(3, downFrames);
    fighting = new Animation(10, upFrames);
    direction = Direction::down;

}

void Boss::inOverworldUpdate() {
    overworldBoss = walkDown->getCurrentFrame();
    walkDown->update();

}

void Boss::fightingUpdate(){
    fightingBoss = fighting->getCurrentFrame();
    fighting->update();
}

void Boss::fightingDraw(){
    fightingBoss.draw(fx, fy, fw, fh);
}

void Boss::revive(){
    this->dead = false;
}

void Boss::kill(){
    this->dead = true;
}

void Boss :: inOverworldDraw(){
    overworldBoss.draw(renderX, renderY, ow, oh);
}


