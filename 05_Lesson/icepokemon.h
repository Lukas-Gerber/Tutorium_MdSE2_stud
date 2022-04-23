//
// Created by lugerber on 16.03.2022.
//

#ifndef LESSON_3_ICEPOKEMON_H
#define LESSON_3_ICEPOKEMON_H


#include <iostream>
#include "Waterpokemon.h"

class Icepokemon : public Waterpokemon{

private:
    Type enumType;
public:

    Icepokemon(Game* parent,const std::string &name, int level, int hitpoints, int pokedexNumber)
            : Waterpokemon(parent, name, level, hitpoints, pokedexNumber), enumType(Ice) {
        std::cout << "Calling icepokemon::Constructor" << std::endl;
    }

    virtual ~Icepokemon() {
        std::cout << "Calling icepokemon::Destructor" << std::endl;
    }

    virtual void attack(Pokemon* enemy) override;

    Type &getEnumType() override;

};


#endif //LESSON_3_ICEPOKEMON_H
