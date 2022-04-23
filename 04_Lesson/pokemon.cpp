//
// Created by lukas on 18.02.2022.
//

#include <iostream>
#include "pokemon.h"


void Pokemon::levelUp() {
    this->level += 1;
    this->hitpoints += this->hitpoints * this->level;
    // aktuelle Hitpoints werden mit dem neuen Level multipliziert und hinzugezählt
    std::cout << this->name << " leveled up to level " << this->level << " and now has " <<
    this->hitpoints << " hitpoints." << std::endl;
}

int Pokemon::addAttack(Attack* attack) {
    for (int i = 0; i < 4; ++i) {
        if(!storage[i]){
            storage[i] = attack;
            return i;
        }
    }
    throw StorageFullException("Pokemon::addAttack(): storage full");
}

Attack* Pokemon::removeAttack(int slot) {
    if (slot < 0 || slot > 4) {
        throw InvalidIndexException("Character::removeInventarItem(): Invalid index");
    } else if (storage[slot]) {
        Attack* retval = storage[slot];
        storage[slot] = nullptr;
        return retval;
    } else {
        throw InvalidAttackException("Character::removeInventarItem(): Invalid item");
    }
}




bool Pokemon::fight(Pokemon *rival) {

    std::cout << this->name << " challenges " << rival->getName() << " to a fight!" << std::endl;

    while(this->getHitpoints() > 0 &&
            rival->getHitpoints() > 0){

        this->attack(rival);

        if(rival->getHitpoints() > 0){
            rival->attack(this);
        }
    }

    return this->getHitpoints() > 0;
}

Attack *Pokemon::getAttack(int index) {
    Attack* attack = this->storage[index];
    return attack;
}


// Getter & Setter


const std::string &Pokemon::getName() const {
    return name;
}

int Pokemon::getHitpoints() const {
    return hitpoints;
}

void Pokemon::setHitpoints(int hitpoints) {
    Pokemon::hitpoints = hitpoints;
}

bool Pokemon::isIsCaught() const {
    return false;
}

std::ostream& operator<<(std::ostream& out, const Pokemon& c) {
    out << c.getName() << " (" << c.getHitpoints() << " hp)";
    return out;
}
