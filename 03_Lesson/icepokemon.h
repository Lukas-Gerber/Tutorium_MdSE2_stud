//
// Created by lukas on 19.03.2022.
//

#pragma once


#include <iostream>
#include "Waterpokemon.h"

class Icepokemon : public Waterpokemon{

private:
    Type enumType;
public:

    Icepokemon(const std::string &name, int level, int hitpoints, int pokedexNumber)
            : Waterpokemon(name, level, hitpoints, pokedexNumber), enumType(Ice) {
        std::cout << "Calling icepokemon::Constructor" << std::endl;
    }

    virtual ~Icepokemon() {
        std::cout << "Calling icepokemon::Destructor" << std::endl;
    }

    virtual void attack(Pokemon* enemy) override;

    Type &getEnumType() override;

};



