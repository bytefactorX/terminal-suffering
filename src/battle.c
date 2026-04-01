#include "battle.h"
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

// unused now
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

bool player_attack(Player *p, Enemy *e) {    
    int crit_chance = rand() % 10;

    if (crit_chance == 0) {
        int crit_value = calc_crit_dmg(p);
        e->e_health -= crit_value;
        printf("[CRITICAL] %s did %d damage to %s!\n", p->name, crit_value, e->title);
        print_battle_stats(p, e);
    }
    else {
        e->e_health -= p->attack;
        printf("%s did %d damage to %s!\n", p->name, p->attack, e->title);
        print_battle_stats(p, e);
    }

    if (e->e_health <= 0) {
        e->e_health = 0;
        printf("Enemy %s has died. %s wins!\n", e->title, p->name);

        printf("Returning to DUNGEON MODE.\n");
        return true;
    }

    printf("Returning to BATTLE MODE.\n");
    return false;
}

bool player_run(Player *p) {
    printf("%s was too much of a coward and flaked out. 0 exp gained.\n", p->name);

    printf("Running DUNGEON MODE here.\n");

    return true;
}

bool enemy_attack(Player *p, Enemy *e) {
    if (p->health <= 0) {
        p->health = 0;
        printf("%s tried hard, but not hard enough.\n", p->name);

        printf("Running GAME OVER mode here.\n");
        return true;
    }
    else {
        p->health -= e->e_attack;
        printf("Enemy %s did %d damage to %s!\n", e->title, e->e_attack, p->name);
        print_battle_stats(p, e);
    }

    return false;
}

// run everything
GameState battle_run(Player *p, Enemy *e, char *battle_options[], int count) {
    // always start with player turn (for now)
    bool player_turn = true;

    if (player_turn) {
        print_battle_options(battle_options, count);
        int player_choice = player_select(battle_options, count);

        switch(player_choice) {
            case 0:
                if (player_attack(p, e)) {
                    reset_enemy(e);
                    player_win_sub(p);
                    return DUNGEON_MODE;
                }
                break;
            case 1:
                printf("[DEV] Sp attack would be completed here\n");
                break;
            case 2:
                printf("[DEV] Item select would be implemented here\n");
                break;
            case 3:
                if (player_run(p)) {
                    reset_enemy(e);
                    return DUNGEON_MODE;
                }
                break;
            default:
                printf("[ERROR] No valid option selected.\n");
        }

        printf("Swapping to enemy turn\n");
        player_turn = false;

        if (enemy_attack(p, e)) {
            return GAME_OVER;
        }
    }

    else {
        if (enemy_attack(p, e)) {
            return GAME_OVER;
        }

        printf("Swapping to player turn\n");
        player_turn = true;
    }

    return BATTLE_MODE;
}