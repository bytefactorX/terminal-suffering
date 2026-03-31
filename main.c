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

    // bool player_turn = determine_turn(&p, &e);

    printf("Player Name: %s\n Level: %d\n Health: %d\n Attack: %d\n Defense: %d\n Mp: %d\n", p.name,
    p.level, p.health, p.attack, p.defense, p.mp);

    // testing purposes
    printf("Enemy Title: %s\n Health: %d\n Attack: %d\n Defense: %d\n",
    e.title, e.e_health, e.e_attack, e.e_defense);

    while(running) {
        // bool player_turn = determine_turn(&p, &e);

        switch (state) {
            case DUNGEON_MODE:
                state = dungeon_run();
                break;
            case BATTLE_MODE:
                state = battle_run(&p, &e, battle_options, NUM_BATTLE_OPTIONS);
                break;
            case GAME_OVER:
                printf("Oops, you died!\n");
                running = false;
                break;
            default:
                printf("Game mode not found. quitting.\n");
                running = false;
        }
    }

    return 0;
}