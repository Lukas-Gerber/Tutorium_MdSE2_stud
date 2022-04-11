#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

#include "Waterpokemon.h"
#include "Firepokemon.h"
#include "Earthpokemon.h"
#include "icepokemon.h"

int main() {

    std::srand(time(nullptr));

    try {
        //Waterpokemon test("", -1, -150, -7);

        Waterpokemon shiggy("Shiggy", 1, 150, 7);
        shiggy.addAttack(new Attack("quick attack", Normal, 7));
        shiggy.addAttack(new Attack("tail whip", Normal, 15));
        shiggy.addAttack(new Attack("rain dance", Water, 5));
        shiggy.addAttack(new Attack("hydro pump", Water, 10));
        //shiggy.addAttack(new Attack("hydro", Water, 10));

        //shiggy.removeAttack(9);
        //shiggy.removeAttack(3);

        Firepokemon lavados("Lavados", 1, 100, 23);
        lavados.addAttack(new Attack("wind", Flight, 20));
        lavados.addAttack(new Attack("ember", Fire, 10));
        lavados.addAttack(new Attack("wind cut", Earth, 15));
        lavados.addAttack(new Attack("heat wave", Fire, 5));

        Earthpokemon diglett("Diglett", 1, 50, 50);
        diglett.addAttack(new Attack("sand attack", Earth, 5));
        diglett.addAttack(new Attack("Scratch", Normal, 10));
        diglett.addAttack(new Attack("slash", Normal, 15));
        diglett.addAttack(new Attack("dig", Earth, 10));

        Icepokemon freezer("Freezer", 1, 50, 99);
        freezer.addAttack(new Attack("snow ball", Ice, 5));
        freezer.addAttack(new Attack("Scratch", Normal, 10));
        freezer.addAttack(new Attack("slash", Normal, 15));
        freezer.addAttack(new Attack("snow storm", Ice, 10));

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

    } catch (std::exception &e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }
    return 0;
}
