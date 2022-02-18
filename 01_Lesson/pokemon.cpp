//
// Created by lukas on 11.02.2022.
//

#include <iostream>
#include "pokemon.h"

void initPokemon(Pokemon_t *pokemon, char *name, int level, int hitpoints, int pokedexNumber) {
    pokemon->name = name;
    pokemon->level = level;
    pokemon->hitpoints = hitpoints;
    pokemon->pokedexNumber = pokedexNumber;
    pokemon->isCaught = true;
}

void initPokemon(Pokemon_t *pokemon) {
    pokemon->isCaught = false;
}

void levelUp(Pokemon_t* pokemon){
    pokemon->level += 1;
    pokemon->hitpoints += pokemon->hitpoints * pokemon->level;
    // aktuelle Hitpoints werden mit dem neuen Level multipliziert und hinzugezählt
    std::cout << pokemon->name << " leveled up to " << pokemon->level << " and has " <<
              pokemon->hitpoints << " hitpoints left." << std::endl;

}

void attack(Pokemon_t *trainer, Pokemon_t *enemy) {
    int damage = 1 + std::rand() % 5; // Modulo beschränkt den Wertebereich der Rand Funktion
    // https://en.cppreference.com/w/cpp/numeric/random/rand

    std::cout << trainer->name << " hits " << enemy->name <<
              " for " << damage << std::endl;
    enemy->hitpoints -= damage;
}
