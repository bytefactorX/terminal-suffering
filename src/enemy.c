#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void init_slime(Enemy *e) {
    int min = 5;
    int max = 10;

    // direct assignment does not work, so indirect instead
    strncpy(e->title, "Slime", 23);
    e->title[23] = '\0';
    // random between [5, 10]
    e->e_attack = (rand() % (max - min + 1)) + min;
    e->e_health = 25;
    e->e_defense = 5;
}

void init_knight(Enemy *e) {
    int min = 12;
    int max = 17;

    // direct assignment does not work, so indirect instead
    strncpy(e->title, "Knight", 23);
    e->title[23] = '\0';
    e->e_attack = (rand() % (max - min + 1)) + min;
    e->e_health = 60;
    e->e_defense = 15;
}

// when dungeons are implemented this will change
void init_rand_enemy(Enemy *e) {
    if (rand() % 2 == 0) {
        init_slime(e);
    }
    else {
        init_knight(e);
    }
}

void reset_enemy(Enemy *e) {
    init_slime(e);
    init_knight(e);
}