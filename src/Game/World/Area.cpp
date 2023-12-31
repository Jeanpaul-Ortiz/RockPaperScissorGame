#include "Area.h"

Area::Area(string name, Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy *> enemies, vector<Immovable *> trees, vector<Friend *> friends, Boss *boss) {
    this->name = name;
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->trees = trees;
    this->friends = friends;
    this->boss = boss;
}


void Area::resetEnemies() {
    for (unsigned int i = 0; i < enemies.size(); i++)
        enemies.at(i)->revive();
}

void Area :: spawnBoss(){
      for (unsigned int i = 0; i < enemies.size(); i++)
        enemies.at(i)->kill();
}

int Area::getRemainingEnemies() {
    int count = 0;
    for (unsigned int i = 0; i < enemies.size(); i++)
        if (!enemies.at(i)->isDead())
            count++;

    return count;
}

void Area::resetBoss(){
    boss->revive();
}



