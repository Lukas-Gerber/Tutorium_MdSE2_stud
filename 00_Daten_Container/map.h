//
// Created by lukas on 18.04.2022.
//

#ifndef DATEN_CONTAINER_MAP_H
#define DATEN_CONTAINER_MAP_H

#include <iostream>
#include <map>

void print_map(std::string comment, const std::map<std::string, int> &m) {
    std::cout << comment;

    for (const auto &n: m) {
        std::cout << n.first << " = " << n.second << "; ";
    }

    std::cout << '\n';
}


void map() {
    // Container in der Standardbibliothek


    // 1.2 Map (https://en.cppreference.com/w/cpp/container/map)

    // In dem header #include <map> zu finden

    // Erzeugen eines Map
    // Zwischen den <>-Klammern werden die Datentypen der Inhalte der Map angegeben
    // mapVar ist in diesem Beispiel der Variablenname
    std::map<std::string, int> mapVar = {{"key1", 10},
                                         {"key2", 20},
                                         {"key3", 30},
                                         {"key4", 40},
                                         {"key5", 50}};
    print_map("Inhalt: ", mapVar);
    std::cout << "---------------------------------" << std::endl;

    // Wichtigste Funktionen für die Map

    // size() => gibt aktuelle Groesse zurück
    std::cout << "size(): " << mapVar.size() << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // - mapVar[KEY] => Zugriff auf den Wert vom angegebenen Key
    std::cout << "Zugriff auf Wert von Key 3 = Wert " << mapVar["key3"] << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // Was passiert wenn wir nach einem Key suchen der nicht existiert?
    // Der key wird angelegt!
    std::cout << "Was wenn key nicht existiert? " << std::endl;
    int a = mapVar["key100"];
    std::cout << "Suchen nach Wert bei Key100 mittels mapVar['key100']: " << a << std::endl;
    print_map("Map nach suche bei Key100: ", mapVar);
    std::cout << "---------------------------------" << std::endl;

    // - at(KEY), Suchen vom Wert des angegebenen Keys (mit Grenz-Ueberprüpfung)
    // int b = mapVar.at("key200"); // auskommentieren um Fehlermeldung zu sehen

    // - mapVar[KEY] = WERT, ueberschreiben vom Wert des angegebenen Keys
    mapVar["key1"] = 23;
    print_map("Nach Ueberschreibung bei Key1: ", mapVar);
    std::cout << "---------------------------------" << std::endl;

    // einfuegen von key-Value paaren
    // mehrere Varianten
    mapVar["key60"] = 150;
    // - insert()
    mapVar.insert({"key61", 151});
    mapVar.insert(std::pair<std::string, int>("key62", 152));
    print_map("Nach einfügen von Key 60,61,62: ", mapVar);
    std::cout << "---------------------------------" << std::endl;

    // - erase(KEY) => löscht key-Value Paar bei angegebenem Key
    mapVar.erase("key100");
    print_map("Löschen des key-value Paares bei Key100: ", mapVar);
    std::cout << "---------------------------------" << std::endl;

    // - begin() => gibt erstes key-Value Paar zurueck
    std::cout << "Erstes Element mit begin(): " << mapVar.begin()->first << std::endl;
    std::cout << "---------------------------------" << std::endl;

    // - end() => gibt einen Iterator bis zum Ende zurück
    std::cout << "end() Iterator mit for-Schleife: ";
    for (auto it = mapVar.begin(); it != mapVar.end(); it++) {
        std::cout << it->first << " = " << it->second << "; ";
    }
    std::cout << "\n---------------------------------" << std::endl;

}

#endif //DATEN_CONTAINER_MAP_H
