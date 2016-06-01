//
// Created by DoubleVV on 26/04/2016.
//

#include "Layer_component.h"

void Layer_component::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on applique la texture
    states.texture = &texture;

    // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

    // on dessine le tableau de vertex
    target.draw(vertices, states);
}

void Layer_component::animate() {

}



