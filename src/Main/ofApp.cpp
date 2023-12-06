#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    ofSetFrameRate(30);
    ofSetWindowTitle("Spooky Quest");
    initAreas();
    // Declaration and Initialization of States
    player = new Player(100, 6);
    titleState = new TitleState();
    overworldState = new OverworldState(player, currentArea);
    battleState = new BattleState(player, currentArea);
    winState = new WinState();
    endGameState = new EndGameState();

    // Initial State
    currentState = titleState;
}

//--------------------------------------------------------------
void ofApp::initAreas() {
    /**
     * @brief
     * each area is 672 pixels wide and 640 pixels high,
     * with 10 and 8 pixels of space between the player and the edge of the map respectively
     * each in-game pixel is 4 * 1 screen pixel
     */

    vector<Enemy *> enemies3;
    vector <Immovable *> trees3;
    vector <Friend *> friends3;
    ofPoint entrancePosition3(4 * 110, 4 * 116);
    Enemy *area3Enemy1 = new Enemy("31", 30, 6, "enemy3", 4 * 120, 4 * 342);
    Enemy *area3Enemy2 = new Enemy("32", 30, 6, "enemy3", 4 * 254, 4 * 130);
    Enemy *area3Enemy3 = new Enemy("33", 30, 6, "enemy3", 4 * 542, 4 * 124);
    Enemy *area3Enemy4 = new Enemy("34", 30, 6, "enemy3", 4 * 532, 4 * 368);
    Enemy *area3Enemy5 = new Enemy("35", 30, 6, "enemy3", 4 * 266, 4 * 312);
    Enemy *area3Enemy6 = new Enemy("36", 30, 6, "enemy3", 4 * 194, 4 * 532);
    Immovable *area3Tree1 = new Immovable(4 * 266, 4 * 124);
    Immovable *area3Tree2 = new Immovable(4 * 300, 4 * 400);
    Friend *area3Friend1 = new Friend( 4 * 110, 4 * 116, "Well Done, traveller. \nYou made it out of Inferno...");
    Boss *area3Boss1 = new Boss("31", "boss3", 3);
    enemies3.push_back(area3Enemy1);
    enemies3.push_back(area3Enemy2);
    enemies3.push_back(area3Enemy3);
    enemies3.push_back(area3Enemy4);
    enemies3.push_back(area3Enemy5);
    enemies3.push_back(area3Enemy6);
    trees3.push_back(area3Tree1);
    trees3.push_back(area3Tree2);
    friends3.push_back(area3Friend1);
    area3 = new Area("Creepy Caves", NULL, "images/areas/area3.png", "audio/ice.wav", "images/stages/stage3.png", entrancePosition3, enemies3, trees3, friends3, area3Boss1);

    //New Area
    vector<Enemy *> enemies2;
    vector<Immovable *> trees2;
    vector<Friend *> friends2;
    ofPoint entrancePosition2(4 * 414, 4 * 566);
    Enemy *area2Enemy1 = new Enemy("21", 30, 6, "enemy2", 4 * 342, 4 * 224);
    Enemy *area2Enemy2 = new Enemy("22", 30, 6, "enemy2", 4 * 222, 4 * 164);
    Enemy *area2Enemy3 = new Enemy("23", 30, 6, "enemy2", 4 * 100, 4 * 322);
    Enemy *area2Enemy4 = new Enemy("24", 30, 6, "enemy2", 4 * 399, 4 * 199);
    Enemy *area2Enemy5 = new Enemy("25", 30, 6, "enemy 2", 4 * 250, 4 *150);
    Immovable *area2Tree1 = new Immovable(4 * 450, 4 * 199);
    Friend *area2Friend1 = new Friend( 4 * 404, 4 * 566, "Wow, you must be very strong \nBut not many get out of here \n IN ONE PIECE...");
    Boss *area2Boss1 = new Boss("21", "boss2", 2);
    enemies2.push_back(area2Enemy1);
    enemies2.push_back(area2Enemy2);
    enemies2.push_back(area2Enemy3);
    enemies2.push_back(area2Enemy4);
    enemies2.push_back(area2Enemy5);
    trees2.push_back(area2Tree1);
    friends2.push_back(area2Friend1);
    area2 = new Area("Impervious Inferno", area3, "images/areas/area2.png", "audio/fire.wav", "images/stages/stage2.jpeg", entrancePosition2, enemies2, trees2, friends2, area2Boss1);


    vector<Enemy *> enemies1;
    vector<Immovable *> trees1;
    vector<Friend *> friends1;
    vector <Boss *> boss1;
    ofPoint entrancePosition1(4 * 414, 4 * 566);
    Enemy *area1Enemy1 = new Enemy("11", 20, 4, "enemy1", 4 * 440, 4 * 432);
    Enemy *area1Enemy2 = new Enemy("12", 20, 4, "enemy1", 4 * 225, 4 * 178);
    Enemy *area1Enemy3 = new Enemy("13", 20, 4, "enemy1", 4 * 420, 4 * 178);
    Immovable *area1Tree1 = new Immovable(4 * 460, 4 * 178);
    Friend *area1Friend1 = new Friend( 4 * 450, 4 * 480, "Who.. Who are you? \nHow did you get here?...");
    Friend *area1Friend2 = new Friend( 4 * 300, 4 * 178, "Many dangers await you, but die not...\nThe reward, very valuable, it is");
    Boss *area1Boss1 = new Boss("11", "boss1", 1);
    enemies1.push_back(area1Enemy1);
    enemies1.push_back(area1Enemy2);
    enemies1.push_back(area1Enemy3);
    trees1.push_back(area1Tree1);
    friends1.push_back(area1Friend1);
    friends1.push_back(area1Friend2);
    boss1.push_back(area1Boss1);
    area1 = new Area("Pleasant Plains", area2, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, trees1, friends1, area1Boss1);
    currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update() {
    currentState->update();
    if (currentState->hasFinished()) {
        currentState->toggleMusic();
        if (currentState->getNextState() == "Title") {
            endGameState->setWin(false);
            area1->resetEnemies();
            area1->resetBoss();
            area2->resetEnemies();
            area2->resetBoss();
            area3->resetEnemies();
            area3->resetBoss();
            currentArea = area1;
            battleState->reset();
            battleState->setStage(currentArea->getStage());
            overworldState->loadArea(currentArea);
            currentState = titleState;
            player->reset();
        } else if (currentState->getNextState() == "Overworld") {

            currentState = overworldState;
           
        } else if (currentState->getNextState() == "Battle") {
            battleState->startBattle(overworldState->getEnemy());
            currentState = battleState;
        } else if (currentState->getNextState() == "Win"){
            if(currentArea->getRemainingEnemies() != 0){
                overworldState->getEnemy()->kill();}
            else{currentArea->getBoss()-> kill();}
            if(currentArea->getBoss()->getLives() > 0 && currentArea->getBoss()->isDead()){
                player->setHealth(player->getHealth() + 15);
                currentArea->getBoss()->revive();
                currentArea->getBoss()->setLives(currentArea->getBoss()->getLives() - 1);
                }
            if(currentArea->getBoss()->isDead() && currentArea->getBoss()->getLives() == 0){
                    if (currentArea->getNextArea() == NULL) {
                        endGameState->setWinGame(true);
                        currentState = endGameState;
                    } else {
                    player->setDmg(player->getDmg() + 5);
                    player->setHealth(player->getHealth() + 5);
                    currentArea = currentArea->getNextArea();
                    overworldState->loadArea(currentArea);
                    battleState->setStage(currentArea->getStage());
                    currentState = winState;
                }
            }
              else {
                currentState = winState;
            }
        } else if (currentState->getNextState() == "End") //DO NOT PUT BRACKETS

            currentState = endGameState;
            currentState->toggleMusic();
            currentState->reset();

    
}
 
}
//--------------------------------------------------------------
void ofApp::draw() {
    currentState->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    currentState->keyPressed(key);
    //Hotkeys-r
    if(key == 'r'){
        currentArea->resetEnemies();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
    currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
    currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
    currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
    currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
    currentState->dragEvent(dragInfo);
}