#ifndef BATTLE_H
#define BATTLE_H

#include <stdbool.h>

struct Player;
struct Enemy;

bool determine_turn(struct Player *p, struct Enemy* e);

// so these dont need = or ; lmao
#define NUM_BATTLE_OPTIONS 4

// just delcare here, no need to define
extern char *battle_options[NUM_BATTLE_OPTIONS];

void print_battle_options(char *battle_options[], int count);

int player_select(char *battle_options[], int count);

void player_attack(struct Player *p, struct Enemy *e);

void player_sp_attack(struct Player *p, struct Enemy *e);

// items not yet implemented
void player_item();

void player_run(struct Player *p);

void enemy_attack(struct Player *p, struct Enemy*e);

#endif