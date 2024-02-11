//
// Created by ratanraj on 10/02/24.
//

#ifndef ALLEGRO_TEST_GAME_H
#define ALLEGRO_TEST_GAME_H


#include <allegro5/timer.h>
#include <allegro5/display.h>

class Game {
private:
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;

public:
    Game();
    virtual ~Game();

    void run();
};


#endif //ALLEGRO_TEST_GAME_H

