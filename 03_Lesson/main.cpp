#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Waterpokemon.h"
#include "Firepokemon.h"
#include "Earthpokemon.h"
#include "icepokemon.h"


int main() {

    std::srand(time(nullptr));

    Waterpokemon shiggy("Shiggy", 1, 150, 7);
    shiggy.addAttack(Attack("water gun", Water, 25));
    shiggy.addAttack(Attack("tail whip", Normal, 15));
    shiggy.addAttack(Attack("rain dance", Water, 5));
    shiggy.addAttack(Attack("hydro pump", Water, 10));

    Firepokemon lavados("Lavados", 1, 100, 23);
    lavados.addAttack(Attack("wind", Flight, 20));
    lavados.addAttack(Attack("ember", Fire, 10));
    lavados.addAttack(Attack("wind cut", Earth, 15));
    lavados.addAttack(Attack("heat wave", Fire, 5));

    Earthpokemon diglett("Diglett", 1, 50, 50);
    diglett.addAttack(Attack("sand attack", Earth, 5));
    diglett.addAttack(Attack("Scratch", Normal, 10));
    diglett.addAttack(Attack("slash", Normal, 15));
    diglett.addAttack(Attack("dig", Earth, 10));

    Icepokemon freezer("Freezer", 1, 50, 99);
    freezer.addAttack(Attack("snow ball", Ice, 5));
    freezer.addAttack(Attack("Scratch", Normal, 10));
    freezer.addAttack(Attack("slash", Normal, 15));
    freezer.addAttack(Attack("snow storm", Ice, 10));

    std::cout << "------------------------------" << std::endl;

    if (shiggy.fight(&lavados)) {
        std::cout << shiggy.getName() << " won!" << std::endl;
        shiggy.levelUp();
        std::cout << "------------------------------" << std::endl;
        if (shiggy.fight(&diglett)) {
            std::cout << shiggy.getName() << " won!" << std::endl;
            std::cout << "------------------------------" << std::endl;
            if (shiggy.fight(&freezer)) {
                std::cout << shiggy.getName() << " won!" << std::endl;
            }
        }

    }
    std::cout << "------------------------------" << std::endl;

    return 0;
}
