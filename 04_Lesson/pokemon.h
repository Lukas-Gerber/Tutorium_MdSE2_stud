//
// Created by lukas on 18.02.2022.
//

#ifndef LESSON_2_POKEMON_H
#define LESSON_2_POKEMON_H


#include <string>
#include "attack.h"
#include "type.h"
#include "exception.h"

class Pokemon {

protected:

    std::string name;
    int hitpoints;
    int level;
    int pokedexNumber;
    Attack* storage[4];

public:

    Pokemon(const std::string &name, int level, int hitpoints, int pokedexNumber) :
            name(name), level(level), hitpoints(hitpoints), pokedexNumber(pokedexNumber), storage() { // storage() = init storage mit NULL

        if (name.size() == 0) {
            throw InvalidArgument("Pokemon::Pokemon: Empty string");
        }
        if (level < 0 || hitpoints < 0 || pokedexNumber < 0) {
            throw InvalidArgument("Pokemon::Pokemon: Negative value");
        }
    }

    virtual ~Pokemon() {

        // Achtung, Attack-Objekte am Heap (new keyword) müssen bei der Zerstörung des Pokemon-Objektes ebenfalls zerstört werden!
        for (int i = 0; i < 4; ++i) {
            delete storage[i];
        }

    };

    // Abstrakte Funktion = Funktion ohne implementierung, die Implementierung erfolgt in den Kindklassen
    virtual void attack(Pokemon *enemy) = 0;

    virtual Type &getEnumType() = 0;

    int addAttack(Attack* attack);

    Attack* removeAttack(int slot);

    bool fight(Pokemon *rival);

    void levelUp();

    Attack *getAttack(int index);

    // Getter & Setter

    const std::string &getName() const;

    int getHitpoints() const;

    void setHitpoints(int hitpoints);

    bool isIsCaught() const;

};

std::ostream& operator<<(std::ostream& out, const Pokemon& c);

#endif //LESSON_2_POKEMON_H
