// conditional compilation
#ifndef PLAYER_H
#define PLAYER_H

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

void level_up(struct Player *p);

void upgrade_player(struct Player *p);

void damage_player(struct Player *p, int dmg);

#endif