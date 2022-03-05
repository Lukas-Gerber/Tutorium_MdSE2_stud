#include <iostream>
#include <cstdlib>
#include <ctime>

#include "trainer.h"
#include "rival.h"

int main() {

    std::srand(time(nullptr));

    Trainer ash;
    // init Funktion erwartet einen Pointer, daher muss hier der Adressoperator angegeben werden
    ash.initTrainer("Ash", 1);

    // Ash chooses Shiggy and catches Rettan on the way
    Pokemon shiggy;
    shiggy.initPokemon("Shiggy", 1, 50, 7);

    Pokemon rettan;
    rettan.initPokemon("Rettan", 1, 10, 23);


    ash.addPokemon(shiggy);
    ash.addPokemon(rettan);

    Rival gary;
    gary.initRival("Gary", 1);
    // Rival gary chooses Glumanda
    Pokemon glumanda;
    glumanda.initPokemon("Glumanda", 1, 30, 4);
    gary.addPokemon(glumanda);

    Rival jessi;
    jessi.initRival("Jessi", 1);
    // Rival Jessi chooses Mauzi
    Pokemon mauzi;
    mauzi.initPokemon("Mauzi", 1, 20, 52);
    jessi.addPokemon(mauzi);

    int index = -1;
    int rivalIndex = -1;

    ash.choosePokemon(index);
    gary.choosePokemon(rivalIndex);


   if (ash.fight(index, &gary, rivalIndex)) {
        std::cout << gary.getPokemon(rivalIndex)->getName() << " has 0 hitpoints left. " << ash.getPokemon(index)->getName() << " still has "
                  << ash.getPokemon(index)->getHitpoints() << ". " << ash.getName() << " wins." << std::endl;
        ash.getPokemon(index)->levelUp();

    } else {
        std::cout << ash.getPokemon(index)->getName() << " has 0 Hitpoints left. "
                  << ash.getName() << " loses!" << std::endl;
        return 0;
    }

/*    ash.choosePokemon(index);
    jessi.choosePokemon(rivalIndex);


    if (ash.fight(index, &jessi, rivalIndex)) {
        std::cout << jessi.getPokemon(rivalIndex)->getName() << " has 0 hitpoints left. " << ash.getPokemon(index)->getName() << " still has "
                  << ash.getPokemon(index)->getHitpoints() << ". " << ash.getName() << " wins." << std::endl;

    } else {
        std::cout << ash.getPokemon(index)->getName() << " has 0 Hitpoints left. "
                  << ash.getName() << " loses!" << std::endl;
        return 0;
    }*/


    return 0;
}
