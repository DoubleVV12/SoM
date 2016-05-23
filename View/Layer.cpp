//
// Created by DoubleVV on 26/04/2016.
//

#include "Layer.h"

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    {
        for(int i=0; i<nb_component; i++){
            target.draw(component[i]);
        }
    }
}

void Layer::add(Layer_component new_component) {
    nb_component++;

    Layer_component tmp[nb_component];
    component = new Layer_component[nb_component];

    for(int i=0; i<nb_component-1; i++)
    {
        tmp[i] = component[i];
    }

    tmp[nb_component-1] = new_component;

    *component = *tmp;
}

Layer::Layer() {
    nb_component = 0;
    component = new Layer_component[nb_component];
}

Layer::~Layer(){
//    delete[] component;
}





