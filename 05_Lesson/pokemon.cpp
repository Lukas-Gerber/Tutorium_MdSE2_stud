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

int Pokemon::addAttack(std::shared_ptr<Attack> attack) {
    storage.push_back(attack);
}

std::shared_ptr<Attack> Pokemon::removeAttack(int slot) {

    if (storage[slot]) {
        auto retval = storage[slot];
        storage.erase(storage.begin()+slot);
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

    if(this->hitpoints > 0){
        std::cout << *this << " won!" << std::endl;
        parent->removePokemon(rival->getName());

    }

    return this->getHitpoints() > 0;
}

std::shared_ptr<Attack>Pokemon::getAttack(int index) {
    auto attack = this->storage[index];
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

std::ostream& operator<<(std::ostream& out, const Pokemon& c) {
    out << c.getName() << " (" << c.getHitpoints() << " hp)";
    return out;
}
