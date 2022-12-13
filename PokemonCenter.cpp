#include "PokemonCenter.h"

PokemonCenter::PokemonCenter(){
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    std::cout<<"PokemonCenter default constructed"<<endl;
}

PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc):Building('C',in_id,in_loc){
    id_num = in_id;
    location = in_loc;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    num_potions_remaining = potion_capacity;
    std::cout<<"PokemonCenter constructed"<<endl;
    state = POTIONS_AVAILABLE;
}

bool PokemonCenter::HasPotions(){
    if(num_potions_remaining > 0){
        return true;
    }
    display_code = 'c';
    return false;
}

unsigned int PokemonCenter::GetNumPotionsRemaining(){
    return num_potions_remaining;
}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget){
    if (budget > (potion*pokedollar_cost_per_potion)){
        return true;
    }else{
        return false;
    }
}
double PokemonCenter::GetPokeDollarCost(unsigned int potion){
    return potion*pokedollar_cost_per_potion;
}

unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed){
    unsigned int returnPotions;
    if (num_potions_remaining >= potion_needed){
        num_potions_remaining = num_potions_remaining - potion_needed;
        returnPotions = potion_needed;
    }else{
        returnPotions = num_potions_remaining;
        num_potions_remaining = 0;
    }
    return returnPotions;
}

bool PokemonCenter::Update(){
    if(state == POTIONS_AVAILABLE && num_potions_remaining == 0){
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        std::cout<<"PokemonCenter ("<<id_num<<") has ran out of potions"<<endl;
        return true;
    }
    return false;
}

void PokemonCenter::ShowStatus(){
    std::cout<<"PokemonCenter Status: "<<endl;
    Building::ShowStatus();
    if (num_potions_remaining == 1){
    std::cout<<"Has ("<<num_potions_remaining<<") potion remaining"<<endl;
    }else{
    std::cout<<"Has ("<<num_potions_remaining<<") potions remaining"<<endl;
    }
    std::cout<<"PokeDollars per potion: ("<<pokedollar_cost_per_potion<<")"<<endl;
    std::cout<<endl;
}

PokemonCenter::~PokemonCenter(){
    cout<<"PokemonCenter Destructed"<<endl;
}


