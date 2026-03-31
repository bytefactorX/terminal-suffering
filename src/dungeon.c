#include "dungeon.h"
#include <stdio.h>

void print_dungeon_level(int level) {
    printf("The current dungeon level is: %d\n", level);
}

// super basic for now, inc will occur once player
// either defeats a certain enemy amt or something w/ a boss
// then, if level = buff, 
// run some win sequence
int inc_dungeon_level(int level, int buff) {
    if (level < buff) {
        return (level + 1); 
    }

    printf("Dungeon level incremented to: %d\n", level);
    return buff;
}

GameState dungeon_run() {
    print_dungeon_level(DUNGEON_START);

    inc_dungeon_level(DUNGEON_START, DUNGEON_LEVELS);

    return BATTLE_MODE;
}