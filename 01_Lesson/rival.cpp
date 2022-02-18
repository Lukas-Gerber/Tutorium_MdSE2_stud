//
// Created by lukas on 11.02.2022.
//

#include <iostream>
#include "rival.h"
#include "trainer.h"

void initRival(Rival_t *rival, char *name, int level) {
    rival->name = name;
    rival->level = level;
    for (int i = 0; i < 8; ++i) {
        initPokemon(&rival->storage[i]);
    }
}

