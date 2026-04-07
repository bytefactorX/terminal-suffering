#include "src/player.h"
#include "src/enemy.h"
#include "src/battle.h"
#include "src/dungeon.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    // always begin in dungeon mode
    GameState state = DUNGEON_MODE;
    bool running = true;

    Player p;
    Enemy e;

    init_player(&p);
    init_rand_enemy(&e);
    
    print_dungeon_level(dungeon_start);
    print_player_ststats(&p);

    while(running) {
        // bool player_turn = determine_turn(&p, &e);

        switch (state) {
            case DUNGEON_MODE:
                state = dungeon_run(&p, &e);
                break;
            case BATTLE_MODE:
                state = battle_run(&p, &e, battle_options, NUM_BATTLE_OPTIONS);
                break;
            case GAME_OVER:
                printf("Oops, you died!\n");
                // will change to a continue option later
                running = false;
                break;
            default:
                printf("Game mode not found. quitting.\n");
                running = false;
        }
    }

    return 0;
}