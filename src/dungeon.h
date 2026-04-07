#ifndef DUNGEON_H
#define DUNGEON_H

#include "game_state.h"
#include "output.h"
#include "battle.h"
#include <stdbool.h>

struct Player;
struct Enemy;

// amount of battles before increasing dungeon lvl
#define ROUNDS 10

#define DUNGEON_LEVELS 100
extern int dungeon_start;

int inc_dungeon_level(int dungeon_start, int threshold);

void print_dungeon_level(int dungeon_start);

bool init_find_item();

bool init_rand_battle();

GameState dungeon_run(Player *p, Enemy *e);

#endif