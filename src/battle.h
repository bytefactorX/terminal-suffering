#ifndef BATTLE_H
#define BATTLE_H

#include <stdbool.h>
#include "player.h"
#include "enemy.h"
#include "output.h"
#include "game_state.h"

struct Player;
struct Enemy;

// so these dont need = or ; lmao
#define NUM_BATTLE_OPTIONS 4

// just delcare here, no need to define
extern char *battle_options[NUM_BATTLE_OPTIONS];

bool determine_turn(struct Player *p, struct Enemy* e);

void print_battle_options(char *battle_options[], int count);

int player_select(char *battle_options[], int count);

void print_battle_stats(struct Player *p, struct Enemy *e);

bool player_attack(struct Player *p, struct Enemy *e);

// not yet implemented
void player_sp_attack(struct Player *p, struct Enemy *e);

// not yet implemented
void player_use_item(); 

bool player_run(struct Player *p);

bool enemy_attack(struct Player *p, struct Enemy*e);

int enemies_killed();

GameState battle_run(Player *p, Enemy *e, char *battle_options[], int count);

#endif