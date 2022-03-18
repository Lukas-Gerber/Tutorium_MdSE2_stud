//
// Created by lugerber on 09.03.2022.
//

#ifndef KLASSEN___KONZEPTE_OOP_2_KINDKLASSE1_H
#define KLASSEN___KONZEPTE_OOP_2_KINDKLASSE1_H


#include "elternklasse.h"

// Hinter dem Doppelpunkt werden die Klassen von denen geerbt werden soll angegeben
// public: die Sichtbarkeiten der Elternklasse bleiben unverändert
// private: alle Sichtbarkeiten der Elternklasse werden auf private gestellt
// protected: alle Sichtbarkeiten der Elternklasse werden auf protected gestellt
// Die Kindklasse erbt Eigenschaften und Funktionen von der Elternklasse
class Kindklasse1 : public Elternklasse {

public:
    // Mittels using xxxxx::xxxxx werden die Konstruktoren der Elternklasse geerbt und können verwendet werden
    // jedoch können hier keine zusätzlichen Argumente übergeben werden
    // Eine weitere Möglichkeit die Konstruktoren zu erstellen wird in der Datei kindklasse2.h dargestellt
    using Elternklasse::Elternklasse;


    void foo(){
        std::cout << "Calling Kindklasse1::foo()" << std::endl;
    }

    virtual void bar(){
        std::cout << "Calling Kindklasse1::bar()" << std::endl;
    }


};

#endif //KLASSEN___KONZEPTE_OOP_2_KINDKLASSE1_H
