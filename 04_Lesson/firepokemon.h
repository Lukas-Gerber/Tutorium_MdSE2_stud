//
// Created by lukas on 19.03.2022.
//

#pragma once


#include <iostream>
#include "pokemon.h"

class Firepokemon : public Pokemon{

private:
    Type enumType;
public:

    Firepokemon(const std::string &name, int level, int hitpoints, int pokedexNumber)
            : Pokemon(name, level, hitpoints, pokedexNumber),enumType(Fire)  {
        std::cout << "Calling Firepokemon::Constructor" << std::endl;
    }

    virtual ~Firepokemon() {
        std::cout << "Calling Firepokemon::Destructor" << std::endl;
    }

    virtual void attack(Pokemon* enemy) override;

    virtual Type &getEnumType() override;


};



