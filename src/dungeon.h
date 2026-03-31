#ifndef DUNGEON_H
#define DUNGEON_H

#include "game_state.h"

#define DUNGEON_LEVELS 100
#define DUNGEON_START 1

void print_dungeon_level(int level);

int inc_dungeon_level(int level, int buff);

GameState dungeon_run();

#endif