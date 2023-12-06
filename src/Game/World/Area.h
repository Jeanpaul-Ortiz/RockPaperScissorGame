#pragma once

#include "OverworldCamera.h"
#include "Player.h"
#include "Immovable.h"
#include "Friend.h"
#include "Boss.h"


class Area {
   protected:
    string name;
    ofImage areaImage;
    ofSoundPlayer areaMusic;
    ofImage areaStage;
    ofPoint entrancePosition;
    Boss *boss;
    std::vector<Enemy *> enemies;
    std::vector<Immovable *> trees;
    std :: vector<Friend *> friends;

    Area *nextArea;

   public:
    Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<Immovable *> trees, vector<Friend *> friends, Boss *boss);
    void resetEnemies();
    string getName() { return name; }
    ofImage getImage() { return areaImage; }
    ofSoundPlayer getMusic() { return areaMusic; }
    ofImage getStage() { return areaStage; }
    ofPoint getEntrancePos() { return entrancePosition; }
    int getRemainingEnemies();
    Area *getNextArea() { return nextArea; }
    void setName(string name) { this->name = name; }
    void setEnemies(std::vector<Enemy *> enemies) { this->enemies = enemies; }
   
    //Immovable objects

    void setTrees(std::vector<Immovable *> trees) {this->trees = trees; }
    vector<Immovable *> getTrees() {return trees;} ;
    vector<Enemy *> getEnemies() { return enemies; }
    vector<Friend *> getFriend() {return friends; }


    //Boss 
    void spawnBoss();    
    Boss *getBoss() {return boss; }
    void setBoss(Boss *boss) {this->boss = boss;}
    void resetBoss();
};