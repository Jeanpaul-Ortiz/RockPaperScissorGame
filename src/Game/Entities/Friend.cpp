#include "Friend.h"

Friend::Friend(int ox, int oy, string message) : Object(ox, oy, 175, 150){
//  
    this->message = message;
    moveTimer = 120;
    vector<ofImage> downFrames;
    vector<ofImage> upFrames;
    vector<ofImage> leftFrames;
    vector<ofImage> rightFrames;

    spriteRight.load("images/entities/Friends/FriendRight.png");
    spriteLeft.load("images/entities/Friends/FriendLeft.png");
    spriteDown.load("images/entities/Friends/FriendDown.png");
    spriteUp.load("images/entities/Friends/FriendUp.png");

    downFrames.push_back(spriteDown);

    leftFrames.push_back(spriteLeft);
  
    rightFrames.push_back(spriteRight);

    upFrames.push_back(spriteUp);

    
    walkDown = new Animation(3, downFrames);
    walkUp = new Animation(3, upFrames);
    walkLeft = new Animation(3, leftFrames);
    walkRight = new Animation(3, rightFrames);

    direction = Direction::down;
}

void Friend::inOverworldUpdate() {
    if (moveTimer == 120) {
        walking = true;
        switch (direction) {
            case Direction::left:
                direction = Direction::up;
                break;
            case Direction::right:
                direction = Direction::down;
                break;
            case Direction::up:
                direction = Direction::right;
                break;
            case Direction::down:
                direction = Direction::left;
                break;
        }
    }
    if (moveTimer == 100) {
        walking = false;
    }
    moveTimer--;
    if (moveTimer == 0) moveTimer = 120;

    if (walking) {
        switch (direction) {
            case Direction::left:
                this->ox -= speed;
                walkLeft->update();
                overworldSprite = walkLeft->getCurrentFrame();
                break;
            case Direction::right:
                this->ox += speed;
                walkRight->update();
                overworldSprite = walkRight->getCurrentFrame();
                break;
            case Direction::up:
                this->oy -= speed;
                walkUp->update();
                overworldSprite = walkUp->getCurrentFrame();
                break;
            case Direction::down:
                this->oy += speed;
                walkDown->update();
                overworldSprite = walkDown->getCurrentFrame();
                break;
        }
    } else {
        switch (direction) {
            case Direction::left:
                overworldSprite = walkLeft->getCurrentFrame();
                break;
            case Direction::right:
                overworldSprite = walkRight->getCurrentFrame();;
                break;
            case Direction::up:
                overworldSprite = walkUp->getCurrentFrame();
                break;
            case Direction::down:
                overworldSprite = walkDown->getCurrentFrame();
                break;
        }
    }
    
}


void Friend :: inOverworldDraw(){
    overworldSprite.draw(RENDER_X,RENDER_Y,ow,oh);
}
        

void Friend :: Pop_up(){

    ofDrawBitmapStringHighlight(getMessage(), RENDER_X, RENDER_Y, ofColor::blueSteel);

}
