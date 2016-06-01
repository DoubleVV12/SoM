//
// Created by DoubleVV on 30/04/2016.
//

#define SLOW_FACTOR 4.0f
#define TILE_SIZE 16
#define CAMERA_SENSITIVITY 0.35f
#define CHARA_SPRITE_W 30
#define CHARA_SPRITE_H 40
#define PUSH_FACTOR 0.5f

#include <SFML/Graphics.hpp>

#ifdef GLOBAL
#define Global
#else
#define Global extern
#endif

Global sf::Clock game_clock;
Global sf::Time dt;
Global bool bullettime;
Global bool debug_show_camera_hitbox;
Global bool debug_show_sprite_hitbox;