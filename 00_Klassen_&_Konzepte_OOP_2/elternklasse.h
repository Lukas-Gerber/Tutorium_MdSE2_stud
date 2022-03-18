//
// Created by lugerber on 09.03.2022.
//

#ifndef KLASSEN___KONZEPTE_OOP_2_ELTERNKLASSE_H
#define KLASSEN___KONZEPTE_OOP_2_ELTERNKLASSE_H


#include <string>

class Elternklasse {

private:
    std::string name;
    int age = -1;

public:

    // Aufbau des Konstruktors: Klassenname(Eingabeargumente) : Objektvariablen(Variable aus den Eingabeargumenten){};
    // Hinter dem Doppelpunkt befindet sich die "Initializer List"
    // Der Funktionskörper kann leer bleibe oder befüllt werden

    // Default-Konstruktor
    // Dieser wird vom Programm automaitsch erzeugt, kann aber selbst implementiert werden z.B. um Variablen zu initialisieren
    Elternklasse() : name("Defaultkonstruktor") {
        //std::cout << "Konstruktor: " << name << std::endl;
    }

    // Erstellter Konstruktor
    // Dieser Konstruktor nimmt einen String entgegen, das Alter wird automatisch auf 0 gesetzt
    Elternklasse(const std::string &konstruktorName)
            : name(konstruktorName), age(0) {
        //std::cout << "Konstruktor: " << name << std::endl;
    }

    // Mehrere Eingabeargumente werden durch ein Komma voneinander getrennt
    Elternklasse(const std::string &konstruktorName, int konstruktorAge)
            : name(konstruktorName), age(konstruktorAge) {
        //std::cout << "Konstruktor: " << name << std::endl;
    }

    // Destruktor
    // Hiervon kann es nur einen geben, dieser hat keine Eingabeargumente
    // und wird bei der Zerstörung des Objektes aufgerufen
    // Ist eine virtual Funktion in der Klasse soll der Destruktor auch virtual sein

    // Der virtual Destruktor ist nur dann notwendig,wenn Polymorphismus
    // im Zusammenhang mit dem delete Operator verwendet wird.

    // Best Practice ist es jedoch den Destructor virtual zu setzten,
    // sobald eine Klasse eine virtuelle Objektfunktion enthält.

    virtual ~Elternklasse() {

        std::cout << "calling Destructor of class: " << name << std::endl;

    }

    // Objektfunktionen

    void foo() {
        std::cout << "Calling Elternklasse::foo()" << std::endl;
    }

    virtual void bar() {
        std::cout << "Calling Elternklasse::bar()" << std::endl;
    }

    // Soll keine Implementierung einer Funktion z.B. foo() in der Elternklasse erfolgen,
    // wird dies als virtual void foo() = 0; angegeben.
    // Dies ist eine abstrakte Funktion. Eine Klasse mit einer abstrakten Funktion wird auch abstrakte Klasse genannt
    // und es kann von der Klasse direkt keine Instanz erzeugt werden



    // Getter
    const std::string &getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }


};


// Operatorenüberladung als Globale Funktion
// https://en.cppreference.com/w/cpp/language/operators
// Unter obigem Link ist ersichtlich welche Operatoren global oder als Memberfunktion überschrieben werden können

// Da wir die Ausgabe verändern wollen, muss der ostream (Outputstream) überschrieben werden (extraction operator)
// Anschließend wird mit operator<< der zu überschreibende Operator angegeben

std::ostream &operator<<(std::ostream &out, const Elternklasse &c) {
// Das linke Eingabeargument nimmt den angegebenen Operator (in diesem Fall <<) entgegen
// Das rechte Eingabeargument ist das von uns übergebene Objekt
// das dieses nicht verändert werden soll/darf, wird es als read-only Reference übergeben

    out << c.getName() << " Alter: " << c.getAge();
    return out;
}


#endif //KLASSEN___KONZEPTE_OOP_2_ELTERNKLASSE_H
