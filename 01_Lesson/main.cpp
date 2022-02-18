#include <iostream>
#include <cstdlib>
#include <ctime>

#include "trainer.h"
#include "rival.h"

int main() {

    std::srand(time(nullptr));

    Trainer_t ash;
    // init Funktion erwartet einen Pointer, daher muss hier der Adressoperator angegeben werden
    initTrainer(&ash, (char *) "Ash", 1);

    // Ash chooses Shiggy and catches Rettan on the way
    initPokemon(&ash.storage[0], (char *) "Shiggy", 1, 50, 7);
    initPokemon(&ash.storage[1], (char *) "Rettan", 1, 10, 23);

    Rival_t gary;
    initRival(&gary, (char *) "Gary", 1);
    // Rival gary chooses Glumanda
    initPokemon(&gary.storage[0], (char *) "Glumanda", 1, 30, 4);

    Rival_t jessi;
    initRival(&jessi, (char *) "Jessi", 1);
    // Rival Jessi chooses Mauzi
    initPokemon(&jessi.storage[0], (char *) "Mauzi", 1, 20, 52);



    showStorage(&ash);

    int index = 0;
    std::cout << "Choose your fighter (index): ";
    std::cin >> index;

    if (fight(&ash, index, &gary, 0)) {
        std::cout << gary.storage[0].name << " has 0 hitpoints left. " << ash.storage[index].name << " still has "
                  << ash.storage[index].hitpoints << ". " << ash.name << " wins." << std::endl;
        levelUp(&ash.storage[index]);
    } else {
        std::cout << ash.storage[index].name << " has 0 Hitpoints left. "
                  << ash.name << " loses!" << std::endl;
        return 0;
    }

    showStorage(&ash);

    std::cout << "Choose your fighter (index): ";
    std::cin >> index;


    if (fight(&ash, index, &jessi, 0)) {
        std::cout << jessi.storage[0].name << " has 0 hitpoints left. " << ash.storage[index].name << " still has "
                  << ash.storage[index].hitpoints << ". " << ash.name << " wins." << std::endl;

    } else {
        std::cout << ash.storage[index].name << " has 0 Hitpoints left. "
                  << ash.name << " loses!" << std::endl;
        return 0;
    }


    return 0;
}
