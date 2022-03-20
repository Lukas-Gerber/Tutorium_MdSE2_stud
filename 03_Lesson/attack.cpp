//
// Created by lukas on 18.03.2022.
//

#include "attack.h"

const std::string &Attack::getName() const {
    return name;
}

int Attack::getDamage() const {
    return damage;
}

bool Attack::isIsKnown() const {
    return isKnown;
}

Type Attack::getDamageType() const {
    return damageType;
}
