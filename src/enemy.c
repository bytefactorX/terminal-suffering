#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// for now just hard-coded values
// will be randomized later
void init_slime(Enemy *e) {
    // direct assignment does not work, so indirect instead
    strncpy(e->title, "Slime", 23);
    e->title[23] = '\0';
    e->e_attack = 7;
    e->e_health = 25;
    e->e_defense = 5;
}

void init_knight(Enemy *e) {
    // direct assignment does not work, so indirect instead
    strncpy(e->title, "Knight", 23);
    e->title[23] = '\0';
    e->e_attack = 20;
    e->e_health = 75;
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