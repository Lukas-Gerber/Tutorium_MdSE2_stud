//
// Created by lugerber on 16.03.2022.
//

#include "icepokemon.h"

void Icepokemon::attack(Pokemon *enemy) {
    int rand = std::rand() % 4;
    auto a = this->getAttack(rand);

    int damage;

    // Ternary expression => condition ? expression if true : expression if false
    (enemy->getEnumType() == Water && a->getDamageType() == Ice) ? damage = a->getDamage() * 2 : damage = a->getDamage();


    std::cout << *this << " hits " << *enemy << " with " << a->getName()
              << " for " << damage << " damage." << std::endl;

    enemy->setHitpoints(enemy->getHitpoints() - damage);
}

Type &Icepokemon::getEnumType() {
    return enumType;
}