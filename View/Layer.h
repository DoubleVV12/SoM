//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_LAYER_H
#define SFMLTEST_LAYER_H

#include <SFML/Graphics.hpp>
#include <c++/list>
#include "Layer_component.h"


class Layer : public sf::Drawable {
public:
//    Layer();
//    ~Layer();
    void add(Layer_component*);
    void animate();
    void sort();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::list<Layer_component*> component;

    void erase();
};


#endif //SFMLTEST_LAYER_H
