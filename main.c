#include "src/player.h"
#include "src/enemy.h"
#include "src/battle.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));

    Player p;
    Enemy e;

    init_player(&p);
    init_rand_enemy(&e);

    // testing purposes
    printf("Player Name: %s\n Level: %d\n Health: %d\n Attack: %d\n Defense: %d\n Mp: %d\n", p.name,
    p.level, p.health, p.attack, p.defense, p.mp);

    printf("Enemy Title: %s\n Health: %d\n Attack: %d\n Defense: %d\n",
    e.title, e.e_health, e.e_attack, e.e_defense);

    // just like python, do not overcomplicate
    bool player_turn = determine_turn(&p, &e);

    while (player_turn) {
        print_battle_options(battle_options, NUM_BATTLE_OPTIONS);
        int option_choice = player_select(battle_options, NUM_BATTLE_OPTIONS);

        switch(option_choice) {
            case 0:
                player_attack(&p, &e);
                player_turn = false;
                break;
            case 1:
                printf("Run sp attack (mp) func here..\n");
                player_turn = false;
                break;
            case 2:
                printf("Run item use func here..\n");
                player_turn = false;
                break;
            case 3:
                player_run(&p);
                break;
            default:
                printf("Invalid choice selected.\n");
        }
        break;
    }
    while (!player_turn) {
        enemy_attack(&p, &e);
        break;
    }

    return 0;
}