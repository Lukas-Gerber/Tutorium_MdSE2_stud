//
// Created by lukas on 18.04.2022.
//

#ifndef DATEN_CONTAINER_VECTOR_H
#define DATEN_CONTAINER_VECTOR_H

#include <vector>
#include <iostream>

void print_vector(const std::vector<int> &v) {
    std::cout << "[ ";
    for (int i: v) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
}

void vector() {

    std::cout << "--VECTOR--" << std::endl;

    // Container in der Standardbibliothek

    // 1. Sequentielle Container
    //      Speichern Elemente hintereinander
    //      Elementzugriff über Index
    //      Dazu gehören z.B.:
    //          - array (statisch)
    //          - vector (dynamisch)


    // 1.1 vector (https://en.cppreference.com/w/cpp/container/vector)
    // dynamisches Array
    // In dem header #include <vector> zu finden

    // Erzeugen eines Vectors
    // Zwischen den <>-Klammern wird der Datentype der Inhalte des Vectors angegeben
    // vec ist in diesem Beispiel der Variablenname
    std::vector<int> vec = {1, 2, 3};
    std::cout << "Inhalt: ";
    print_vector(vec);
    std::cout << "---------------------------------" << std::endl;

    // Wichtigste Funktionen für den Vector

    // size() => gibt aktuelle Groesse zurück
    std::cout << "size(): " << vec.size() << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // - push_back(WERT) => neues Element am Ende hinzufügen
    vec.push_back(42);
    std::cout << "Inhalt nach push_back(): ";
    print_vector(vec);
    std::cout << "---------------------------------" << std::endl;

    // - vec[INDEX] => Zugriff auf den Wert an Indexstelle
    std::cout << "Zugriff auf Index 3: " << vec[3] << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // - vec[INDEX] = WERT, ueberschreiben von Werten an Indexstelle (ohne Grenz-Ueberprüpfung)
    vec[0] = 23;
    std::cout << "Nach Ueberschreibung bei Index 0: ";
    print_vector(vec);
    std::cout << "---------------------------------" << std::endl;

    // - at(INDEX) = WERT, ueberschreiben von Werten an Indexstelle (mit Grenz-Ueberprüpfung)
    // vec.at(10) = 23; // auskommentieren um Fehlermeldung zu sehen

    // - erase(INDEX) => löscht Wert an Indexstelle
    vec.erase(vec.begin() + 3); // Achtung, hier mit begin() + Index gearbeitet werden
    std::cout << "Löschen des Wertes bei Index 3!" << std::endl;
    print_vector(vec);
    std::cout << "---------------------------------" << std::endl;

    // Es besteht auch die Möglichkeit zwischen einem Start und Endindex zu löschen
    // Hinzufügen von Werten zur besseren Veranschaulichung
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    print_vector(vec);

    std::cout << "Löschen der Werte zwischen Index 1(inklusive) - 3(exkulsive)!" << std::endl;

    vec.erase(vec.begin() + 1, vec.begin() + 3);
    print_vector(vec);
    std::cout << "---------------------------------" << std::endl;

    // - front() => gibt erstes Element zurueck
    std::cout << "Erstes Element mit front(): " << vec.front() << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // - back() => gibt letztes Element zurueck
    std::cout << "Letztes Element mit back(): " << vec.back() << std::endl;
    std::cout << "---------------------------------" << std::endl;

}

#endif //DATEN_CONTAINER_VECTOR_H
