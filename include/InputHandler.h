#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

class InputHandler {
public:
    InputHandler();
    ~InputHandler();
    int getInput();
    void updateDirection();

private:
    int direction;
};

#endif // INPUTHANDLER_H