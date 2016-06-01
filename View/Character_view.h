//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_CHARACTER_VIEW_H
#define SFMLTEST_CHARACTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <c++/iostream>
#include "../Model/Character.h"
#include "../Util/util.h"
#include "Hitbox_view.h"
#include "Layer_component.h"
//#include "../Game.h"
//class Game{};

class Character_view : public Layer_component
{
public:
    Character_view(Character *c);
    virtual ~Character_view();
    virtual void animate();
    void stop();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void set_max_animation(Character::move_set);

    Character::move_set moveSet;
    sf::Texture texture;
    sf::Sprite sprite;
    Character *c;
    sf::VertexArray m_vertices;
    sf::Clock animation_clock;
    sf::Time elapsed_animation;
    unsigned short int frame;
    unsigned short int max_animation;
    Hitbox_view debug_hitbox;
    sf::Vector2f previousPosition;
};


#endif //SFMLTEST_CHARACTER_VIEW_H
