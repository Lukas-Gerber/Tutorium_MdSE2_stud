//
// Created by lukas on 18.03.2022.
//

#ifndef LESSON_3_VORLAGE_POKEMON_H
#define LESSON_3_VORLAGE_POKEMON_H


#include <string>
#include <ostream>
#include "attack.h"
#include "type.h"


class Pokemon {

private:
    std::string name;
    int hitpoints;
    int level;
    int pokedexNumber;
    Attack storage[4];

public:

    Pokemon(const std::string &name, int level, int hitpoints, int pokedexNumber)
            : name(name), level(level), hitpoints(hitpoints), pokedexNumber(pokedexNumber) {

        std::cout << "Calling Pokemon::Constructor" << std::endl;
    }

    ~Pokemon() {};

    // Abstrakte Funktion = Funktion ohne implementierung, diese erfolgt in den Kindklassen
    virtual void attack(Pokemon *enemy) = 0;

    virtual Type &getEnumType() = 0;

    int addAttack(const Attack &attack);

    Attack *getAttack(int index);

    bool fight(Pokemon *rival);

    void levelUp();


    // Getter & Setter
    const std::string &getName() const;

    int getHitpoints() const;

    void setHitpoints(int hitpoints);

};

std::ostream& operator<<(std::ostream& out, const Pokemon& c);

#endif //LESSON_3_VORLAGE_POKEMON_H
