#include "LegendaryPokemon.h"

LegendaryPokemon::LegendaryPokemon(string in_name, double in_attack, double in_health, bool in_variant, int in_id, Point2D in_loc, bool fly, char in_code) : WildPokemon(in_name, in_attack, in_health, in_variant, in_id, in_loc, in_code) {
    can_fly = fly;
}

bool LegendaryPokemon::GetCanFly() {
    return can_fly;
}

void LegendaryPokemon::UseSpecialAttack() {
    srand(time(0));
    attack = int(4 + rand() % 4);
}

void LegendaryPokemon::ShowStatus() {
    WildPokemon::ShowStatus();
    cout << "This legendary Pokémon has the following additional attributes:" << endl;
    cout << "Can fly" << endl;
    cout << "Has special attack" << endl;
}

bool LegendaryPokemon::Update(){
    if(health == 0){
        state = DEAD;
        return false;
    }
    else if (state == IN_TRAINER) {
        return true;
    }else if(state == FOLLOWING){
        return true;
    }
    else {
        state = IN_ENVIORNMENT;
        return true;
    }
}

void LegendaryPokemon::follow(Trainer*trainer){
    if(state != DEAD && (trainer->GetState()==MOVING || trainer->GetState() == MOVING_TO_CENTER || trainer->GetState() == MOVING_TO_GYM)){
    if((abs((int)trainer->GetLocation().x - (int)location.x))<=1 && abs(((int)trainer->GetLocation().y - (int)location.y)) <= 1){
        location = trainer->GetLocation();
        health = health - 1;
        trainer->battlingWild(attack);
        state = IN_TRAINER;
    }else if(abs(((int)trainer->GetLocation().x - (int)location.x))<=4 && abs(((int)trainer->GetLocation().y - (int)location.y)) <=4){
        Point2D destination = trainer->GetLocation();
        delta = (destination - location)*(speed/GetDistanceBetween(destination,location));
        location = location + delta;
        state = FOLLOWING;
    }else{
        state = IN_ENVIORNMENT;
    }
    }
}