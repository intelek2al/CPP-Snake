#pragma once

#include "Includes.h"

#include "Food.h"
#include "Snake.h"

class SnakeBlock
{
public:
    SnakeBlock(const sf::Vector2i &pos)
    {
        shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
        position = {pos.x, pos.y};
        global_position = GET_GLOBAL_POSITION(position);
        shape.setPosition(global_position.x, global_position.y);
        shape.setOutlineThickness(5.f);
        shape.setOutlineColor(COLOR_BORDER);
        shape.setFillColor(COLOR_BODY);
    }
    SnakeBlock(const sf::Vector2i &pos, sf::Color clr)
    {
        shape.setSize({BLOCK_SIZE, BLOCK_SIZE});
        position = {pos.x, pos.y};
        global_position = GET_GLOBAL_POSITION(position);
        shape.setPosition(global_position.x, global_position.y);
        shape.setOutlineThickness(5.f);
        shape.setOutlineColor(COLOR_BORDER);
        shape.setFillColor(clr);
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

    void setColor(sf::Color clr)
    {
        shape.setFillColor(clr);
    }

private:
    sf::RectangleShape shape;
    sf::Vector2<int> position;
    sf::Vector2<int> global_position;
};
