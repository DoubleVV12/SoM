//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_LAYER_H
#define SFMLTEST_LAYER_H

#include <SFML/Graphics.hpp>
#include "Layer_component.h"


class Layer : public sf::Drawable {
public:
    Layer();
    virtual ~Layer();
    void add(Layer_component);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    Layer_component* component;
    int nb_component;
};


#endif //SFMLTEST_LAYER_H
