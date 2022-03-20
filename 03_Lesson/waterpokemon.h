//
// Created by lukas on 19.03.2022.
//

#pragma once


#include <iostream>
#include "pokemon.h"

class Waterpokemon : public Pokemon {
private:
    Type enumType;


public:
    Waterpokemon(const std::string &name, int level, int hitpoints, int pokedexNumber)
            : Pokemon(name, level, hitpoints, pokedexNumber), enumType(Water)
            {
        std::cout << "Calling waterpokemon::Constructor" << std::endl;
    }

    virtual ~Waterpokemon() {
        std::cout << "Calling waterpokemon::Destructor" << std::endl;
    }

    virtual void attack(Pokemon* enemy) override;

    virtual Type &getEnumType() override;


};



