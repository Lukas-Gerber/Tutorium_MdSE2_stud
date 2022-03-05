//
// Created by lukas on 18.02.2022.
//

#ifndef LESSON_2_TRAINER_H
#define LESSON_2_TRAINER_H


#include <string>
#include "pokemon.h"

//Forward declaration
struct Rival;

class Trainer {

private:
    std::string name;
    int level;
    Pokemon storage[8];

public:

    void initTrainer(const std::string &name, int level);

    bool fight(int trainerIndex, Rival *rival, int rivalindex);

    void showStorage() const;

    int addPokemon(const Pokemon &pokemon);

    void choosePokemon(int &index);

    //Getter & Setter

    const std::string &getName() const;

    Pokemon *getPokemon(int index);
};


#endif //LESSON_2_TRAINER_H
