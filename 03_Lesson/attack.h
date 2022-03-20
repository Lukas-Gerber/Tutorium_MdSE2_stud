//
// Created by lukas on 18.03.2022.
//

#pragma once


#include <string>
#include "type.h"

class Attack {


private:
    std::string name;
    Type damageType;
    int damage;
    bool isKnown;

public:

    //Default Konstruktor
    Attack() : damage(0), isKnown(false) {}

    Attack(const std::string &name, const Type &damageType, int damage)
            : name(name), damageType(damageType), damage(damage), isKnown(true) {}



    const std::string &getName() const;

    int getDamage() const;

    bool isIsKnown() const;

    Type getDamageType() const;

};



