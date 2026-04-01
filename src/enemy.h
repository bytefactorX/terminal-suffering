#ifndef ENEMY_H
#define ENEMY_H

typedef struct Enemy {
    char title[24];
    int e_health;
    int e_defense;
    int e_attack;
} Enemy;

void init_slime(Enemy *e);

void init_knight(Enemy *e);

void init_rand_enemy(Enemy *e);

void reset_enemy(Enemy *e);

#endif