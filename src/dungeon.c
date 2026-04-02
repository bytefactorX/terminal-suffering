#include "dungeon.h"
#include <stdio.h>
#include <stdlib.h>

void print_dungeon_level(int level) {
    printf("The current dungeon level is: %d\n", level);
}

bool init_find_item() {
    int item_chance = rand() % 8;

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

// will call this dependent on how many enemies killed 
int inc_dungeon_level(int level, int threshold) {
    if (level < threshold) {
        return level += 1;
    }
    return 0;
}

GameState dungeon_run(Player *p, Enemy*e) {
    print_dungeon_level(DUNGEON_START);

    print_walking_cycle();

    if (init_find_item()) {
        printf("Found item!\n");
    }

    if (init_rand_battle()) {
        printf("BATTLE STARTING.\n");
        print_battle_stats(p, e);
        return BATTLE_MODE;
    }

    return DUNGEON_MODE;
}