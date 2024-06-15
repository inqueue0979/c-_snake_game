#include "item.h"

Position* Item::getItemPosition() {
    return &(this->itemPosition);
}

Item::Item(int y, int x, int type) {
    this->itemPosition = Position(y, x, type);
    this->age = 0;
}

Item::Item() {
    this->itemPosition = Position();
    this->age = 0;
}

int Item::getAge() {
    return this->age;
}

void Item::setAge(int a) {
    this->age = a;
}
