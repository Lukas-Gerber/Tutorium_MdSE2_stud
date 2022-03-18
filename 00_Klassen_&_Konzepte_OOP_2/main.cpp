#include <iostream>
#include "elternklasse.h"
#include "kindklasse1.h"
#include "kindklasse2.h"
#include "kindeskindklasse.h"

// Forward Deklaration
void statischeBindung(Elternklasse *e);

void dynamischBindung(Elternklasse *e);

int main() {

    {
        // 1. Konstruktoren & Destruktoren

        // Konstruktoren werden bei der Erzeugung eines Objektes aufgerufen (siehe elternklasse.h)
        // Es können mehrere Konstruktoren mit verschiedenen Eingabeargumenten erstellt werden.

        Elternklasse ek1;
        Elternklasse ek2("Elternklasse");
        Elternklasse ek3("Elternklasse", 25);

        // Destruktoren werden bei der Zerstörung eines Objektes (Ende des Gültigkeitsbereiches) aufgerufen

        // 1.1 Operatorenüberladung (siehe elternklasse.h)
        // Mittels Operatorenüberladung können Operatoren erweitert werden
        // z.B. müssten wir in folgendem Beispiel den Aufruf ek1.getName() tätigen um die Variable name der Klasse aufrufen zu können

        std::cout << "getName(): " << ek1.getName() << std::endl;

        // Dies mag bei einer Variable nicht sehr viel Unterschied machen, was passiert jedoch wenn wir mehrere Variablen haben oder neue Variablen hinzukommen?
        // Bei der Überladung kann dies einfach und schnell geändert werden,
        // beim Aufruf mittels Getter führt dies schnell zu langen Codezeilen und viel Arbeit!!

        std::cout << "Ueberladung: " << ek1 << std::endl;
        std::cout << "Ueberladung: " << ek2 << std::endl;
        std::cout << "Ueberladung: " << ek3 << std::endl;

    }

    {
        // 1.2 Beispiel am Heap

        std::cout << "------------------------------------ " << std::endl;
        Elternklasse *ekh = new Elternklasse("Heapklasse", 100);
        std::cout << "Ueberladung: " << *ekh << std::endl;

        // bei Heap-Objekten muss delete aufgerufen werden, dass das Objekt zerstört wird!
        delete ekh; // wenn delete auskommentiert ist sieht man, dass der Destruktor nicht aufgerufen wird, da das Objekt nicht zerstört wurde!

        std::cout << "------------------------------------ " << std::endl;

    }

    // 2. Abstraktion (Finden von Gemeinsamkeiten (Eigenschaften, Verhalten))
    // In unserem Beispiel werden z.B. der Name und das Alter in die Elternklasse "gehoben",
    // da diese Gemeinsamkeiten zwischen allen Kindklassen darstellen.


    // 3. Vererbung (Weitergeben von Eigenschaften und Verhalten)

    std::cout << "------------------------------------ " << std::endl;

    {
        Kindklasse1 kk1;
        Kindklasse1 kk2("Kindklasse 1.1");
        Kindklasse1 kk3("Kindklasse 1.2", 25);

        Kindeskindklasse kikla("Kindeskindklasse",10,5);

        std::cout << "Kind1-Ueberladung: " << kk1 << std::endl;
        std::cout << "Kind1-Ueberladung: " << kk2 << std::endl;
        std::cout << "Kind1-Ueberladung: " << kk3 << std::endl;
        std::cout << "Kindeskind-Ueberladung: " << kikla << " Index: " << kikla.getIndex() << std::endl;
    }

    std::cout << "------------------------------------ " << std::endl;

    {
        Kindklasse2 kk4("Kindklasse 2.1", 25, 99);
        std::cout << "Kind2-Ueberladung: " << kk4 << std::endl;
    }

    std::cout << "------------------------------------ " << std::endl;
    std::cout << "4.Polymorphismus & dynamische/statische Bindung" << std::endl;
    // 4. Polymorphismus (Vielgestaltigkeit) & dynamische / statische Bindung
    // Überall dort wo ein Objekt einer Elternklasse erwartet wird kann ein Objekt einer Kindklasse verwendet werden.

    // Dynamische und statische Bindungen sind ein sehr wichtiges Konzept für den Polymorphismus
    // statische Bindung = Bindung findet zur Compile-Time statt
    // dynamische Bindung = Bindung findet zur Runtime-Time statt

    {

        std::cout << "-- statische Bindung" << std::endl;
        // Statische Bindung (wird in C++ stanardmäßig verwendet)
        // Compiler trifft die Zuordnung während der Compile-Time
        // Daher kann die Ausgabe nur der in der Funktion angegebenen Klasse zugeordnet werden
        // in unserem Fall der Elternklasse

        Elternklasse *ek1 = new Elternklasse;
        Elternklasse *kk1 = new Kindklasse1;
        Elternklasse *kikla = new Kindeskindklasse;

        statischeBindung(ek1);
        statischeBindung(kk1);
        statischeBindung(kikla);
        // Hier wird zweimal die foo() der Elternklasse ausgegeben

        std::cout << "-- dynamische Bindung" << std::endl;

        // Dynamische Bindung (dynamische Bindung wird mit dem virtual Keyword angegeben)
        // Zuordnung wird während der Runtime-Time getroffen
        // Daher kann der Aufruf der konkreten übergebenen Subklasse zugeordnet werden
        // und daher die Funktion der Subklasse aufgerufen werden

        dynamischBindung(ek1);
        dynamischBindung(kk1);
        dynamischBindung(kikla);
        // Hier wird die bar() der Elternklasse & der Kindklasse ausgegeben

        // Nicht vergessen die auf dem Heap erstellten Instanzen am Ende zu löschen!
        delete ek1;
        delete kk1;
        delete kikla;

        // Bei den Beispielen ist zu beachten, dass von den Funktionen ein Objekt der Elternklasse erwartet wird,
        // wir jedoch ein Objekt der Kindklasse übergeben => Polymorphismus

    }

    std::cout << "------------------------------------ " << std::endl;

}

void statischeBindung(Elternklasse *e) {
    e->foo();
}

void dynamischBindung(Elternklasse *e) {
    e->bar();
}
