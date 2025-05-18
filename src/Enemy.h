//
// Created by andre on 04.05.2025.
//
#pragma once
#include <vector>
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Enemy {
public:
    Enemy();
    virtual ~Enemy() = default;
    virtual void update(float dt);
    virtual void draw(sf::RenderWindow&) const;
    virtual void takeDamage(int dmg);
    virtual bool isAlive() const;
    virtual bool reachedEnd() const;
    virtual sf::Vector2f getPosition() const;
    virtual void setPath(std::vector<sf::Vector2f>);


protected:
    std::vector<sf::Vector2f> path;
    unsigned int pathIndex{};
    sf::CircleShape shape;
    float speed{};
    int health{};
    bool reached{};
    };
// Enemy

class CommonEnemy: public Enemy{
public:
    CommonEnemy();
};
