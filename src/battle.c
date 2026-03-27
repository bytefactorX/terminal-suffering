// heart of game's logic occurs here

#include "battle.h"
#include "player.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool determine_turn(Player *p, Enemy *e) {
    bool player_turn;

    if ((p->health - p->defense) > e->e_health) {
        player_turn = true;
        printf("Player is going first!\n");
    }
    else {
        player_turn = false;
        printf("Enemy is going first!\n");
    }

    return player_turn;
}

char *battle_options[NUM_BATTLE_OPTIONS] = {
    "Attack",
    "Sp Attack", // uses MP 
    "Item",
    "Run"
};

// TODO: figure out cleaner print
void print_battle_options(char *battle_options[], int count) {
    // decays down to char**, need to use a count
    for (int i = 0; i < count; i++) {
        printf("%s \n", battle_options[i]);
    }
}

// TODO: add case-insensitive compare
void player_select(char *battle_options[], int count) {
    char choice_buff[50];
    int found = 0;

    printf("Decide carefully. >");
    fgets(choice_buff, sizeof(choice_buff), stdin);

    // strip newline
    choice_buff[strcspn(choice_buff, "\n")] = 0;

        for (int i = 0; i < count; i++) {
        if (strcmp(choice_buff, battle_options[i]) == 0) {
            printf("Option selected: %s\n", battle_options[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid option was selected.\n");
    }
    
}