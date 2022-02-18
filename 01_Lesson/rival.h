//
// Created by lukas on 11.02.2022.
//

#ifndef LESSON_1_RIVAL_H
#define LESSON_1_RIVAL_H


#include <string>
#include "pokemon.h"
#include "trainer.h"


//Forward declaration
struct Trainer_t;

struct Rival_t {
    std::string name;
    int level;
    Pokemon_t storage[8];
};

void initRival(Rival_t *rival, char *name, int level);

#endif //LESSON_1_RIVAL_H
