#ifndef DUNGEON_H
#define DUNGEON_H

#include "game_state.h"
#include "output.h"
#include <stdbool.h>

#define DUNGEON_LEVELS 100
#define DUNGEON_START 1

void print_dungeon_level(int level);

bool init_find_item();

bool init_rand_battle();

GameState dungeon_run();

#endif