//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_CHARACTER_H
#define SFMLTEST_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <c++/iostream>

#include "Hitbox.h"
#include "Map.h"
#include "../Util/util.h"


#define WALKING_SPEED 100


//TODO Réécriture de la classe et la décomposer en 3 classes
class Character
{
private:
    sf::Vector2f position;
    float speed;
    Hitbox hitbox;
    std::string name;

public:
    enum direction{LEFT,UP,RIGHT,DOWN};
    enum move_set{WALK_DOWN,WALK_LEFT,WALK_UP,WALK_RIGHT};

    //Constructor, copy constructor and destructor
    Character(int xpos, int ypos, std::string name = "Character");
    Character(const Character& other);
    virtual ~Character();

    //Getter and setter
    sf::Vector2f getPosition();
    void setPosition(float,float);

    Hitbox* getHitbox();

    float getSpeed();
    void setSpeed(float s);

    std::string getName();
    void setName(std::string s);

    //Other functions
    virtual bool move(direction d, Map* m, std::list<Character*>* npc, std::list<Character*>* playableChar, float factor = 1) = 0;
    void stop();
    virtual void calculHitbox(direction d);
    bool verifyMove(direction d, Hitbox *h);
    bool verifyMoveMap(direction d, std::list<Hitbox *> hb);

};


#endif //SFMLTEST_CHARACTER_H
