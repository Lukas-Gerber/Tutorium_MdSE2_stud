//
// Created by lukas on 11.02.2022.
//

#ifndef LESSON_1_TRAINER_H
#define LESSON_1_TRAINER_H


#include <string>
#include "pokemon.h"

//Forward declaration
struct Rival_t;

struct Trainer_t {
    std::string name;
    int level;
    Pokemon_t storage[8];
};

void initTrainer(Trainer_t *trainer, char *name, int level);

bool fight(Trainer_t *trainer, const int trainerIndex, Rival_t *rival, const int rivalindex);

void showStorage(const Trainer_t *trainer);

#endif //LESSON_1_TRAINER_H
