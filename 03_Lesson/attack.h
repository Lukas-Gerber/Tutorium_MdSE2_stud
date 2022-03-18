//
// Created by lukas on 18.03.2022.
//

#pragma once


#include <string>

class Attack {


private:
    std::string name;
    int damage;
    bool isKnown;

public:

    void initAttack(const std::string& name, int damage);

    void initAttack();

    const std::string &getName() const;

    int getDamage() const;

    bool isIsKnown() const;


};



