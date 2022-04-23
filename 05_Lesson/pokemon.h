//
// Created by lukas on 18.02.2022.
//

#ifndef LESSON_2_POKEMON_H
#define LESSON_2_POKEMON_H


#include <string>
#include <memory>
#include <vector>
#include "attack.h"
#include "type.h"
#include "exception.h"
#include "game.h"

class Pokemon {

protected:

    std::string name;
    int hitpoints;
    int level;
    int pokedexNumber;
    std::vector<std::shared_ptr<Attack>> storage;
    Game *parent;

public:

    Pokemon(Game *parent, const std::string &name, int level, int hitpoints, int pokedexNumber) :
            parent(parent), name(name), level(level), hitpoints(hitpoints), pokedexNumber(pokedexNumber),
            storage() { // storage() = init storage mit NULL


        if (name.size() == 0) {
            throw InvalidArgument("Pokemon::Pokemon: Empty string");
        }
        if (level < 0 || hitpoints < 0 || pokedexNumber < 0) {
            throw InvalidArgument("Pokemon::Pokemon: Negative value");
        }
    }

    virtual ~Pokemon() {};

    // Abstrakte Funktion = Funktion ohne implementierung, die Implementierung erfolgt in den Kindklassen
    virtual void attack(Pokemon *enemy) = 0;

    virtual Type &getEnumType() = 0;

    int addAttack(std::shared_ptr<Attack> attack);

    std::shared_ptr<Attack> removeAttack(int slot);

    bool fight(Pokemon *rival);

    void levelUp();

    std::shared_ptr<Attack> getAttack(int index);

    // Getter & Setter

    const std::string &getName() const;

    int getHitpoints() const;

    void setHitpoints(int hitpoints);

};

std::ostream &operator<<(std::ostream &out, const Pokemon &c);

#endif //LESSON_2_POKEMON_H
