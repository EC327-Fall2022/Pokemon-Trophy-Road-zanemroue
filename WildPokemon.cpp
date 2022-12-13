#include "WildPokemon.h"
using namespace std;

WildPokemon::WildPokemon(string in_name, double in_attack, double in_health, bool in_variant, int in_id, Point2D in_loc, char in_code) : GameObject() {
    attack = in_attack;
    health = in_health;
    variant = in_variant;
    in_combat = false;
    name = in_name;
    id_num = in_id;
    location = in_loc;
    state = IN_ENVIORNMENT;
    display_code = in_code;
    speed = 3;
}

void WildPokemon::follow(Trainer* trainer) {
    if(state != DEAD && (trainer->GetState()==MOVING || trainer->GetState() == MOVING_TO_CENTER || trainer->GetState() == MOVING_TO_GYM)){
    if((abs((int)trainer->GetLocation().x - (int)location.x))<=1 && abs(((int)trainer->GetLocation().y - (int)location.y)) <= 1){
        location = trainer->GetLocation();
        health = health - 1;
        trainer->battlingWild(attack);
        state = IN_TRAINER;
    }else if(abs(((int)trainer->GetLocation().x - (int)location.x))<=2 && abs(((int)trainer->GetLocation().y - (int)location.y)) <=2){
        Point2D destination = trainer->GetLocation();
        delta = (destination - location)*(speed/GetDistanceBetween(destination,location));
        location = location + delta;
        state = FOLLOWING;
    }else{
        state = IN_ENVIORNMENT;
    }
    }
}

bool WildPokemon::get_variant() {
    return variant;
}

double WildPokemon::get_attack() {
    return attack;
}

double WildPokemon::get_health() {
    return health;
}

bool WildPokemon::get_in_combat() {
    return in_combat;
}

bool WildPokemon::Update() {
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

void WildPokemon::ShowStatus() {
    cout << "Wild Pokemon status:" << endl;
    GameObject::ShowStatus();
    switch (state) {
        case IN_ENVIORNMENT:
            cout << "The wild Pokemon is in the environment." << endl;
            break;
        case DEAD:
            cout << "The wild Pokemon is dead!" << endl;
            break;
        case FOLLOWING:
            cout << "The wild Pokemon is following a trainer!" << endl;
            break;
        case IN_TRAINER:
            cout<<"The wild Pokemon is attacking a trainer!"<<endl;
            break;
    }
}

bool WildPokemon::IsAlive() {
    if (health == 0) {
        return false;
    } else {
        return true;
    }
}

bool WildPokemon::ShouldBeVisible(){
    if (health != 0){
        return true;
    }else{
        return false;
    }
}
