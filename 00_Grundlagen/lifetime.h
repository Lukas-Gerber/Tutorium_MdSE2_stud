//
// Created by lukas on 11.02.2022.
//

#ifndef GRUNDLAGEN_LIFETIME_H
#define GRUNDLAGEN_LIFETIME_H

#include <iostream>


// Funktionen-Scoped

void lifetime(){

    std::cout << "\n6.Lebenszeit\n----------------------------" << std::endl;
    std::cout << "Start 'Function scope'\n{" << std::endl;

    // Variablen existieren so lange bis das Funktionsende erreicht ist
    int functionScoped = 10;
    std::cout << "Var func: " << functionScoped << " created" << std::endl;

    // Statement scope
    if(true){
        std::cout << "  Start 'Statement scope'\n   {" << std::endl;
        int i = 0;
        std::cout << "  Var state: " << i << std::endl;
        std::cout << "  Var func: " << functionScoped << std::endl;
        std::cout << "  End 'Statement scope'\n   }" << std::endl;
    }

    // Empty scope
    {
        std::cout << "  Start 'Empty scope'\n   {" << std::endl;
        int es = 10;
        std::cout << "  Var empty: " << es << std::endl;
        std::cout << "  Var func: " << functionScoped << std::endl;
        std::cout << "  Var state: " << "nicht verwendbar da mit Ende des vorherigen Scopes zerstört" << std::endl;
        std::cout << "  End 'Empty scope'\n   }" << std::endl;
    }
    std::cout << "End 'Function scope'\n}" << std::endl;

    std::cout << "\nGenaueres zu den Gültigkeitsbereichen und dem Zusammenspiel mit Heap und Stack folgt noch" << std::endl;
}
// an dieser Stelle kann functionscoped nicht mehr verwendet werden,
// da es mit ende des Scopes "zerstört" wurde




#endif //GRUNDLAGEN_LIFETIME_H
