#include <iostream>
#include "class.h"
#include "kapselung.h"


int main() {

    // 1. Unterschiede struct und class (class.h)

    // Grundlegend unterscheiden sich struct und class nur in den Sichtbarkeiten.
    // Während ein struct als Standard public ist, ist eine class standardmäßig private.

    // Was heißt nun public, private und protected
    // public: auf die variable/funktion usw. kann von überall zugegriffen werden
    // private: auf die Variable/Funktion usw. kann nur innerhalb der Klasse zugegriffen werden
    // protected: auf die Variable/Funktion usw. kann innerhalb der Klasse und von Kindklassen zugegriffen werden


    Class c;
    Struct s;
    PublicClass pc;

    std::cout << s.structName << std::endl; // struct ist standardmäßig public
    std::cout << pc.publicClassName
              << std::endl; // wird die variable auf public gesetzt kann auf diese auch zugegriffen werden

    // 1.1 Objektfunktionen / methoden
    // Es ist möglich Funktionen innerhalb einer Klasse zu deklarieren, definieren & implementieren, dabei spricht man von Objektfunktionen oder Methoden
    // So können wir z.B. die Methode print aufrufen, welche uns einen String und den Klassennamen ausgibt

    c.print();

    // 1.2 Getter & Setter - Zugriff auf private/protected Parameter

    // std::cout << c.className << std::endl; // hier wird die Fehlermeldung "error: 'std::string Class::className' is private within this context" ausgegeben
    // Durch Kapselung wird die Variable vor der "Außenwelt" versteckt
    // Stattdessen müssen für den Zugriff auf private Parameter Getter & Setter gemacht werden

    std::cout << c.getName() << std::endl;
    c.setName("Getter Class");
    std::cout << c.getName() << std::endl;



    // KONZEPTE DER OBJEKTORIENTIERTEN PROGRAMMIERUNG

    // 2.Kapselung (Verstecken interner Details)
    // In der Datei kapselung.h findet ihr genaueres zu dem Thema
    // Grundlegend geht es darum interne Details vor der "Au0enwelt" zu verstecken
    // Damit kann vermieden werden, dass ein direkter Zugriff auf z.B. Variablen erfolgt und ein illegaler zustand entsteht

    Kapselung k;

    std::cout << "Age: " << k.getAge() << std::endl;
    k.setAge(-1);
    std::cout << "Age: " << k.getAge() << std::endl;
    k.setAge(10);
    std::cout << "Age: " << k.getAge() << std::endl;


    // Folgende Konzepte sehen wir uns in Lesson/Aufgabe 3 an

    // 4.Abstraktion (Finden von Gemeinsamkeiten (Eigenschaften, Verhalten))
    // 5.Vererbung (Weitergeben von Eigenschaften und Verhalten)
    // 5.1 Spezialisierung (Ableiten von Kindklassen)
    // 5.2 Generalisierung (Auslagern von gemeinsamen Attributen)
    // 6.Polymorphismus (Vielgestaltigkeit)

    return 0;
}
