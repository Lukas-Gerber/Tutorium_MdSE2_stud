//
// Created by lukas on 11.02.2022.
//

#ifndef GRUNDLAGEN_SCHLEIFEN_H
#define GRUNDLAGEN_SCHLEIFEN_H

#include <vector>
#include <iostream>

void schleifen(const std::string &eingabe) {
    // 3. Schleifen
    std::cout << "\n3.Schleifen\n----------------------------" << std::endl;
    // Schleifen sind zum Großteil gleich wie in C aufgebaut.

    // 3.1 for-each
    // Seit C++ 11 gibt es zusätzlich eine Range-based for loop (for-each)
    // Diese kann auch mit nicht primitiven Datentypen (z.B. Objekten) verwendet werden

    // Genaueres zum vector folgt im Laufe der Vorlesung
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    // int i wird für das weiterverwenden in der loop angegeben.
    // vec ist der Vector welchen wir durchitterieren wollen.
    for (int i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Hierzu noch ein Beispiel.
    // Wir wollen herausfinden wie viele Vokale in dem von uns vorher eingegebenen Wort sind

    int vowels = 0;

    // in der Schleife wollen wir alle Positionen mit dem Datentyp "char" in der "eingabe" durchgehen
    // Uebersetzt heisst die folgende Zeile so viel wie, "Für jeden char in eingabe mache folgendes

    for (char c: eingabe) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        }
    }
    std::cout << "In dem Wort '" << eingabe << "' sind " << vowels << " Vokale" << std::endl;


}


#endif //GRUNDLAGEN_SCHLEIFEN_H
