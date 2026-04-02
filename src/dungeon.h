#ifndef DUNGEON_H
#define DUNGEON_H

#include "game_state.h"
#include "output.h"
#include <stdbool.h>

struct Player;
struct Enemy;

#define DUNGEON_LEVELS 100
#define DUNGEON_START 1

void print_dungeon_level(int level);

int inc_dungeon_level(int level, int threshold);

bool init_find_item();

bool init_rand_battle();

GameState dungeon_run(Player *p, Enemy *e);

#endif