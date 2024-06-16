#ifndef SNAKEMAP_H
#define SNAKEMAP_H

#include <ncurses.h>

class SnakeMap {
public:
    SnakeMap(int size);
    ~SnakeMap();
    void loadMap(int mapData[25][25]);
    void drawMap(int start_x, int start_y);
    int** getMap() const;
    void setMap(int x, int y, int value);

private:
    int size;
    int **map;
    WINDOW *mapWin; // 맵을 표시할 윈도우
};

#endif // SNAKEMAP_H
