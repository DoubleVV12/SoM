//
// Created by DoubleVV on 26/04/2016.
//

#include <c++/iostream>
#include "Layer.h"

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(Layer_component *comp : component){
        target.draw(*comp);
    }
}

void Layer::add(Layer_component *new_component) {
    component.push_back(new_component);
}

void Layer::erase() {
    component.pop_back();
}

void Layer::animate() {
    for(Layer_component *comp : component){
        comp->animate();
    }
}

void Layer::sort() {
    component.sort([](Layer_component* first, Layer_component* second){
        return first->getPosition().y < second->getPosition().y;});
}