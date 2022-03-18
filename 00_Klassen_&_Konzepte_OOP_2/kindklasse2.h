//
// Created by lugerber on 09.03.2022.
//

#ifndef KLASSEN___KONZEPTE_OOP_2_KINDKLASSE2_H
#define KLASSEN___KONZEPTE_OOP_2_KINDKLASSE2_H


#include "elternklasse.h"

// Hinter dem Doppelpunkt werden die Klassen von denen geerbt werden soll angegeben
// public: die Sichtbarkeiten der Elternklasse bleiben unverändert
// private: alle Sichtbarkeiten der Elternklasse werden auf private gestellt
// protected: alle Sichtbarkeiten der Elternklasse werden auf protected gestellt
// Die Kindklasse erbt Eigenschaften und Funktionen von der Elternklasse
class Kindklasse2 : public Elternklasse {



private:
    int number;

public:

    // Hier ist zu sehen, dass auch der Konstruktor der Elternklasse geerbt wird Elternklasse(...) und
    // neue Variablen zum Konstruktor der Kindklasse hinzugefügt werden können
    Kindklasse2(const std::string &konstruktorName, int konstruktorAge, int number)
            : Elternklasse(konstruktorName, konstruktorAge), number(number) {}

    // Mittels using xxxxx können die Konstruktoren der Elternklasse geerbt und verwendet werden (siehe kindklasse1.h)
    // jedoch können hier keine zusätzlichen Argumente (z.B. number) übergeben werden

    virtual ~Kindklasse2() {}

    void foo(){
        std::cout << "Calling Kindklasse2::foo()" << std::endl;
    }

    virtual void bar(){
        std::cout << "Calling Kindklasse2::bar()" << std::endl;
    }

};


#endif //KLASSEN___KONZEPTE_OOP_2_KINDKLASSE2_H
