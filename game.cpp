//
// Created by ratanraj on 10/02/24.
//
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "game.h"

Game::Game() {
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();

    timer = al_create_timer(1.0 / 30.0);
    queue = al_create_event_queue();
    display = al_create_display(1024, 768);

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
}

Game::~Game() {
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);
    std::cout<<"end"<<std::endl;
}


void Game::run() {
  ALLEGRO_EVENT event;

  bool redraw = true;
  bool done = false;
  
  float x=0.0, y=0.0;

  al_start_timer(timer); // Start the Game

  for(int i=0;i<1;i++) {
    while(1) {
      al_wait_for_event(queue, &event);
      
      switch (event.type) {
        case ALLEGRO_EVENT_TIMER:
          redraw = true;
          break;

        case ALLEGRO_EVENT_KEY_DOWN:

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
          done=true;
          break;
      }

      if(done) break;

      if (redraw && al_is_event_queue_empty(queue)) {
        update();
        al_flip_display();
        redraw = false;
      }
    }
  }
}

void Game::update() {
  al_clear_to_color(al_map_rgb(20, 20, 80));
  al_draw_rectangle(20, 20, 1004, 748, al_map_rgb(200, 200, 200), 2);
}
