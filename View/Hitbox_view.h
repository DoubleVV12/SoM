//
// Created by DoubleVV on 06/05/2016.
//

#ifndef SFMLTEST_HITBOX_VIEW_H
#define SFMLTEST_HITBOX_VIEW_H

#include "../Model/Hitbox.h"

class Hitbox_view : public sf::Drawable {
private:
    Hitbox *hitbox;
    sf::Vertex line[5];

public:
    Hitbox_view(Hitbox*);
    Hitbox_view();
    void update();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFMLTEST_HITBOX_VIEW_H
