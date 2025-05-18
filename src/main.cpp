#include <SFML/Graphics.hpp>
#include "Enemy.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Tower Defense");
    window.setFramerateLimit(60);

    CommonEnemy enemy;


    sf::Clock clock;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            // Enemy enemy;
        }

    //     window.clear();
    //     sf::CircleShape shape;
    //     window.draw(shape);
    //     window.display();


        // ⏱ Розрахунок часу
        float dt = clock.restart().asSeconds();

        // 🔄 Оновлення логіки
        enemy.update(dt);

        // 🖼 Малювання
        window.clear();
        enemy.draw(window);
        window.display();
    }
    }
// }
