//
// Created by Walid on 25/05/2016.
//

#include <SFML/Graphics/Drawable.hpp>
#include "../Model/Game.h"
#include "Layer.h"

#ifndef SOM_GAME_VIEW_H
#define SOM_GAME_VIEW_H


class Game_view : public sf::Drawable {
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Game *game;

    Layer background;
    Layer base;
    Layer decoration;
    Layer sprites;
    Layer effect;

    std::list<Character_view*> cPlayer;
    std::list<Character_view*> cNpc;
    Map_view *mapView;

    sf::View camera;

    sf::Vertex line[5];
public:
    Game_view(Game *g);
    void handle_event(sf::Event* e = NULL);
    void handle_camera();
    void animate();
    sf::View get_camera();
};


#endif //SOM_GAME_VIEW_H
