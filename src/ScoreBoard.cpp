#include "ScoreBoard.h"
#include <ncurses.h>
#include <iostream>

ScoreBoard::ScoreBoard(WINDOW* externalWin, int width, int height, int start_x, int start_y) {
    // ncurses 윈도우를 외부에서 전달받아 생성
    scoreWin = derwin(externalWin, height, width, start_y, start_x);
    reset();
    box(scoreWin, 0, 0);
    wrefresh(scoreWin);
}

// 초기화 함수
void ScoreBoard::reset() {
    score = 0; 
    bodyCurrentLength = 3;
    bodyLongestLength = 3;
    growthEaten = 0;
    poisonEaten = 0;
    gateEaten = 0;
    gameTimer = 0;
}

void ScoreBoard::updateScore(int newScore) {
    score = newScore;
}

void ScoreBoard::display() {
    werase(scoreWin); // 이전 내용 지우기
    box(scoreWin, 0, 0);
    mvwprintw(scoreWin, 1, (28 - 10) / 2, "SCOREBOARD");
    mvwprintw(scoreWin, 2, 1, "Score: %d", score);
    mvwprintw(scoreWin, 3, 1, "B : (%d / %d)", bodyCurrentLength, bodyLongestLength);
    mvwprintw(scoreWin, 4, 1, "Growth : %d", growthEaten);
    mvwprintw(scoreWin, 5, 1, "Poison : %d", poisonEaten);
    mvwprintw(scoreWin, 6, 1, "Gate : %d", gateEaten);
    mvwprintw(scoreWin, 7, 1, "Time : %d", gameTimer);
    wrefresh(scoreWin);
}

// 점수 관련 게터와 세터
int ScoreBoard::getScore() const { return score; }
void ScoreBoard::setScore(int newScore) { score = newScore; }
void ScoreBoard::addScore(int increment) { score += increment; }

// 뱀 길이 관련 게터와 세터
int ScoreBoard::getBodyCurrentLength() const { return bodyCurrentLength; }
void ScoreBoard::setBodyCurrentLength(int length) { bodyCurrentLength = length; }
void ScoreBoard::addBodyCurrentLength(int increment) { bodyCurrentLength += increment; }

int ScoreBoard::getBodyLongestLength() const { return bodyLongestLength; }
void ScoreBoard::setBodyLongestLength(int length) { bodyLongestLength = length; }
void ScoreBoard::addBodyLongestLength(int increment) { bodyLongestLength += increment; }

// 아이템 관련 게터와 세터
int ScoreBoard::getGrowthEaten() const { return growthEaten; }
void ScoreBoard::setGrowthEaten(int count) { growthEaten = count; }
void ScoreBoard::addGrowthEaten(int increment) { growthEaten += increment; }

int ScoreBoard::getPoisonEaten() const { return poisonEaten; }
void ScoreBoard::setPoisonEaten(int count) { poisonEaten = count; }
void ScoreBoard::addPoisonEaten(int increment) { poisonEaten += increment; }

int ScoreBoard::getGateEaten() const { return gateEaten; }
void ScoreBoard::setGateEaten(int count) { gateEaten = count; }
void ScoreBoard::addGateEaten(int increment) { gateEaten += increment; }

// 게임 시간 관련 게터와 세터
int ScoreBoard::getGameTimer() const { return gameTimer; }
void ScoreBoard::setGameTimer(int time) { gameTimer = time; }
void ScoreBoard::addGameTimer(int increment) { gameTimer += increment; }