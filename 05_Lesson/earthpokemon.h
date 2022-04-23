//
// Created by lukas on 19.03.2022.
//

#pragma once


#include <iostream>
#include "pokemon.h"

class Earthpokemon : public Pokemon{

private:
    Type enumType;
public:

    Earthpokemon(Game* parent,const std::string &name, int level, int hitpoints, int pokedexNumber)
            : Pokemon(parent, name, level, hitpoints, pokedexNumber), enumType(Earth) {
        std::cout << "Calling Earthpokemon::Constructor" << std::endl;
    }

    virtual ~Earthpokemon() {
        std::cout << "Calling Earthpokemon::Destructor" << std::endl;
    }

    virtual void attack(Pokemon* enemy) override;

    Type &getEnumType() override;

};



