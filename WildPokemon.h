//WildPokemon only start moving towrds you when you get within 2 points away from them. They move towards you with a set speed.

#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H

#include <string>
#include <iostream>
#include "Trainer.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <cstdlib>
#include <ctime>

class WildPokemon : public GameObject {
    protected:
    double attack;
    double speed;
    double health;
    bool variant;
    bool in_combat;
    Vector2D delta;
    string name;
    Trainer* current_trainer;
    
    public:
    WildPokemon(string, double, double, bool, int, Point2D, char);
    virtual void follow(Trainer*);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    virtual bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();

};

enum WildPokemonStates
{
    IN_ENVIORNMENT = 0,
    DEAD = 1,
    FOLLOWING = 2,
    IN_TRAINER = 3,
};

#endif