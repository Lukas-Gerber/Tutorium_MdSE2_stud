//
// Created by lukas on 18.02.2022.
//

#ifndef LESSON_2_RIVAL_H
#define LESSON_2_RIVAL_H


#include <string>
#include "pokemon.h"
#include "trainer.h"

class Rival {
private:

    std::string name;
    int level;
    Pokemon storage[8];

public:
    void initRival(const std::string& name, int level);

    int addPokemon(const Pokemon& pokemon);

    void showStorage();

    void choosePokemon(int& index);

    // Getter & Setter

    const std::string &getName() const;

    Pokemon *getPokemon(int index);
};


#endif //LESSON_2_RIVAL_H
