//
// Created by lukas on 18.03.2022.
//

#ifndef LESSON_3_VORLAGE_POKEMON_H
#define LESSON_3_VORLAGE_POKEMON_H


#include <string>
#include <ostream>
#include "attack.h"


class Pokemon {

private:
    std::string name;
    int hitpoints;
    int level;
    int pokedexNumber;
    Attack storage[4];

public:

    void initPokemon(const std::string& name, int level, int hitpoints, int pokedexNumber);

    int addAttack(const Attack& attack);

    Attack* getAttack(int index);

    bool fight(Pokemon *rival);

    void attack(Pokemon *enemy);

    void levelUp();


    // Getter & Setter
    const std::string &getName() const;

    int getHitpoints() const;

    void setHitpoints(int hitpoints);


 };


#endif //LESSON_3_VORLAGE_POKEMON_H
