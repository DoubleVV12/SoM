#define GLOBAL

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Model/Game.h"
#include "View/Game_view.h"

int main()
{
//    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(704,480), "SFML works!", sf::Style::Close);
//    sf::RenderWindow window(sf::VideoMode(1680,1050), "SFML works!", sf::Style::Close);
//    window.setFramerateLimit(120);

    Game g;
    Game_view game(&g);
//    sf::Time dt;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased);
                game.handle_event(&event);
        }

        dt = get_elapsed_time();
        game.handle_event();
        game.handle_camera();
        game.animate();

        window.clear();
        window.draw(game);
//        window.setMouseCursorVisible(false); //TODO : à activer plus tard
        window.setView(game.get_camera());
        window.display();
    }

    return 0;
}
