#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include "Building.h"

class PokemonCenter : public Building {
    enum PokemonCenterStates {
        POTIONS_AVAILABLE = 0,
        NO_POTIONS_AVAILABLE = 1
    };

    public:
    PokemonCenter();
    PokemonCenter(int, double, unsigned int, Point2D);
    ~PokemonCenter();
    bool HasPotions();
    unsigned int GetNumPotionsRemaining();
    void SetNumPotionsRemaining(unsigned int); // added setter
    bool CanAffordPotion(unsigned int, double);
    double GetPokeDollarCost(unsigned int);
    unsigned int DistributePotion(unsigned int);
    bool Update();
    void ShowStatus();


    private:
    unsigned int potion_capacity;
    unsigned int num_potions_remaining;
    double pokedollar_cost_per_potion;

};

#endif