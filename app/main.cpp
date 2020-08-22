#include <iostream>
#include <utility>
#include <stdlib.h>
#include <deque>

#include "Graphics.hpp"

#define SPEED 0.02

enum class Direction
{
    Up,
    Right,
    Down,
    Left
};

class SnakeBlock /* : public sf::Drawable, public sf::Transformable*/
{
public:
    SnakeBlock()
    {
        shape.setSize({40, 40});
        shape.setPosition(30, 30);
        shape.setFillColor(sf::Color::Cyan);
    }
    SnakeBlock(const sf::Vector2f &size, const sf::Vector2f &pos)
    {
        shape.setSize(size);
        shape.setPosition(pos.x, pos.y);
        shape.setFillColor(sf::Color::Cyan);
    }

    auto &getShape() const
    {
        return shape;
    }

    auto &getPosition() const
    {
        return position;
    }

    void setDirection(Direction dir)
    {
        direction = dir;
        switch (direction)
        {
        case Direction::Up:
        {
            speed.x = 0;
            speed.y = -SPEED;
            break;
        }
        case Direction::Right:
        {
            speed.x = SPEED;
            speed.y = 0;
            break;
        }
        case Direction::Left:
        {
            speed.x = -SPEED;
            speed.y = 0;
            break;
        }
        case Direction::Down:
        {
            speed.x = 0;
            speed.y = SPEED;
            break;
        }
        }
    }

    auto &moveShape()
    {
        position.x += speed.x;
        position.y += speed.y;
        shape.setPosition(position.x, position.y);
        return shape;
    }
    // virtual void draw () override {

    // }
private:
    sf::RectangleShape shape;
    sf::Vector2<float> speed = {SPEED, 0};
    sf::Vector2<float> position;
    Direction direction;
};

class Snake
{
public:
    Snake()
    {
        snake.push_back(SnakeBlock({40, 40}, {30, 30}));
        snake.push_back(SnakeBlock({40, 40}, {70, 70}));
        snake.push_back(SnakeBlock({40, 40}, {110, 110}));
        snake.push_back(SnakeBlock({40, 40}, {150, 150}));
        auto front = snake.begin();
        std::cout << front->getPosition().x << " " << front->getPosition().y << std::endl;
    }

    void moveSnake()
    {
        snake.pop_back();
        auto front = snake.begin();
        std::cout << front->getPosition().x << " " << front->getPosition().y << std::endl;
        snake.push_front(SnakeBlock({40, 40}, {front->getPosition().x + 40, front->getPosition().y + 40}));
    }

    void drawSnake(sf::RenderWindow &w) const
    {
        for (const auto &block : snake)
            w.draw(block.getShape());
    }

private:
    std::deque<SnakeBlock> snake;
};

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    // window.clear();

    Snake snake;
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            // if (event.key.code == sf::Keyboard::Down)
            // {
            //     snake.setDirection(Direction::Down);
            // }
            // if (event.key.code == sf::Keyboard::Right)
            // {
            //     snake.setDirection(Direction::Right);
            // }
            // if (event.key.code == sf::Keyboard::Up)
            // {
            //     snake.setDirection(Direction::Up);
            // }
            // if (event.key.code == sf::Keyboard::Left)
            // {
            //     snake.setDirection(Direction::Left);
            // }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        snake.moveSnake();
        snake.drawSnake(window);
        // window.draw(snake.getShape());
        sf::Time tm(sf::seconds(0.5));
        sf::sleep(tm);
        window.display();
    }
    return 0;
}
