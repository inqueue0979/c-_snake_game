#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <ncurses.h>

class ScoreBoard {
public:
    ScoreBoard(WINDOW* externalWin, int width, int height, int start_x, int start_y);
    
    void updateScore(int newScore);
    void display();

    // 초기화 함수
    void reset();

    // 점수 관련 게터와 세터
    int getScore() const;
    void setScore(int newScore);
    void addScore(int increment);

    // 뱀 길이 관련 게터와 세터
    int getBodyCurrentLength() const;
    void setBodyCurrentLength(int length);
    void addBodyCurrentLength(int increment);
    int getBodyLongestLength() const;
    void setBodyLongestLength(int length);
    void addBodyLongestLength(int increment);

    // 아이템 관련 게터와 세터
    int getGrowthEaten() const;
    void setGrowthEaten(int count);
    void addGrowthEaten(int increment);
    int getPoisonEaten() const;
    void setPoisonEaten(int count);
    void addPoisonEaten(int increment);
    int getGateEaten() const;
    void setGateEaten(int count);
    void addGateEaten(int increment);

    // 게임 시간 관련 게터와 세터
    int getGameTimer() const;
    void setGameTimer(int time);
    void addGameTimer(int increment);

private:
    WINDOW* scoreWin;
    int score;
    int bodyCurrentLength;
    int bodyLongestLength;
    int growthEaten;
    int poisonEaten;
    int gateEaten;
    int gameTimer;
};

#endif // SCOREBOARD_H