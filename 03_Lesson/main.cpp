#include <iostream>
#include <cstdlib>
#include <ctime>

#include "pokemon.h"


int main() {

    std::srand(time(nullptr));

    Pokemon shiggy;
    shiggy.initPokemon("Shiggy", 1, 150, 7);

    // Attacks
    Attack watergun;
    watergun.initAttack("water gun", 25);
    Attack tailwhip;
    tailwhip.initAttack("tail whip", 15);
    Attack raindance;
    raindance.initAttack("rain dance", 5);
    Attack hydropump;
    hydropump.initAttack("hydro pump", 10);

    // Add Attacks to Pokemon
    shiggy.addAttack(watergun);
    shiggy.addAttack(tailwhip);
    shiggy.addAttack(raindance);
    shiggy.addAttack(hydropump);



    Pokemon lavados;
    lavados.initPokemon("Lavados", 1, 100, 23);

    Attack wind;
    wind.initAttack("wind", 20);
    Attack ember;
    ember.initAttack("ember", 10);
    Attack windcut;
    windcut.initAttack("wind cut", 15);
    Attack heatwave;
    heatwave.initAttack("heat wave", 5);

    lavados.addAttack(wind);
    lavados.addAttack(ember);
    lavados.addAttack(windcut);
    lavados.addAttack(heatwave);




    std::cout << "------------------------------" << std::endl;

    if(shiggy.fight(&lavados)){
        std::cout << shiggy.getName() << " won and still has " << shiggy.getHitpoints() << "hp left! "<< std::endl;
        shiggy.levelUp();

    }
    std::cout << "------------------------------" << std::endl;

    return 0;
}
