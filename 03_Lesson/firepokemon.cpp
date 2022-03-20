//
// Created by lukas on 19.03.2022.
//

#include "firepokemon.h"

void Firepokemon::attack(Pokemon *enemy) {
    int rand = std::rand() % 4;
    Attack *a = this->getAttack(rand);

    int damage;

    // Zur Erinnerung Enum:
    // Fire = 0
    // Water = 1
    // Earth = 2
    // Ice = 3

    // Ternary expression => condition ? expression if true : expression if false
    (enemy->getEnumType() == Earth && a->getDamageType() == Fire) ? damage = a->getDamage() * 2
                                                               : damage = a->getDamage();

    std::cout << *this << " hits " << *enemy << " with " << a->getName()
              << " for " << damage << " damage." << std::endl;

    enemy->setHitpoints(enemy->getHitpoints() - damage);
}

Type &Firepokemon::getEnumType() {
    return enumType;
}