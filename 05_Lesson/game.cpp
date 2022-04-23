//
// Created by lukas on 23.04.2022.
//

#include <iostream>
#include "game.h"
#include "waterpokemon.h"
#include "icepokemon.h"
#include "firepokemon.h"
#include "earthpokemon.h"

void Game::play() {

    std::srand(time(nullptr));

    try {
        //Waterpokemon test("test", 1, 150, 7);



        std::shared_ptr<Waterpokemon> shiggy(new Waterpokemon(this, "Shiggy", 1, 150, 7));
        addPokemon(shiggy);
        std::shared_ptr<Firepokemon> lavados(new Firepokemon(this, "Lavados", 1, 100, 23));
        addPokemon(lavados);
        std::shared_ptr<Earthpokemon> diglett(new Earthpokemon(this, "Diglett", 1, 50, 50));
        addPokemon(diglett);
        std::shared_ptr<Icepokemon> freezer(new Icepokemon(this, "Freezer", 1, 50, 99));
        addPokemon(freezer);
        std::shared_ptr<Waterpokemon> anton(new Waterpokemon(this, "Anton", 1, 150, 7));
        addPokemon(anton);

        printPokemon();

        shiggy->addAttack(std::shared_ptr<Attack>(new Attack("quick attack", Normal, 7)));
        shiggy->addAttack(std::shared_ptr<Attack>(new Attack("tail whip", Normal, 15)));
        shiggy->addAttack(std::shared_ptr<Attack>(new Attack("rain dance", Water, 5)));
        shiggy->addAttack(std::shared_ptr<Attack>(new Attack("hydro pump", Water, 10)));


        lavados->addAttack(std::shared_ptr<Attack>(new Attack("wind", Flight, 20)));
        lavados->addAttack(std::shared_ptr<Attack>(new Attack("ember", Fire, 10)));
        lavados->addAttack(std::shared_ptr<Attack>(new Attack("wind cut", Earth, 15)));
        lavados->addAttack(std::shared_ptr<Attack>(new Attack("heat wave", Fire, 5)));


        diglett->addAttack(std::shared_ptr<Attack>(new Attack("sand attack", Earth, 5)));
        diglett->addAttack(std::shared_ptr<Attack>(new Attack("Scratch", Normal, 10)));
        diglett->addAttack(std::shared_ptr<Attack>(new Attack("slash", Normal, 15)));
        diglett->addAttack(std::shared_ptr<Attack>(new Attack("dig", Earth, 10)));


        freezer->addAttack(std::shared_ptr<Attack>(new Attack("snow ball", Ice, 5)));
        freezer->addAttack(std::shared_ptr<Attack>(new Attack("Scratch", Normal, 10)));
        freezer->addAttack(std::shared_ptr<Attack>(new Attack("slash", Normal, 15)));
        freezer->addAttack(std::shared_ptr<Attack>(new Attack("snow storm", Ice, 10)));


        std::cout << "------------------------------" << std::endl;

        if (shiggy->fight(lavados.get())) {
            shiggy->levelUp();
            lavados.reset();
            std::cout << "------------------------------" << std::endl;
            if (shiggy->fight(diglett.get())) {
                shiggy->levelUp();
                diglett.reset();
                std::cout << "------------------------------" << std::endl;
                if (shiggy->fight(freezer.get())) {
                    freezer.reset();
                }
            }

        }

        printPokemon();

        std::cout << "------------------------------" << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }

}

void Game::addPokemon(std::shared_ptr<Pokemon> pokemon) {
    if (pokemons.find(pokemon->getName()) == pokemons.end()) {
        pokemons.insert({pokemon->getName(), pokemon});
    } else {
        throw NonUniqueNameException(std::string("Name ") + pokemon->getName() + std::string(" already exists"));
    }
}

void Game::removePokemon(const std::string &name) {
    if (pokemons.find(name) != pokemons.end()) {
        pokemons.erase(name);
    } else {
        throw NonExistingNameException(std::string("Name ") + name + std::string(" does not exist"));
    }
}

void Game::printPokemon() {
    std::cout << "---------------------" << std::endl;
    for (const auto &p: pokemons) {
        std::cout << "Key: " << p.first << " = " << "HP: " << p.second->getHitpoints() << "; " << std::endl;
    }
}
