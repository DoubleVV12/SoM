//
// Created by DoubleVV on 26/04/2016.
//

#include <c++/iostream>
#include "Map_view.h"
#include "../Util/Global.h"

Map_view::Map_view(Map* m) {
    std::cout << "Map_View." << std::endl;
    this->map = m;
    if (!load("./Texture/Map/tiles.png", sf::Vector2u(TILE_SIZE, TILE_SIZE), 16, 8))
        std::cout << "Failed to load player spritesheet!" << std::endl;

    for(Hitbox* h : map->get_hitbox()){
        debug.push_back(Hitbox_view(h));
    }
}

bool Map_view::load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
    // on charge la texture du tileset
    if (!m_texture.loadFromFile(tileset))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // on récupère le numéro de tuile courant
            int tileNumber = map->getLevel()[i + j * width];

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (m_texture.getSize().x / tileSize.x);
            int tv = tileNumber / (m_texture.getSize().x / tileSize.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void Map_view::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation de l'entité -- on la combine avec celle qui a été passée par l'appelant
    states.transform *= getTransform(); // getTransform() est définie par sf::Transformable

    // on applique la texture
    states.texture = &m_texture;

    // on peut aussi surcharger states.shader ou states.blendMode si nécessaire

    // on dessine le tableau de vertex
    target.draw(m_vertices, states);

    for(Hitbox_view h : debug){
        target.draw(h);
    }
}

Map_view::~Map_view() {
    sf::Texture::bind(NULL);

}






