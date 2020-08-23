#pragma once

#include "Includes.h"

#include "Food.h"
#include "SnakeBlocks.h"

class Food;
// class SnakeBlock;

class Snake
{
private:
    bool checkHeadPosition(sf::Vector2<int> &new_head_position);
    void doMovement(const sf::Vector2<int> &v);

    auto getHead();

    void updateTimeFrame(size_t step);

    bool deleteBlock();

    void eatFood(Food &f, Food &of);

public:
    sf::Vector2<int> getHeadPosition();
    Snake(WindowInfo *_w);

    bool moveSnake();

    void destroyTail();

    void drawSnake(sf::RenderWindow &w) const;

    void addBlock();

    void setDirection(Direction dir);

    void checkFoodCollision(Food &f, Food &of);

    Direction getDirection();

private:
    WindowInfo *w;
    bool is_add_block = false;
    std::deque<SnakeBlock> snake;
    Direction direction = Direction::Right;
    std::deque<sf::Vector2<int>> move_vector{{1, 0}};
    bool is_done_process = true;
};
