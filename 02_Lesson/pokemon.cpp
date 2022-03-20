//
// Created by lukas on 18.02.2022.
//

#include <iostream>
#include "pokemon.h"

void Pokemon::initPokemon(const std::string& name, int level, int hitpoints,
                          const int pokedexNumber) {
    this->name = name;
    this->level = level;
    this->hitpoints = hitpoints;
    this->pokedexNumber = pokedexNumber;
    this->isCaught = true;

}

void Pokemon::initPokemon() {
    this->isCaught = false;
}

void Pokemon::attack(Pokemon *enemy) {
    int damage = 5 + std::rand() % 10; // Modulo beschränkt den Wertebereich der Rand Funktion
    // https://en.cppreference.com/w/cpp/numeric/random/rand

    std::cout << this->name << " hits " << enemy->getName() <<
              " for " << damage << std::endl;
    int hp = enemy->getHitpoints();
    enemy->setHitpoints(hp - damage);
    //std::cout << enemy->getName() << " HP after attack " << enemy->getHitpoints() << std::endl;
}

void Pokemon::levelUp() {
    this->level += 1;
    this->hitpoints += this->hitpoints * this->level;
    // aktuelle Hitpoints werden mit dem neuen Level multipliziert und hinzugezählt
    std::cout << this->name << " leveled up to " << this->level << " and has " <<
    this->hitpoints << " hitpoints left." << std::endl;
}


// Getter & Setter


const std::string &Pokemon::getName() const {
    return name;
}

int Pokemon::getHitpoints() const {
    return hitpoints;
}

void Pokemon::setHitpoints(int hitpoints) {
    this->hitpoints = hitpoints;
}

bool Pokemon::isIsCaught() const {
    return isCaught;
}


