//
// Created by lugerber on 09.03.2022.
//

#ifndef LESSON_3_ATTACK_H
#define LESSON_3_ATTACK_H

#include <iostream>
#include <string>
#include "type.h"

class Attack {
private:
    std::string name;
    Type damageType;
    int damage;
    bool isKnown;

public:

    Attack(const std::string &name, const Type &damageType, int damage)
            : name(name), damageType(damageType), damage(damage), isKnown(true) {

        // std::cout << "calling Attack::Construct(): " + name << std::endl;
    }

    ~Attack(){
        // std::cout << "calling Attack::Destructor(): " + name << std::endl;
    }

    const std::string &getName() const;

    int getDamage() const;

    bool isIsKnown() const;

    Type getDamageType() const;


};

#endif //LESSON_3_ATTACK_H
