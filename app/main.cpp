#include <iostream>
#include <utility>
#include <stdlib.h>
#include <deque>
#include <chrono>
#include <random>

#include "Graphics.hpp"

#include "src/Includes.h"

#include "src/Food.h"
#include "src/Snake.h"
#include "src/SnakeBlocks.h"



// class Food
// {
// public:
//     const auto &getPosition() const
//     {
//         return position;
//     }

//     const auto &getGlobalPosition() const
//     {
//         return global_position;
//     }

// private:
//     sf::Vector2<int> generatePosition(Snake &snake, Food &food)
//     {
//         sf::Vector2<int> pos = {std::rand() % (W - 1) + 1, std::rand() % (H - 1) + 1};
//         while (snake.getHeadPosition() == pos || food.getPosition() == pos)
//         {
//             pos = {std::rand() % (W - 1) + 1, std::rand() % (H - 1) + 1};
//         }
//         return pos;
//     }

// public:
//     Food(bool _is_good = true) : is_good(_is_good)
//     {
//         shape = sf::RectangleShape({FOOD_SIZE, FOOD_SIZE});
//         position = {std::rand() % (W - 1) + 1, std::rand() % (H - 1) + 1};
//         global_position = GET_GLOBAL_POSITION(position);
//         color = is_good ? sf::Color::Green : sf::Color::Red;
//         shape.setPosition(global_position.x, global_position.y);
//         shape.setFillColor(color);
//         shape.setOutlineThickness(5.f);
//         shape.setOutlineColor(sf::Color::Magenta);
//     }

//     auto getHealthment() const
//     {
//         return is_good;
//     }

//     void drawFood(sf::RenderWindow &w) const
//     {
//         w.draw(shape);
//     }

//     void feedSnake(Snake &snake, Food &food)
//     {
//         position = generatePosition(snake, food);
//         global_position = GET_GLOBAL_POSITION(position);
//         color = is_good ? sf::Color::Green : sf::Color::Red;
//         shape.setPosition(global_position.x, global_position.y);
//     }

// private:
//     sf::RectangleShape shape;
//     sf::Color color;
//     sf::Vector2<int> position;
//     sf::Vector2<int> global_position;
//     const bool is_good;
// };

// class SnakeBlock
// {
// public:
//     SnakeBlock(const sf::Vector2i &pos)
//     {
//         shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
//         position = {pos.x, pos.y};
//         global_position = GET_GLOBAL_POSITION(position);
//         shape.setPosition(global_position.x, global_position.y);
//         shape.setOutlineThickness(5.f);
//         shape.setOutlineColor(COLOR_BORDER);
//         shape.setFillColor(COLOR_BODY);
//     }
//     SnakeBlock(const sf::Vector2i &pos, sf::Color clr)
//     {
//         shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
//         position = {pos.x, pos.y};
//         global_position = GET_GLOBAL_POSITION(position);
//         shape.setPosition(global_position.x, global_position.y);
//         shape.setOutlineThickness(5.f);
//         shape.setOutlineColor(COLOR_BORDER);
//         shape.setFillColor(clr);
//     }

//     auto &getShape() const
//     {
//         return shape;
//     }

//     const auto &getPosition() const
//     {
//         return position;
//     }

//     const auto &getGlobalPosition() const
//     {
//         return global_position;
//     }

//     void setColor(sf::Color clr)
//     {
//         shape.setFillColor(clr);
//     }

// private:
//     sf::RectangleShape shape;
//     sf::Vector2<int> position;
//     sf::Vector2<int> global_position;
// };

// class Snake
// {
// private:
//     bool checkHeadPosition(sf::Vector2<int> &new_head_position)
//     {
//         for (const auto &block : snake)
//         {
//             if (new_head_position == block.getPosition())
//                 return false;
//         }
//         if (new_head_position.x == W || new_head_position.y == H || new_head_position.x == -1 || new_head_position.y == -1)
//             return false;
//         return true;
//     }
//     void doMovement(const sf::Vector2<int> &v)
//     {
//         if (is_done_process)
//             move_vector.pop_front();
//         move_vector.push_back(v);
//         is_done_process = false;
//     }

//     auto getHead()
//     {
//         auto front = snake.begin();
//         return front;
//     }

//     void updateTimeFrame(size_t step)
//     {
//         // if (FRAME_TIME > )
//         FRAME_TIME += step;
//     }

//     bool deleteBlock()
//     {
//     }

