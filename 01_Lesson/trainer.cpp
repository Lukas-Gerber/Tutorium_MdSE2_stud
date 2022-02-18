//
// Created by lukas on 11.02.2022.
//

#include <iostream>
#include <cstdlib>
#include "trainer.h"
#include "rival.h"

void initTrainer(Trainer_t *trainer, char *name, int level) {
    trainer->name = name;
    trainer->level = level;

    for (int i = 0; i < (sizeof(trainer->storage)/sizeof(trainer->storage[0])); ++i) {
        initPokemon(&trainer->storage[i]);
    }
}

/*void attack(Pokemon_t *trainer, Pokemon_t *enemy) {
    int damage = 1 + std::rand() % 5; // Modulo beschränkt den Wertebereich der Rand Funktion
    // https://en.cppreference.com/w/cpp/numeric/random/rand

    std::cout << trainer->name << " hits " << enemy->name <<
              " for " << damage << std::endl;
    enemy->hitpoints -= damage;
}*/


bool fight(Trainer_t *trainer, const int trainerIndex, Rival_t *rival, const int rivalindex) {
    std::cout << trainer->name << " callenges " << rival->name << " to a fight!" << std::endl;
    std::cout << trainer->name << " chooses " << trainer->storage[trainerIndex].name << std::endl;
    std::cout << rival->name << " chooses " << rival->storage[rivalindex].name << std::endl;

    while (trainer->storage[trainerIndex].hitpoints > 0 && rival->storage[rivalindex].hitpoints > 0) {
        attack(&trainer->storage[trainerIndex], &rival->storage[rivalindex]);
        if (rival->storage[rivalindex].hitpoints > 0) {
            attack(&rival->storage[rivalindex], &trainer->storage[trainerIndex]);
        }
    }
    return trainer->storage[trainerIndex].hitpoints > 0;

}

void showStorage(const Trainer_t *trainer) {
    int index = 0;
    std::cout << "-------------------" << std::endl;
    std::cout << "You have the following pokemon to choose from: " << std::endl;

    // durchitterieren der vorhandenen Pokemon, Ausgabe nur wenn Pokemon gefangen ist.
    for (int i = 0; i < (sizeof(trainer->storage)/sizeof(trainer->storage[0])); ++i) {
        if(trainer->storage[i].isCaught){
            std::cout << i << " - " << trainer->storage[i].name << "   hp: " << trainer->storage[i].hitpoints<< std::endl;
        }
    }

    // würde mit einer range based for loop wie folgt aussehen
/*    for (const Pokemon_t &poke: trainer->storage) {
        if (poke.isCaught) {
            std::cout << index << " - " << poke.name << "   hp: " << poke.hitpoints<< std::endl;
        }
        index++;
    }*/

    std::cout << "-------------------" << std::endl;
}

