//
// Created by andre on 04.05.2025.
//

#include "Enemy.h"

#include <cmath>


Enemy::Enemy() {
    speed = 0.f;
    health = 0;
    reached = false;
    pathIndex = 0;
    path = {
        {100.f, 100.f},
        {300.f, 100.f},
        {300.f, 300.f},
        {500.f, 300.f},
        {600.f, 300.f},
        {600.f, 400.f},
        {600.f, 500.f},
        {500.f, 500.f},
        {400.f, 500.f},
        {400.f, 600.f},
        {400.f, 700.f},
        {500.f, 700.f},
        {600.f, 700.f},
        {700.f, 700.f},
        {800.f, 700.f},
        {800.f, 800.f},
        {900.f, 800.f},
        {1000.f, 800.f},
        {1100.f, 800.f},
        {1200.f, 800.f},
        {1200.f, 900.f},
        {1200.f, 800.f},
        {1200.f, 700.f},
        {1200.f, 600.f},
        {1200.f, 500.f},
        {1300.f, 500.f}
    };
    shape.setRadius(15.f);
    shape.setOrigin({15.f, 15.f});

    // Ось тут — задаємо колір
    shape.setFillColor(sf::Color::Red);       // готові кольори
    // або свої:
    // shape.setFillColor(sf::Color(255, 100, 50, 200)); // RGBA

    // За бажанням: контур
    // shape.setOutlineColor(sf::Color::Black);
    // shape.setOutlineThickness(2.f);

    // Встановлюємо початкову позицію
    if (!path.empty())
        shape.setPosition(path[0]);
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Enemy::update(const float dt) {
    if (pathIndex < path.size()) {
    sf::Vector2f target = path[pathIndex];
    sf::Vector2f direction = target - shape.getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 1.f) {
        pathIndex++;
        if (pathIndex >= path.size()) {
            reached = true;
        }
    } else {
        direction /= distance; // нормалізація
        shape.move(direction * speed * dt);
    }
}}

bool Enemy::isAlive() const {
    return health > 0;
}


void Enemy::takeDamage(const int dmg) {
    health -= dmg;
};


sf::Vector2f Enemy::getPosition() const {
    return shape.getPosition();
}

bool Enemy::reachedEnd() const {
    return reached || pathIndex >= path.size();
}

void Enemy::setPath(std::vector<sf::Vector2f> newpath) {
    path = newpath;
};
// Enemy

CommonEnemy::CommonEnemy() {
    speed = 100;
    health = 100;
    reached = false;
    pathIndex = 0;
};