//
// Created by lukas on 18.02.2022.
//

#include <iostream>
#include "rival.h"

void Rival::initRival(const std::string &name, int level) {
    this->name = name;
    this->level = level;
    for (int i = 0; i < 8; ++i) {
        this->storage[i].initPokemon();

    }
}

int Rival::addPokemon(const Pokemon &pokemon) {
    for (int i = 0; i < 8; ++i) {
        if (!storage[i].isIsCaught()) {
            storage[i] = pokemon;
            return i;
        }
    }
    return -1;
}

void Rival::showStorage() {

    std::cout << "-------------------" << std::endl;
    std::cout << this->getName() << " has the following pokemon to choose from: " << std::endl;

    // durchitterieren der vorhandenen Pokemon, Ausgabe nur wenn Pokemon gefangen ist.
    for (int i = 0; i < (sizeof(this->storage) / sizeof(this->storage[0])); ++i) {
        if (this->storage[i].isIsCaught()) {
            std::cout << i << " - " << this->storage[i].getName() << "   hp: " << this->storage[i].getHitpoints()
                      << std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
}

void Rival::choosePokemon(int &index) {

    index = -1;

    this->showStorage();

    while (index < 0 || index >= 8 || !this->storage[index].isIsCaught()) {
        std::cout << "Choose your fighter (index): ";
        std::cin >> index;
        if (index < 0 || index >= 8 || !this->storage[index].isIsCaught()) {
            std::cout << "Wrong input, please try again!" << std::endl;
        }
    }
}

const std::string &Rival::getName() const {
    return name;
}

Pokemon *Rival::getPokemon(int index) {

    Pokemon &poke = this->storage[index];

    return &poke;
}
