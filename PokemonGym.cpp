#include "PokemonGym.h"
#include <iostream>

PokemonGym::PokemonGym() : Building() {
    display_code = 'G';
    state = NOT_DEFEATED;
    max_number_of_battles = 10;
    num_battle_remaining = max_number_of_battles;
    health_cost_per_battle = 1.0;
    experience_per_battle = 2;
    std::cout << "PokemonGym default constructed." << endl;
}

PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, 
double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc) : Building() {
    id_num = in_id;
    max_number_of_battles = max_battle;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    location = in_loc;
    display_code = 'G';
    num_battle_remaining = max_number_of_battles;
    std::cout << "PokemonGym constructed" << endl;
}

PokemonGym::~PokemonGym() {
    std::cout << "PokemonGym destructed." << endl;
}

double PokemonGym::GetPokeDollarCost(unsigned int battle_qty) {
    return PokeDollar_cost_per_battle * battle_qty;
}

unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty) {
    return health_cost_per_battle * battle_qty;
}

unsigned int PokemonGym::GetNumBattlesRemaining() {
    return num_battle_remaining;
}

void PokemonGym::SetNumBattlesRemaining(unsigned int battle_qty) { // added setter
    num_battle_remaining = battle_qty;
}

bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) {
    if (budget < GetPokeDollarCost(battle_qty))
        return false;
    else if (health < GetHealthCost(battle_qty))
        return false;
    else
        return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int battle_units) {
    int x;
    if (battle_units > num_battle_remaining) {
        x = num_battle_remaining;
        num_battle_remaining = 0;
        return x * num_battle_remaining;
    }
    else
        num_battle_remaining -= battle_units;
        return battle_units = experience_per_battle;
}


unsigned int PokemonGym::GetExperiencePerBattle() {
    return (max_number_of_battles-num_battle_remaining) * experience_per_battle;
}

bool PokemonGym::Update() {
    if (passed() == true) {
        return false;
    }
    else if (num_battle_remaining == 0) {
        state = DEFEATED;
        display_code = 'g';
        std::cout << display_code << id_num << " has been beaten" << endl;
        return true;
    }
    else
        return false;
}

bool PokemonGym::passed() {
    if (num_battle_remaining == 0)
        return true;
    else
        return false;
}

void PokemonGym::ShowStatus() {
    GameObject::ShowStatus();
    std::cout << "PokemonGymStatus:" << endl;
    std::cout << "Max number of battles: " << max_number_of_battles << endl;
    std::cout << "Health cost per battle: " << health_cost_per_battle << endl;
    std::cout << "PokeDollar per battle: " << PokeDollar_cost_per_battle << endl;
    std::cout << "Experience per battle: " << experience_per_battle << endl;
    std::cout << num_battle_remaining << " battle(s) are remaining for this PokemonGym" << endl<<endl;
}
