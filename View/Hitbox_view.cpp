//
// Created by DoubleVV on 06/05/2016.
//

#include "Hitbox_view.h"
#include "../Util/Global.h"

Hitbox_view::Hitbox_view(Hitbox* h) {
    hitbox = h;
    line[0] = sf::Vertex(hitbox->getPosition());
    line[1] = sf::Vertex(sf::Vector2f(hitbox->getPosition().x+hitbox->get_size().x, hitbox->getPosition().y));
    line[2] = sf::Vertex(sf::Vector2f(hitbox->getPosition().x+hitbox->get_size().x,
                                      hitbox->getPosition().y+hitbox->get_size().y));
    line[3] = sf::Vertex(sf::Vector2f(hitbox->getPosition().x, hitbox->getPosition().y+hitbox->get_size().y));
    line[4] = line[0];
}

void Hitbox_view::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(debug_show_sprite_hitbox)
        target.draw(line, 5, sf::LinesStrip);
}

Hitbox_view::Hitbox_view() {
    hitbox = NULL;
}

void Hitbox_view::update() {
    line[0] = sf::Vertex(hitbox->getPosition());
    line[1] = sf::Vertex(sf::Vector2f(hitbox->getPosition().x+hitbox->get_size().x, hitbox->getPosition().y));
    line[2] = sf::Vertex(sf::Vector2f(hitbox->getPosition().x+hitbox->get_size().x,
                                      hitbox->getPosition().y+hitbox->get_size().y));
    line[3] = sf::Vertex(sf::Vector2f(hitbox->getPosition().x, hitbox->getPosition().y+hitbox->get_size().y));
    line[4] = line[0];
}








