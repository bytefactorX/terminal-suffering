// heart of game's logic occurs here

#include "battle.h"
#include "player.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *battle_options[NUM_BATTLE_OPTIONS] = {
    "Attack",
    "Sp Attack", // uses MP 
    "Item",
    "Run"
};

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

// TODO: figure out cleaner print
void print_battle_options(char *battle_options[], int count) {
    // decays down to char**, need to use a count
    for (int i = 0; i < count; i++) {
        printf("%s \n", battle_options[i]);
    }
}

// TODO: add case-insensitive compare
int player_select(char *battle_options[], int count) {
    char choice_buff[50];

    printf("Decide carefully. $ ");
    fgets(choice_buff, sizeof(choice_buff), stdin);

    // strip newline
    choice_buff[strcspn(choice_buff, "\n")] = 0;

        for (int i = 0; i < count; i++) {
        if (strcmp(choice_buff, battle_options[i]) == 0) {
            printf("Option selected: %s\n", battle_options[i]);
            return i;
        }
    }
    return -1;  // no option found
}

void player_attack(Player *p, Enemy *e) {    
    int crit_chance = rand() % 10;

    if (crit_chance == 0) {
        int crit_value = calc_crit_dmg(p);
        e->e_health -= crit_value;
        printf("[CRITICAL] %s did %d damage to %s!\n", p->name, crit_value, e->title);
    }
    else {
        e->e_health -= p->attack;
        printf("%s did %d damage to %s!\n", p->name, p->attack, e->title);
    }

    if (e->e_health <= 0) {
        printf("Enemy %s has died. %s wins!\n", e->title, p->name);
    }
}

void player_run(Player *p) {
    printf("%s was too much of a coward and flaked out. 0 exp gained.\n", p->name);
}

void enemy_attack(Player *p, Enemy *e) {
    if (p->health <= 0) {
        printf("%s tried hard, but not hard enough.\n", p->name);
    }
    else {
        p->health -= e->e_attack;
        printf("Enemy %s did %d damage to %s!\n", e->title, e->e_attack, p->name);
    }
}