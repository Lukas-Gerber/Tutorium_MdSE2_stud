// Created by Lukas Gerber, 11.02.2022

// 1. Includes
// Sind diese im Format <filename> geschrieben, sucht der Präprozessor zuerst in durch die IDE vordefinierten Pfaden.
// Wird verwendet, um standard Header-Dateien einzubinden.
#include <iostream>

// Sind diese im Format "filename" geschrieben, sucht der Präprozessor zuerst in demselben Ordner wo das .cpp-File liegt.
#include "ueberladung.h"
#include "streams.h"
#include "schleifen.h"
#include "lifetime.h"

int main() {

    std::string eingabe;

    // 2. Input & Output Operatoren
    // Detailierte Erklärung der Input & Output Operatoren in der Datei "streams.h"

    streams(eingabe);

    // 3. Schleifen
    // Detailierte Erklärung der Schleifen in der Datei "schleifen.h"

    schleifen(eingabe);

    // 4.Lebenszeit / Gueltigkeitsbereiche
    // Detailierte Erklärung des Gueltigkeitsbereiches in der Datei "lifetime.h"

    lifetime();


    // 5. Funktionsueberladung
    // Ueberladene Funktionen, sind Funktionen mit demselben Namen
    // aber unterschiedlichen Eingabeparametern

    std::cout << "\n5.Funktionsueberladung\n----------------------------" << std::endl;

    // Funktionen befinden sich in der Datei "ueberladung.h"
    print(5);
    print(4.4);
    print("Test");

    // Return Statement in der main().
    // return 0 bedeutete in diesem Fall "no error".
    return 0;



}

