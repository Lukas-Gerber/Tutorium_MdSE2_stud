//
// Created by lukas on 19.03.2022.
//

#include "waterpokemon.h"

void Waterpokemon::attack(Pokemon *enemy) {

    int rand = std::rand() % 4;

    Attack* a = this->getAttack(rand);

    int damage;

    if (enemy->getEnumType() == Fire && a->getDamageType() == Water) {
        damage = a->getDamage() * 2;
    } else {
        damage = a->getDamage();
    }

    std::cout << *this << " hits " << *enemy << " with " << a->getName()
              << " for " << damage << " damage." << std::endl;

    enemy->setHitpoints(enemy->getHitpoints() - damage);

}

Type &Waterpokemon::getEnumType() {
    return enumType;
}
