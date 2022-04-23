//
// Created by lukas on 23.04.2022.
//

#pragma once


#include <map>
#include <string>
#include <memory>

class Pokemon;

class Game {
protected:
    std::map<std::string, std::shared_ptr<Pokemon>> pokemons;

public:

    Game() {}

    void play();

    void addPokemon(std::shared_ptr<Pokemon> pokemon);

    void removePokemon(const std::string& name);

    void printPokemon();


};



