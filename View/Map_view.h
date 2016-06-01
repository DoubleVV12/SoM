//
// Created by DoubleVV on 26/04/2016.
//

#ifndef SFMLTEST_MAP_VIEW_H
#define SFMLTEST_MAP_VIEW_H

#include <SFML/Graphics.hpp>
#include <c++/string>
#include "../Model/Map.h"
#include "Hitbox_view.h"
#include "Layer_component.h"

class Map_view : public Layer_component {
public:
    Map_view(Map*);
    ~Map_view();

private:
    bool load(const std::string &tileset, sf::Vector2u tileSize, unsigned int width,
              unsigned int height);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
    Map *map;
    std::list<Hitbox_view> debug;
};


#endif //SFMLTEST_MAP_VIEW_H
