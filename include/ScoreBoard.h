#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <ncurses.h>

class ScoreBoard {
public:
    ScoreBoard(WINDOW* externalWin, int width, int height, int start_x, int start_y, int level);
    void reset();
    void updateScore(int newScore);
    void display();

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

    // 목표 조건 설정 메서드
    void setGrowthGoal(int goal);
    void setPoisonGoal(int goal);
    void setGateGoal(int goal);

    // 목표 조건 충족 확인 메서드
    bool checkGoalsMet() const;

    // 레벨 설정 메서드
    void setLevel(int level);

private:
    WINDOW* scoreWin;
    int score;
    int bodyCurrentLength;
    int bodyLongestLength;
    int growthEaten;
    int poisonEaten;
    int gateEaten;
    int gameTimer;
    int growthGoal;
    int poisonGoal;
    int gateGoal;
    int currentLevel;
};

#endif // SCOREBOARD_H