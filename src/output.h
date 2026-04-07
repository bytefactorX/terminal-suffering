#ifndef OUTPUT_H
#define OUTPUT_H

#include "player.h"
#include "enemy.h"
#include "dungeon.h"

struct Player;
struct Enemy;

void init_game_text();

void print_player_ststats(struct Player *p);

void print_battle_stats(struct Player *p, struct Enemy *e);

void print_player_expup(struct Player *p);

void print_player_lvlup(struct Player *p);

void print_walking_cycle();

#endif