#include "output.h"
#include <stdio.h>
#include <unistd.h>

void init_game_text() {
    
}

void print_player_ststats(Player *p) {
    printf("Player Name: %s\n Level: %d\n Health: %d\n Attack: %d\n Defense: %d\n Mp: %d\n", p->name,
    p->level, p->health, p->attack, p->defense, p->mp);
}

void print_battle_stats(Player *p, Enemy *e) {
    printf("Player Name: %s\n Level: %d\n Health: %d\n Attack: %d\n Defense: %d\n Mp: %d\n", p->name,
    p->level, p->health, p->attack, p->defense, p->mp);

    printf("Enemy Title: %s\n Health: %d\n Attack: %d\n Defense: %d\n",
    e->title, e->e_health, e->e_attack, e->e_defense);
}

void print_player_expup(Player *p) {
    printf("Player %s gained exp!\n", p->name);
    printf("Player exp: %d\n", p->exp);
}

void print_player_lvlup(Player *p) {
    printf("Player Name: %s\n Level: %d\n Health: %d\n Attack: %d\n Defense: %d\n Mp: %d\n", p->name,
    p->level, p->health, p->attack, p->defense, p->mp);
}

void print_walking_cycle() {
    printf("Walking...\n");

    sleep(2);
}

