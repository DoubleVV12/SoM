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
//#include "../Game.h"
//class Game{};

class Character_view : public sf::Drawable, public sf::Transformable
{
public:
    Character_view(Character *c);
    virtual ~Character_view();
    void animate(move_set);
    void stop();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void set_max_animation(move_set);

    move_set moveSet;
    sf::Texture texture;
    sf::Sprite sprite;
    Character *c;
    sf::VertexArray m_vertices;
    sf::Clock animation_clock;
    sf::Time elapsed_animation;
    unsigned short int frame;
    unsigned short int max_animation;
    Hitbox_view debug_hitbox;
};


#endif //SFMLTEST_CHARACTER_VIEW_H
