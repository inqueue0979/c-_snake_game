#ifndef SNAKEPOSITION_H
#define SNAKEPOSITION_H

class Snakeposition {
private:
    int posX;
    int posY;

public:
    Snakeposition(int x, int y);
    int getPosX() const;
    int getPosY() const;
    void setPosX(int x);
    void setPosY(int y);
};

#endif // SNAKEPOSITION_H
