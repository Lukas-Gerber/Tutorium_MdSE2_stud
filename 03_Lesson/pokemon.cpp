//
// Created by lukas on 18.03.2022.
//

#include <iostream>
#include "pokemon.h"

void Pokemon::initPokemon(const std::string &name, int level, int hitpoints,
                          const int pokedexNumber) {
    this->name = name;
    this->level = level;
    this->hitpoints = hitpoints;
    this->pokedexNumber = pokedexNumber;

    for (int i = 0; i < (sizeof(this->storage) / sizeof(this->storage[0])); i++) {
        this->storage[i].initAttack();
    }

}

int Pokemon::addAttack(const Attack &attack) {
    for (int i = 0; i < (sizeof(this->storage) / sizeof(this->storage[0])); i++) {
        if (!storage[i].isIsKnown()) {
            storage[i] = attack;
            return i;
        }
    }
    return -1;
}

bool Pokemon::fight(Pokemon *rival) {

    std::cout << this->name << " challenges " << rival->getName() << " to a fight!" << std::endl;

    while (this->getHitpoints() > 0 &&
           rival->getHitpoints() > 0) {

        this->attack(rival);

        if (rival->getHitpoints() > 0) {
            rival->attack(this);
        }
    }

    return this->getHitpoints() > 0;
}


void Pokemon::attack(Pokemon *enemy) {
    int rand = std::rand() % 4;
    Attack *a = this->getAttack(rand);

    int damage = a->getDamage();

    std::cout << this->name << " hits " << enemy->getName() << " with "
              << a->getName() << " for " << damage << std::endl;

    enemy->setHitpoints(enemy->getHitpoints() - damage);
}

void Pokemon::levelUp() {
    this->level += 1;
    this->hitpoints += this->hitpoints * this->level;
    // aktuelle Hitpoints werden mit dem neuen Level multipliziert und hinzugezählt
    std::cout << this->name << " leveled up to " << this->level << " and now has " <<
              this->hitpoints << " hitpoints." << std::endl;
}

const std::string &Pokemon::getName() const {
    return name;
}

int Pokemon::getHitpoints() const {
    return hitpoints;
}

void Pokemon::setHitpoints(int hitpoints) {
    this->hitpoints = hitpoints;
}

Attack *Pokemon::getAttack(int index) {
    Attack &attack = this->storage[index];
    return &attack;
}



