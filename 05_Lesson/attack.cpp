//
// Created by lugerber on 09.03.2022.
//

#include "attack.h"

int Attack::getDamage() const {
    return damage;
}

bool Attack::isIsKnown() const {
    return isKnown;
}

const std::string &Attack::getName() const {
    return name;
}

Type Attack::getDamageType() const {
    return damageType;
}
