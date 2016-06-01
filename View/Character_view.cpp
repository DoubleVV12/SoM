//
// Created by DoubleVV on 26/04/2016.
//

#include "Character_view.h"

Character_view::Character_view(Character* c)
{
    std::cout << "Character_View." << std::endl;
    this->c = c;
    if(!texture.loadFromFile("Texture/Character/char2.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 40));
    setPosition(sf::Vector2f(this->c->getPosition().x,this->c->getPosition().y));
    sprite.setPosition(getPosition());
    moveSet = Character::WALK_DOWN;
    debug_hitbox = Hitbox_view(this->c->getHitbox());
//    texture.setSmooth(true);

    previousPosition = c->getPosition();
}

void Character_view::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on applique la texture
    states.texture = &texture;

    // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

    // on dessine le tableau de vertex
    target.draw(m_vertices, states);

    target.draw(sprite);
    target.draw(debug_hitbox);
}

Character_view::~Character_view() {
    sf::Texture::bind(NULL);
}

void Character_view::animate() {
    if(previousPosition.x < c->getPosition().x)
        moveSet = Character::WALK_RIGHT;
    else if(previousPosition.x > c->getPosition().x)
        moveSet = Character::WALK_LEFT;
    else if(previousPosition.y > c->getPosition().y)
        moveSet = Character::WALK_UP;
    else if(previousPosition.y < c->getPosition().y)
        moveSet = Character::WALK_DOWN;
    else {
//        std::cout << c->getSpeed().x << " " << c->getSpeed().y << std::endl;
        stop();
        return;
    }
    set_max_animation(moveSet);
    elapsed_animation+= (bullettime) ? animation_clock.restart()/SLOW_FACTOR : animation_clock.restart() ;
//    elapsed_animation += dt;
    if (elapsed_animation.asSeconds() > 0.1)
    {
        frame = ++frame%max_animation;
        sprite.setTextureRect(sf::IntRect((frame+1) *CHARA_SPRITE_W, moveSet*CHARA_SPRITE_H, CHARA_SPRITE_W, CHARA_SPRITE_H));
        elapsed_animation = sf::seconds(0);
    }
    setPosition(sf::Vector2f(this->c->getPosition().x,this->c->getPosition().y));
    sprite.setPosition(getPosition());
    debug_hitbox.update();
    previousPosition = c->getPosition();
}

void Character_view::set_max_animation(Character::move_set a)
{
    switch (a){
        case Character::WALK_DOWN :
            max_animation = 6;
            break;
        case Character::WALK_LEFT :
            max_animation = 6;
            break;
        case Character::WALK_UP :
            max_animation = 6;
            break;
        case Character::WALK_RIGHT :
            max_animation = 6;
            break;
    }
}

void Character_view::stop() {
//    Character::stop();
    sprite.setTextureRect(sf::IntRect(0, moveSet*CHARA_SPRITE_H, CHARA_SPRITE_W, CHARA_SPRITE_H));
    frame =0;
}












