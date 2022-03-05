//
// Created by lukas on 18.02.2022.
//

#include <iostream>
#include "trainer.h"
#include "rival.h"

void Trainer::initTrainer(const std::string& name, int level) {
    this->name = name;
    this->level = level;

    for (int i = 0; i < (sizeof(this->storage)/sizeof(this->storage[0])); ++i) {
        this->storage[i].initPokemon();
    }
}

bool Trainer::fight(const int trainerIndex, Rival *rival, const int rivalIndex) {

    Pokemon* ownPokemon = this->getPokemon(trainerIndex);
    Pokemon* rivalPokemon = rival->getPokemon(rivalIndex);

    std::cout << this->name << " callenges " << rival->getName() << " to a fight!" << std::endl;
    std::cout << this->name << " chooses " << ownPokemon->getName() << std::endl;
    std::cout << rival->getName() << " chooses " << rivalPokemon->getName() << std::endl;

    while(ownPokemon->getHitpoints() > 0 &&
            rivalPokemon->getHitpoints() > 0){

        ownPokemon->attack(rivalPokemon);

        if(rivalPokemon->getHitpoints() > 0){
            rivalPokemon->attack(ownPokemon);
        }

    }

    return ownPokemon->getHitpoints() > 0;
}

void Trainer::showStorage() const {

    std::cout << "-------------------" << std::endl;
    std::cout << this->getName() <<  " has the following pokemon to choose from: " << std::endl;

    // durchitterieren der vorhandenen Pokemon, Ausgabe nur wenn Pokemon gefangen ist.
    for (int i = 0; i < (sizeof(this->storage)/sizeof(this->storage[0])); ++i) {
        if(this->storage[i].isIsCaught()){
            std::cout << i << " - " << this->storage[i].getName() << "   hp: " << this->storage[i].getHitpoints()<< std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
}

int Trainer::addPokemon(const Pokemon& pokemon){
    for (int i = 0; i < 8; ++i) {
        if(!storage[i].isIsCaught()){
            storage[i] = pokemon;
            return i;
        }
    }
    return -1;
}

void Trainer::choosePokemon(int& index){

    index = -1;

    this->showStorage();

    while(index < 0 || index >= 8 || !this->storage[index].isIsCaught()){
        std::cout << "Choose your fighter (index): ";
        std::cin >> index;
        if(index < 0 || index >= 8 || !this->storage[index].isIsCaught()){
            std::cout << "Wrong input, please try again!" << std::endl;
        }
    }
}

// Getter & Setter

const std::string &Trainer::getName() const {
    return name;
}

Pokemon *Trainer::getPokemon(int index){

    Pokemon& poke = this->storage[index];

    return &poke;
}

