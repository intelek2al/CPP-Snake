#pragma once
#include "Includes.h"

#include "Snake.h"
#include "SnakeBlocks.h"

class Food
{
public:
    const auto &getPosition() const
    {
        return position;
    }

    const auto &getGlobalPosition() const
    {
        return global_position;
    }

private:
    sf::Vector2<int> generatePosition(Snake &snake, Food &food)
    {
        sf::Vector2<int> pos = {std::rand() % (W - 1) + 1, std::rand() % (H - 1) + 1};
        while (snake.getHeadPosition() == pos || food.getPosition() == pos)
        {
            pos = {std::rand() % (W - 1) + 1, std::rand() % (H - 1) + 1};
        }
        return pos;
    }

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

    auto getHealthment() const
    {
        return is_good;
    }

    void drawFood(sf::RenderWindow &w) const
    {
        w.draw(shape);
    }

    void feedSnake(Snake &snake, Food &food)
    {
        position = generatePosition(snake, food);
        global_position = GET_GLOBAL_POSITION(position);
        color = is_good ? sf::Color::Green : sf::Color::Red;
        shape.setPosition(global_position.x, global_position.y);
    }

private:
    sf::RectangleShape shape;
    sf::Color color;
    sf::Vector2<int> position;
    sf::Vector2<int> global_position;
    const bool is_good;
};
