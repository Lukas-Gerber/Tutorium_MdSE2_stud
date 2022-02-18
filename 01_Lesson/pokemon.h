//
// Created by lukas on 11.02.2022.
//

#ifndef LESSON_1_POKEMON_H
#define LESSON_1_POKEMON_H


#include <string>

struct Pokemon_t {
    std::string name;
    int hitpoints;
    int level;
    int pokedexNumber;
    bool isCaught;

};

void initPokemon(Pokemon_t *pokemon, char *name, int level, int hitpoints, int pokedexNumber);

void initPokemon(Pokemon_t *pokemon);

void attack(Pokemon_t *pokemon, Pokemon_t *enemy);

void levelUp(Pokemon_t* pokemon);

#endif //LESSON_1_POKEMON_H
