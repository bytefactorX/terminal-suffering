#include "dungeon.h"
#include <stdio.h>
#include <stdlib.h>

void print_dungeon_level(int level) {
    printf("The current dungeon level is: %d\n", level);
}

bool init_find_item() {
    int item_chance = rand() % 4;

    if (item_chance == 0) {
        return true;
    }
    return false;
}

bool init_rand_battle() {
    int battle_chance = rand() % 5;

    if (battle_chance == 0) {
        return true;
    }
    return false;
}

GameState dungeon_run() {
    print_dungeon_level(DUNGEON_START);

    print_walking_cycle();

    if (init_find_item()) {
        printf("Found item!\n");
    }

    if (init_rand_battle()) {
        return BATTLE_MODE;
    }

    return DUNGEON_MODE;
}