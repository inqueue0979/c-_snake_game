#include "ScoreBoard.h"
#include <ncurses.h>
#include <iostream>

ScoreBoard::ScoreBoard(WINDOW* externalWin, int width, int height, int start_x, int start_y, int level) 
    : currentLevel(level) {
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
    setLevel(currentLevel); // 초기화 시 현재 레벨의 목표 설정
}

void ScoreBoard::updateScore(int newScore) {
    score = newScore;
}

void ScoreBoard::display() {
    werase(scoreWin); // 이전 내용 지우기
    box(scoreWin, 0, 0);
    mvwprintw(scoreWin, 1, (28 - 10) / 2, "SCOREBOARD");
    mvwprintw(scoreWin, 3, 3, "Score: %d", score);
    mvwprintw(scoreWin, 4, 3, "B : (%d / %d)", bodyCurrentLength, bodyLongestLength);
    mvwprintw(scoreWin, 5, 3, "Growth : %d", growthEaten);
    mvwprintw(scoreWin, 6, 3, "Poison : %d", poisonEaten);
    mvwprintw(scoreWin, 7, 3, "Gate : %d", gateEaten);
    mvwprintw(scoreWin, 8, 3, "Time : %d", gameTimer);
    mvwprintw(scoreWin, 10, 3, "----------------------");
    mvwprintw(scoreWin, 12, (28 - 5) / 2, "GOALS");
    mvwprintw(scoreWin, 14, 3, "Growth : (%d / %d)", growthEaten, growthGoal);
    mvwprintw(scoreWin, 15, 3, "Poison : (%d / %d)", poisonEaten, poisonGoal);
    mvwprintw(scoreWin, 16, 3, "Gate : (%d / %d)", gateEaten, gateGoal);
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

// 목표 조건 설정 메서드
void ScoreBoard::setGrowthGoal(int goal) { growthGoal = goal; }
void ScoreBoard::setPoisonGoal(int goal) { poisonGoal = goal; }
void ScoreBoard::setGateGoal(int goal) { gateGoal = goal; }

// 목표 조건 충족 확인 메서드
bool ScoreBoard::checkGoalsMet() const {
    return growthEaten >= growthGoal && poisonEaten >= poisonGoal && gateEaten >= gateGoal;
}

// 레벨 설정 메서드
void ScoreBoard::setLevel(int level) {
    currentLevel = level;
    switch (level) {
        case 1:
            growthGoal = 2;
            poisonGoal = 1;
            gateGoal = 1;
            break;
        case 2:
            growthGoal = 3;
            poisonGoal = 2;
            gateGoal = 1;
            break;
        case 3:
            growthGoal = 3;
            poisonGoal = 3;
            gateGoal = 1;
            break;
        case 4:
            growthGoal = 2;
            poisonGoal = 2;
            gateGoal = 1;
            break;    
        // 추가 레벨별 목표 설정
        default:
            growthGoal = 1;
            poisonGoal = 1;
            gateGoal = 1;
            break;
    }
}