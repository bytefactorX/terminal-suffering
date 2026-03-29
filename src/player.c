#include "player.h"
#include <stdio.h>
#include <string.h>

// initialize starting values
void init_player(Player *p) {
    printf("Before your journey begins, please provide your name $ ");
    
    if (fgets(p->name, sizeof(p->name), stdin)) {
        p->name[strcspn(p->name, "\n")] = '\0';
    }
    else {
        strncpy(p->name, "no name", 23);
        p->name[23] = '\0';
    }
    p->health = 100;
    p->attack = 10;
    p->defense = 25;
    p->level = 1;
    p->exp = 0;
    p->mp = 5;
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

// TODO: actually implement (will need to handle input to determine
// what to upgrade )
void upgrade_player(Player *p) {
    return;
}

int calc_crit_dmg(Player *p) {
    float crit_mul = 1.5;
    int crit_value;
    crit_value = (p->attack + p->level) * crit_mul;

    return crit_value;
}