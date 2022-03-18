//
// Created by lukas on 18.03.2022.
//

#include "attack.h"

void Attack::initAttack(const std::string &name, int damage) {

    this->name = name;
    this->damage = damage;
    this->isKnown = true;

}

void Attack::initAttack() {

    this->isKnown = false;

}

const std::string &Attack::getName() const {
    return name;
}

int Attack::getDamage() const {
    return damage;
}

bool Attack::isIsKnown() const {
    return isKnown;
}
