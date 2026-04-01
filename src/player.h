// conditional compilation
#ifndef PLAYER_H
#define PLAYER_H

#include "output.h"

typedef struct Player {
    char name[24];
    int health;
    int attack;
    int defense;
    int level;
    int exp;
    int mp;
} Player;

void init_player(struct Player *p);

void gain_exp(struct Player *p);

void level_up(struct Player *p);

// not yet implemented
void upgrade_player(struct Player *p);

int calc_crit_dmg(struct Player *p);

void player_win_sub(struct Player *p);

#endif