//
// Created by ratanraj on 10/02/24.
//
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include <iostream>
#include "game.h"
#include "utils.h"
#include "monsters.h"
#include "tower.h"

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

  load_sprites();
  al_start_timer(timer); // Start the Game

  for(int i=0;i<1;i++) {
    
    // generate monsters
    std::vector<Monster> monster_list;
    for(int m_counter=0; m_counter<10;m_counter++) {
        Monster mx(m_counter*70, 100);
        monster_list.push_back(mx);
    }

    // Towers

    Tower t1;

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
        al_clear_to_color(al_map_rgb(0, 0, 0));
        for(auto m=monster_list.begin(); m!=monster_list.end(); ++m) {
          if (m->is_alive()) {
            blit(m->get_x(), m->get_y(), m->get_monster_type());
            m->forward();
            if (t1.is_within_range(m->get_x(), m->get_y()))
              m->damage();
          }
        }

        al_draw_bitmap(canon_base, t1.get_x(), t1.get_y(), 0);  

        al_flip_display();
        redraw = false;
      }
    }
  }
}


void Game::load_sprites() {
  monster_a = al_load_bitmap("./sprites/monster_a.png");
  monster_b = al_load_bitmap("./sprites/monster_a.png");
  monster_c = al_load_bitmap("./sprites/monster_a.png");
  monster_z = al_load_bitmap("./sprites/monster_a.png");
  canon_base = al_load_bitmap("./sprites/base.png");
  canon_gun = al_load_bitmap("./sprites/canon.png");
}

void Game::blit(int x, int y, enum Sprite sprite) {
  switch(sprite) {
    case B_CANON_BASE:
      al_draw_bitmap(canon_base, x, y, 0);
      break;
    case B_MONSTER_A:
      al_draw_bitmap(monster_a, x, y, 0);
      break;
    case B_MONSTER_B:
      al_draw_bitmap(monster_b, x, y, 0);
      break;
    case B_MONSTER_C:
      al_draw_bitmap(monster_c, x, y, 0);
  }
}
