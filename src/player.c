#include "player.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// initialize starting values
void init_player(Player *p) {
    int a_min = 10;
    int a_max = 15;
    int d_min = 22;
    int d_max = 27;

    printf("Before your journey begins, please provide your name $ ");
    
    if (fgets(p->name, sizeof(p->name), stdin)) {
        p->name[strcspn(p->name, "\n")] = '\0';
    }
    else {
        strncpy(p->name, "no name", 23);
        p->name[23] = '\0';
    }
    p->health = 100;
    p->attack = (rand() % (a_max - a_min + 1)) + a_min;
    p->defense = (rand() % (d_max - d_min + 1)) + d_min;
    p->level = 1;
    p->exp = 0;
    p->mp = 5;
}

// super basic for now tbh 
void gain_exp(Player *p) {
    p->exp += 10;
}

// will want to add some logic handling to check if exp 
// is valid for level up
void level_up(Player *p) {
    p->level += 1;
    p->health += p->level + (p->level / 2);
    p->attack += p->level * 2;
    p->defense += p->level;
    p->mp +=1; 
}

int calc_crit_dmg(Player *p) {
    float crit_mul = 1.5;
    int crit_value;
    crit_value = (p->attack + p->level) * crit_mul;

    return crit_value;
}

void use_mp(Player *p) {
    p->mp -= 1;

    if (p->mp == 0) {
        printf("Out of MP!");
    }
}

// run everything if player wins
int player_win_sub(Player *p) {
    gain_exp(p);

    if (p->exp == 100) {
        level_up(p);
        return 1;
    }
    return 0;
}