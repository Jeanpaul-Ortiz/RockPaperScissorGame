#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area) {
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    pauseScreen.load("images/ui/PausedGame.jpeg");
    hot.load("audio/hot.wav");
}

void OverworldState::loadArea(Area *area) {
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}
void OverworldState::update() {
    //Pause spec
    if(pause){
        return;
    } 
    else{
    player->inOverworldUpdate();

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead()) {
            area->getEnemies().at(i)->inOverworldUpdate();
            if (player->collides(area->getEnemies().at(i))) {
                setEnemy(area->getEnemies().at(i));
                setNextState("Battle");
                setFinished(true);
                break;
            }
        }

        //Update Boss
        if(area->getRemainingEnemies() == 0){
            if(player->collides(area->getBoss())) {
                setEnemy(area->getBoss());
                setNextState("Battle");
                setFinished(true);
                break;
            }
            }
        
     }
        //Checking for player collisions with immovable objects
        for(unsigned int i = 0; i < area->getTrees().size(); i++){
            if(player->collides(area->getTrees().at(i))){
               if(player->getOX() < area->getTrees().at(i)->getOX()){
                    player->setOX(player->getOX() - 5);
               }
                if(player->getOX() > area->getTrees().at(i)->getOX()){
                    player->setOX(player->getOX() + 5);
                    
                }
                if(player->getOY() > area->getTrees().at(i)->getOY()){
                    player->setOY(player->getOY() + 5);
                }
                if(player->getOY() < area->getTrees().at(i)->getOY()){
                    player->setOY(player->getOY() - 5);
                }
        }
}
    

    camera->update();
    timer++;
    if(area->getName() == "Impervious Inferno"){
        if(timer % 150 == 0){
            if(player->getHealth() < 5){
                setNextState("End"); 
                setFinished(true);
            }
            else{player->setHealth(player->getHealth() - 3);}
        }
    }
}
}



void OverworldState::draw() {
    //Draws pause screen
    if(pause){
        pauseScreen.draw(0,0,ofGetWidth(),ofGetHeight());
    }
    else{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->inOverworldDraw();

    //HUD-area and enemies remaning

    ofDrawBitmapStringHighlight("Current Area: " + area->getName(), 0 , 32, ofColor::white, ofColor::black);
    ofDrawBitmapStringHighlight("Enemies Remaining: " + to_string(area->getRemainingEnemies()), 0, 12);

    //Drawing enemies

    for (unsigned int i = 0; i < area->getEnemies().size(); i++) {
        if (!area->getEnemies().at(i)->isDead()) {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->inOverworldDraw();
        }
    }

    // //Drawing Boss 
        if (area->getRemainingEnemies() == 0){
            int playerDistanceX = area->getBoss()->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getBoss()->getOY() - camera->getPlayerY();
            area->getBoss()->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getBoss()->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getBoss()->inOverworldDraw();
            
        }
    
    
    //Drawing immovable objects
    

    for(unsigned int i = 0; i < area->getTrees().size(); i++){
        int playerDistanceX = area->getTrees().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getTrees().at(i)->getOY() - camera->getPlayerY();
        area->getTrees().at(i)->setRENDER_X(camera->getDimensionX() / 2 + playerDistanceX);
        area->getTrees().at(i)->setRENDER_Y(camera->getDimensionY() / 2 + playerDistanceY);
        if(area->getName() == "Pleasant Plains"){
            area->getTrees().at(i)->inArea1Draw();
        }
        else if(area->getName() == "Impervious Inferno"){
            area->getTrees().at(i)->inArea2Draw();
        }
        else{area->getTrees().at(i)->inArea3Draw();}
    }

    //Drawing Friends and Message


    for(unsigned int i = 0; i < area->getFriend().size(); i++){
        int playerDistanceX = area->getFriend().at(i)->getOX() - camera->getPlayerX();
        int playerDistanceY = area->getFriend().at(i)->getOY() - camera->getPlayerY();
        area->getFriend().at(i)->setRENDER_X(camera->getDimensionX() / 2 + playerDistanceX);
        area->getFriend().at(i)->setRENDER_Y(camera->getDimensionY() / 2 + playerDistanceY);
        area->getFriend().at(i)->inOverworldDraw();
        if(player->collides(area->getFriend().at(i))){
            if(friendInteract){
                area->getFriend().at(i)->Pop_up();
    }
        }
    area->getFriend().at(i)->inOverworldUpdate();
}
    //HUD-HealthBar
    ofImage healthbar; 
    healthbar.load("images/ui/healthbar.png");
    healthbar.draw(480, 380, 150, 150);
    if(player->getHealth() > 70){
        ofSetColor(0,255,0);
        ofDrawRectangle(515, 447, player->getHealth() + 12, 12);
        ofSetColor(255,255,255);
    }
    else if(player->getHealth() > 30){
        ofSetColor(204,204,0);
        ofDrawRectangle(515, 447, player->getHealth() + 12, 12);
        ofSetColor(255,255,255);
    }
    else if(player->getHealth()){
        ofSetColor(255,0,0);
        ofDrawRectangle(515, 447, player->getHealth() + 12, 12);
        ofSetColor(255,255,255);
    }

    
}
}

void OverworldState::keyPressed(int key) {
    player->keyPressed(key);
    if(key == OF_KEY_ESC){
        pause = !pause;
        toggleMusic();
    }

    //Friend Message 

    if(friendInteract){
        friendInteract = false;
    }

    if(key == 'e'){
        friendInteract = true;
}
    if(key == 'b'){
        area->spawnBoss();
    }
}
void OverworldState::keyReleased(int key) {
    player->keyReleased(key);
}

void OverworldState::reset() {
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}