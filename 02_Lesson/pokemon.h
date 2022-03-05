//
// Created by lukas on 18.02.2022.
//

#ifndef LESSON_2_POKEMON_H
#define LESSON_2_POKEMON_H


#include <string>

class Pokemon {

private:

    std::string name;
    int hitpoints;
    int level;
    int pokedexNumber;
    bool isCaught;

public:

    void initPokemon(const std::string& name, int level, int hitpoints, int pokedexNumber);

    void initPokemon();

    void attack(Pokemon *enemy);

    void levelUp();


    // Getter & Setter

    const std::string &getName() const;

    void setName(const std::string &name);

    int getHitpoints() const;

    void setHitpoints(int hitpoints);

    int getLevel() const;

    void setLevel(int level);

    int getPokedexNumber() const;

    void setPokedexNumber(int pokedexNumber);

    bool isIsCaught() const;

    void setIsCaught(bool isCaught);


};


#endif //LESSON_2_POKEMON_H
