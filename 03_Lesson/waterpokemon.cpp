//
// Created by lukas on 19.03.2022.
//

#include "waterpokemon.h"

void Waterpokemon::attack(Pokemon *enemy) {

    int rand = std::rand() % 4;
    Attack *a = this->getAttack(rand);

    int damage;

    // Zur Erinnerung Enum:
    // Fire = 0
    // Water = 1
    // Earth = 2
    // Ice = 3

    if(enemy->getEnumType() == Fire && a->getDamageType() == Water){
        damage = a->getDamage() * 2;
    } else {
        damage = a->getDamage();
    }

    // Ternary expression => condition ? expression if true : expression if false
    // (enemy->getEnumType() == 0 && a->getDamageType() == 1) ? damage = a->getDamage() * 2 : damage = a->getDamage();


    std::cout << *this << " hits " << *enemy << " with " << a->getName()
              << " for " << damage << " damage." << std::endl;

    enemy->setHitpoints(enemy->getHitpoints() - damage);

}

Type &Waterpokemon::getEnumType() {
    return enumType;
}
