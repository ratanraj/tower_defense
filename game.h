//
// Created by ratanraj on 10/02/24.
//

#ifndef ALLEGRO_TEST_GAME_H
#define ALLEGRO_TEST_GAME_H


#include <allegro5/timer.h>
#include <allegro5/display.h>
#include "monsters.h"

class Game {
private:
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;

    // Bitmaps
    ALLEGRO_BITMAP* monster_a;
    ALLEGRO_BITMAP* monster_b;
    ALLEGRO_BITMAP* monster_c;
    ALLEGRO_BITMAP* monster_z;
    ALLEGRO_BITMAP* canon_base;
    ALLEGRO_BITMAP* canon_gun;
public:
    Game();
    virtual ~Game();

    void load_sprites();
    void run();
    void blit(int x, int y, enum Sprite sprite);
};


#endif //ALLEGRO_TEST_GAME_H

