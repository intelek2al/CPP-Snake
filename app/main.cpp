#include <iostream>
#include <utility>
#include <stdlib.h>
#include <deque>
#include <chrono>
#include <random>

#include "Graphics.hpp"

#define BLOCK_SIZE 40

#define SPEED 1
#define FOOD_SIZE BLOCK_SIZE

#define GET_STRING(x) #x
#define GET_VALUE(x) GET_STRING(x)
#define GET_ENUM(x) GET_VALUE(x)

int W = 20;
int H = 20;

int SCREEN_W = BLOCK_SIZE * W;
int SCREEN_H = BLOCK_SIZE * H;

template <typename T>
sf::Vector2<T> GET_GLOBAL_POSITION(T x, T y)
{
    return {BLOCK_SIZE * x, BLOCK_SIZE * y};
}

template <typename T>
sf::Vector2<T> GET_GLOBAL_POSITION(sf::Vector2<T> pos)
{
    return GET_GLOBAL_POSITION(pos.x, pos.y);
}

template <typename T>
bool OPERATOR_EQUEL_VECTOR(const sf::Vector2<T> &lhs, const sf::Vector2<T> &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

enum class Direction
{
    Up = -1,
    Right = 2,
    Down = 1,
    Left = -2
};

struct VectorObject
{
    sf::Vector2<int> UL;
    sf::Vector2<int> DR;
};

class Food
{
public:
    Food(bool _is_good = true) : is_good(_is_good)
    {
        shape = sf::RectangleShape({FOOD_SIZE, FOOD_SIZE});
        position = {std::rand() % (W - 1) + 1, std::rand() % (H - 1) + 1};
        global_position = GET_GLOBAL_POSITION(position);
        color = is_good ? sf::Color::Green : sf::Color::Red;
        shape.setPosition(global_position.x, global_position.y);
        shape.setFillColor(color);
        shape.setOutlineThickness(5.f);
        shape.setOutlineColor(sf::Color::Magenta);
    }

    const auto &getPosition() const
    {
        return position;
    }

    const auto &getGlobalPosition() const
    {
        return global_position;
    }

    void drawFood(sf::RenderWindow &w) const
    {
        w.draw(shape);
    }

private:
    sf::RectangleShape shape;
    sf::Color color;
    sf::Vector2<int> position;
    sf::Vector2<int> global_position;
    const bool is_good;
};

class SnakeBlock
{
public:
    SnakeBlock()
    {
        shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
        position = {0, 0};
        global_position = GET_GLOBAL_POSITION(position);
        shape.setPosition(global_position.x, global_position.y);
        shape.setFillColor(sf::Color::Cyan);
    }
    SnakeBlock(const sf::Vector2i &pos)
    {
        shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
        position = {pos.x, pos.y};
        global_position = GET_GLOBAL_POSITION(position);
        shape.setPosition(global_position.x, global_position.y);
        shape.setFillColor(sf::Color::Cyan);
    }

    auto &getShape() const
    {
        return shape;
    }

    const auto &getPosition() const
    {
        return position;
    }

    const auto &getGlobalPosition() const
    {
        return global_position;
    }

private:
    sf::RectangleShape shape;
    sf::Vector2<int> position;
    sf::Vector2<int> global_position;
};

class Snake
{
private:
    bool checkHeadPosition(sf::Vector2<int> new_head_position)
    {
        for (const auto &block : snake)
        {
            if (new_head_position == block.getPosition())
                return false;
        }
        return true;
    }
    void doMovement(const sf::Vector2<int> &v)
    {
        if (is_done_process)
            move_vector.pop_front();
        move_vector.push_back(v);
        is_done_process = false;
    }

    auto getHead() const
    {
        auto front = snake.begin();
        return front;
    }
    sf::Vector2<int> getHeadPosition() const
    {
        auto front = getHead();
        return front->getPosition();
    }

public:
    Snake()
    {
        snake.push_front(SnakeBlock({0, 0}));
        snake.push_front(SnakeBlock({1, 0}));
        snake.push_front(SnakeBlock({2, 0}));
        snake.push_front(SnakeBlock({3, 0}));
        auto front = snake.begin();
        std::cout << front->getPosition().x << " " << front->getPosition().y << std::endl;
    }

    bool moveSnake()
    {
        if (!is_add_block)
        {
            snake.pop_back();
        }
        is_add_block = false;
        auto front = getHead();
        std::cout << "!! " << front->getPosition().x << " " << front->getPosition().y << std::endl;
        auto &vector = move_vector.front();

        sf::Vector2<int> new_head_position = {front->getPosition().x + SPEED * vector.x, front->getPosition().y + SPEED * vector.y};
        is_done_process = true;
        if (move_vector.size() > 1)
        {
            std::cout << "removed" << std::endl;
            move_vector.pop_front();
            is_done_process = false;
        }
        if (!checkHeadPosition(new_head_position))
            return false;
        snake.push_front(SnakeBlock(new_head_position));
        return true;
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
        std::cout << "added << " << GET_ENUM(direction) << std::endl;
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

    void checkFoodCollision(const Food &f)
    {
        if (f.getPosition() == getHeadPosition())
            std::cout << "Yummy" << std::endl;
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

int main(int argc, char *argv[])
{
    std::srand(std::time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Snake", sf::Style::Default, settings);
    // window.clear();
    auto start_time = std::chrono::steady_clock::now();
    Snake snake;
    Food food;
    bool skip = false;
    size_t TM = 100;
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Tab)
            {
                TM -= 10;
                break;
            }
            if (event.key.code == sf::Keyboard::Space)
            {
                snake.addBlock();
                break;
            }
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

        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time) >= std::chrono::milliseconds(TM))
        {
            skip = false;
            start_time = std::chrono::steady_clock::now();
            if (!snake.moveSnake())
            {
                std::cout << "Game Over" << std::endl;
                window.close();
            }
            snake.checkFoodCollision(food);
            snake.drawSnake(window);
            food.drawFood(window);
            window.display();
        }
    }
    return 0;
}
