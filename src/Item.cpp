#include "Item.h"
#include <cstdlib>
#include <ctime>

Item::Item() {
    std::srand(std::time(nullptr)); // 랜덤 시드 설정
}

void Item::generateItems(SnakeMap& snakeMap) {
    int numItems = std::rand() % 2 + 2; // 2~3개의 아이템을 생성
    for (int i = 0; i < numItems; ++i) {
        auto position = getRandomEmptyPosition(snakeMap);
        if (position.first != -1 && position.second != -1) {
            ItemType itemType = getRandomItemType();
            items.push_back(position);
            itemTimers.push_back(20); // 아이템의 생명 시간 5초 (20틱) 설정
            itemTypes.push_back(itemType);
            snakeMap.setMap(position.first, position.second, itemType); // 아이템을 맵에 표시
        }
    }
}

void Item::updateItems(SnakeMap& snakeMap) {
    for (size_t i = 0; i < itemTimers.size(); ++i) {
        --itemTimers[i];
        if (itemTimers[i] <= 0) {
            removeItem(i, snakeMap);
            --i; // 삭제 후 인덱스 조정
        }
    }
}

void Item::removeItem(int index, SnakeMap& snakeMap) {
    auto position = items[index];
    snakeMap.setMap(position.first, position.second, 0); // 맵에서 아이템 제거
    items.erase(items.begin() + index);
    itemTimers.erase(itemTimers.begin() + index);
    itemTypes.erase(itemTypes.begin() + index);
}

std::pair<int, int> Item::getRandomEmptyPosition(SnakeMap& snakeMap) {
    int size = snakeMap.getSize() - 1;
    int x, y;

    for (int attempts = 0; attempts < 100; ++attempts) { // 최대 100번 시도
        x = std::rand() % size;
        y = std::rand() % size;
        if (snakeMap.getMap()[y][x] == 0) {
            return {y, x};
        }
    }
    return {-1, -1}; // 빈 위치를 찾지 못함
}

ItemType Item::getRandomItemType() {
    return (std::rand() % 2 == 0) ? GROWTH : POISON; // 랜덤으로 GROWTH 또는 POISON 반환
}