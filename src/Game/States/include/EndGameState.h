#pragma once

#include "Enemy.h"
#include "Player.h"
#include "State.h"

class EndGameState : public State {
   private:
    Player *player;
    Enemy *enemy;
    ofImage loseScreen;
    ofImage winScreen;
    ofImage winGameScreen;
    bool win;
    bool winGame = false;

   public:
    EndGameState();
    bool getWin() { return win; };
    bool getWinGame() {return winGame;}
    void setWin(bool winning) { this->win = winning; };
    void setWinGame(bool winGame) {this->winGame = winGame;}
    void update();
    void draw();
    void keyPressed(int key);
    void reset();
};