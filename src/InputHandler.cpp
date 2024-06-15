#include "InputHandler.h"
#include <ncurses.h>

InputHandler::InputHandler() {
    direction = 0;
}

InputHandler::~InputHandler() {
}

int InputHandler::getInput() {
    return direction;
}

void InputHandler::updateDirection() {
    direction = getch();
}