//     void eatFood(Food &f, Food &of)
//     {
//         if (f.getHealthment())
//         {
//             addBlock();
//             f.feedSnake(*this, of);
//             updateTimeFrame(FRAME_TIME_STEP);
//             std::cout << FRAME_TIME << std::endl;
//         }
//         else
//         {
//             deleteBlock();
//             f.feedSnake(*this, of);
//             updateTimeFrame(FRAME_TIME_STEP);
//             std::cout << FRAME_TIME << std::endl;
//         }
//     }

// public:
//     sf::Vector2<int> getHeadPosition()
//     {
//         auto front = getHead();
//         return front->getPosition();
//     }
//     Snake()
//     {
//         snake.push_front(SnakeBlock({0, 0}));
//         snake.push_front(SnakeBlock({1, 0}));
//         snake.push_front(SnakeBlock({2, 0}));
//         snake.push_front(SnakeBlock({3, 0}));
//         // auto front = snake.begin();
//         // std::cout << front->getPosition().x << " " << front->getPosition().y << std::endl;
//     }

//     bool moveSnake()
//     {
//         if (!is_add_block)
//         {
//             snake.pop_back();
//         }
//         is_add_block = false;
//         auto front = getHead();
//         // std::cout << "!! " << front->getPosition().x << " " << front->getPosition().y << std::endl;
//         auto &vector = move_vector.front();
//         front->setColor(COLOR_BODY);
//         sf::Vector2<int>
//             new_head_position = {front->getPosition().x + SPEED * vector.x, front->getPosition().y + SPEED * vector.y};
//         is_done_process = true;
//         if (move_vector.size() > 1)
//         {
//             // std::cout << "removed" << std::endl;
//             move_vector.pop_front();
//             is_done_process = false;
//         }
//         if (!checkHeadPosition(new_head_position))
//             return false;
//         snake.push_front(SnakeBlock(new_head_position, COLOR_HEAD));
//         return true;
//     }

//     void destroyTail()
//     {
//         snake.pop_back();
//     }

//     void drawSnake(sf::RenderWindow &w) const
//     {
//         for (const auto &block : snake)
//             w.draw(block.getShape());
//     }

//     void addBlock()
//     {
//         is_add_block = true;
//     }

//     void setDirection(Direction dir)
//     {
//         if (std::abs(static_cast<int>(direction)) != std::abs(static_cast<int>(dir)))
//             direction = dir;
//         // std::cout << "added << " << GET_ENUM(direction) << std::endl;
//         switch (direction)
//         {
//         case Direction::Up:
//         {
//             doMovement({0, -1});
//             break;
//         }
//         case Direction::Right:
//         {
//             doMovement({1, 0});
//             break;
//         }
//         case Direction::Left:
//         {
//             doMovement({-1, 0});
//             break;
//         }
//         case Direction::Down:
//         {
//             doMovement({0, 1});
//             break;
//         }
//         }
//     }

//     void checkFoodCollision(Food &f, Food &of)
//     {
//         if (f.getPosition() != getHeadPosition())
//             return;
//         eatFood(f, of);
//     }

//     auto getDirection()
//     {
//         return direction;
//     }

// private:
//     bool is_add_block = false;
//     std::deque<SnakeBlock> snake;
//     Direction direction = Direction::Right;
//     std::deque<sf::Vector2<int>> move_vector{{1, 0}};
//     bool is_done_process = true;
// };

int main(int argc, char *argv[])
{
    std::srand(std::time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Snake", sf::Style::Default, settings);
    // window.clear();
    auto start_time = std::chrono::steady_clock::now();
    Snake snake;
    Food h_food;
    Food b_food(false);
    bool skip = false;
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Down && snake.getDirection() != Direction::Down)
            {
                snake.setDirection(Direction::Down);
                break;
            }
            if (event.key.code == sf::Keyboard::Right && snake.getDirection() != Direction::Right)
            {
                snake.setDirection(Direction::Right);
                break;
            }
            if (event.key.code == sf::Keyboard::Up && snake.getDirection() != Direction::Up)
            {
                snake.setDirection(Direction::Up);
                break;
            }
            if (event.key.code == sf::Keyboard::Left && snake.getDirection() != Direction::Left)
            {
                snake.setDirection(Direction::Left);
                break;
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time) >= std::chrono::milliseconds(1000))
        {
            skip = false;
            start_time = std::chrono::steady_clock::now();
            if (!snake.moveSnake())
            {
                std::cout << "Game Over" << std::endl;
                window.close();
            }
            snake.checkFoodCollision(h_food, b_food);
            snake.checkFoodCollision(b_food, h_food);
            snake.drawSnake(window);
            h_food.drawFood(window);
            b_food.drawFood(window);
            window.display();
        }
    }
    return 0;
}
