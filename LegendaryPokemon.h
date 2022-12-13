//Has more health, higher attack, special attack which changes its attack randomly, and says it can fly :)

#ifndef LEGENDARYPOKEMON_H
#define LEGENDARYPOKEMON_H
#include "WildPokemon.h"


class LegendaryPokemon : public WildPokemon {
    private:
    bool can_fly;
    int special_attack;

    public:
    LegendaryPokemon(string, double, double, bool, int, Point2D, bool, char);
    bool GetCanFly();
    void UseSpecialAttack();
    void ShowStatus();
    bool Update();
    void follow(Trainer*);
};

#endif