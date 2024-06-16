#ifndef ITEM_H
#define ITEM_H

#include "SnakeMap.h"
#include <utility>
#include <vector>

enum ItemType { GROWTH = 5, POISON = 6 }; // 아이템 종류를 구분하는 열거형

class Item {
public:
    Item();
    void generateItems(SnakeMap& snakeMap); // 여러 아이템을 생성하도록 이름 변경
    void updateItems(SnakeMap& snakeMap);

private:
    std::vector<std::pair<int, int>> items; // 아이템 위치
    std::vector<int> itemTimers; // 아이템 타이머
    std::vector<ItemType> itemTypes; // 아이템 종류
    void removeItem(int index, SnakeMap& snakeMap);
    std::pair<int, int> getRandomEmptyPosition(SnakeMap& snakeMap);
    ItemType getRandomItemType(); // 랜덤 아이템 타입을 반환하는 함수
};

#endif // ITEM_H