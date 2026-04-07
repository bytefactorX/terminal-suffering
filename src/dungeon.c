#include "dungeon.h"
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int dungeon_start = 1;

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
int inc_dungeon_level(int dungeon_start, int threshold) {
    if (dungeon_start < threshold) {
        dungeon_start++;
        printf("You've made it to dungeon level %d\n", dungeon_start);
        return dungeon_start;
    }
    return threshold;
}

// this is always 1 for some reason
void print_dungeon_level(int dungeon_start) {
    printf("The current dungeon level is: %d\n", dungeon_start);
}

GameState dungeon_run(Player *p, Enemy*e) {
    print_walking_cycle();

    if (init_find_item()) {
        printf("Found item!\n");
    }

    if (init_rand_battle()) {
        // inc dungeon logic
        count += 1;

        if (count == ROUNDS) {
            count = 0;  // reset lvls
            dungeon_start = inc_dungeon_level(dungeon_start, DUNGEON_LEVELS);
            print_dungeon_level(dungeon_start);
        }

        // init battle
        printf("BATTLE STARTING.\n");
        print_battle_stats(p, e);
        return BATTLE_MODE;
    }

    return DUNGEON_MODE;
}