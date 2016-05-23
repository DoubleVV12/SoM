//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_LAYER_COMPONENT_H
#define SFMLTEST_LAYER_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "../Game.h"

class Layer_component : public sf::Drawable, public sf::Transformable {
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Texture texture;
    sf::VertexArray vertices;
    Game *game;
};


#endif //SFMLTEST_LAYER_COMPONENT_H
