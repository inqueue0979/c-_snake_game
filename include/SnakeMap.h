#ifndef SNAKEMAP_H
#define SNAKEMAP_H

class SnakeMap {
public:
    SnakeMap(int size);
    ~SnakeMap();

    void loadMap(int level[21][21]);
    void drawMap();
    bool isCollision(int x, int y);

private:
    int size;
    int **map;
};

#endif // SNAKEMAP_H
