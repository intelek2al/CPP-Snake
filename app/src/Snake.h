#pragma once

#include "Includes.h"

#include "Food.h"
#include "SnakeBlocks.h"

class Snake
{
private:
    bool checkHeadPosition(sf::Vector2<int> &new_head_position)
    {
        for (const auto &block : snake)
        {
            if (new_head_position == block.getPosition())
                return false;
        }
        if (new_head_position.x == W || new_head_position.y == H || new_head_position.x == -1 || new_head_position.y == -1)
            return false;
        return true;
    }
    void doMovement(const sf::Vector2<int> &v)
    {
        if (is_done_process)
            move_vector.pop_front();
        move_vector.push_back(v);
        is_done_process = false;
    }

    auto getHead()
    {
        auto front = snake.begin();
        return front;
    }

    void updateTimeFrame(size_t step)
    {
        // if (FRAME_TIME > )
        FRAME_TIME += step;
    }

    bool deleteBlock()
    {
    }

    void eatFood(Food &f, Food &of)
    {
        if (f.getHealthment())
        {
            addBlock();
            f.feedSnake(*this, of);
            updateTimeFrame(FRAME_TIME_STEP);
            std::cout << FRAME_TIME << std::endl;
        }
        else
        {
            deleteBlock();
            f.feedSnake(*this, of);
            updateTimeFrame(FRAME_TIME_STEP);
            std::cout << FRAME_TIME << std::endl;
        }
    }

public:
    sf::Vector2<int> getHeadPosition()
    {
        auto front = getHead();
        return front->getPosition();
    }
    Snake()
    {
        snake.push_front(SnakeBlock({0, 0}));
        snake.push_front(SnakeBlock({1, 0}));
        snake.push_front(SnakeBlock({2, 0}));
        snake.push_front(SnakeBlock({3, 0}));
        // auto front = snake.begin();
        // std::cout << front->getPosition().x << " " << front->getPosition().y << std::endl;
    }

    bool moveSnake()
    {
        if (!is_add_block)
        {
            snake.pop_back();
        }
        is_add_block = false;
        auto front = getHead();
        // std::cout << "!! " << front->getPosition().x << " " << front->getPosition().y << std::endl;
        auto &vector = move_vector.front();
        front->setColor(COLOR_BODY);
        sf::Vector2<int>
            new_head_position = {front->getPosition().x + SPEED * vector.x, front->getPosition().y + SPEED * vector.y};
        is_done_process = true;
        if (move_vector.size() > 1)
        {
            // std::cout << "removed" << std::endl;
            move_vector.pop_front();
            is_done_process = false;
        }
        if (!checkHeadPosition(new_head_position))
            return false;
        snake.push_front(SnakeBlock(new_head_position, COLOR_HEAD));
        return true;
    }

    void destroyTail()
    {
        snake.pop_back();
    }

    void drawSnake(sf::RenderWindow &w) const
    {
        for (const auto &block : snake)
            w.draw(block.getShape());
    }

    void addBlock()
    {
        is_add_block = true;
    }

    void setDirection(Direction dir)
    {
        if (std::abs(static_cast<int>(direction)) != std::abs(static_cast<int>(dir)))
            direction = dir;
        // std::cout << "added << " << GET_ENUM(direction) << std::endl;
        switch (direction)
        {
        case Direction::Up:
        {
            doMovement({0, -1});
            break;
        }
        case Direction::Right:
        {
            doMovement({1, 0});
            break;
        }
        case Direction::Left:
        {
            doMovement({-1, 0});
            break;
        }
        case Direction::Down:
        {
            doMovement({0, 1});
            break;
        }
        }
    }

    void checkFoodCollision(Food &f, Food &of)
    {
        if (f.getPosition() != getHeadPosition())
            return;
        eatFood(f, of);
    }

    auto getDirection()
    {
        return direction;
    }

private:
    bool is_add_block = false;
    std::deque<SnakeBlock> snake;
    Direction direction = Direction::Right;
    std::deque<sf::Vector2<int>> move_vector{{1, 0}};
    bool is_done_process = true;
};
