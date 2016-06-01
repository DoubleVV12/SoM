//
// Created by DoubleVV on 28/04/2016.
//

#ifndef SFMLTEST_UTIL_H
#define SFMLTEST_UTIL_H

#include "Global.h"

static void start_clock(){ //TODO : savoir si ça sert vraiment
    game_clock.restart();
}

static sf::Time get_elapsed_time(){
    static sf::Time old_time;
    sf::Time dt;
    sf::Time current_time = game_clock.getElapsedTime();

    dt = current_time - old_time;
    old_time = current_time;
    return (bullettime) ? dt / SLOW_FACTOR : dt;
}

static bool tile_permeability[] = {
        false,false,false,false,false,true,
        false,false,false,false,false,false,
        false,true,false,false,false,false,
        true,true,false,true,false,false,
        true,true,true,true,false,false,
        true,true,false,false,false,false,

};
#endif //SFMLTEST_UTIL_H

