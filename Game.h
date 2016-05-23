//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H


#include <SFML/Graphics/Drawable.hpp>
//#include "Model/Map.h"
//#include "Model/Character.h"
#include "View/Character_view.h"
#include "View/Map_view.h"

class Game : public sf::Drawable {
public:
    Game();
    void handle_event(sf::Event*);
    void handle_event();
    void handle_camera();
    void handle_hitboxes();
    sf::View get_camera();


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    Character* player;
    Character* test;
    Map* current_map;
    Character_view *cView;
    Character_view *cTest;
    Map_view *mapView;
    sf::View camera;

    sf::Vertex line[5];

};


#endif //SFMLTEST_GAME_H

