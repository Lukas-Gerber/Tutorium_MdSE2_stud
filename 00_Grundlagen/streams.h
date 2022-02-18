//
// Created by lukas on 11.02.2022.
//

#ifndef GRUNDLAGEN_STREAMS_H
#define GRUNDLAGEN_STREAMS_H


#include <iostream>

void streams(std::string& eingabe){
    // 2. Ausgeben
    std::cout << "\n1.Ausgabe\n----------------------------" << std::endl;
    // std:: steht für die "Standard Library", in dieser finden wir auch das Objekt "cout" welches stdout repräsentiert
    // https://en.cppreference.com/w/cpp/io/basic_ostream

    // Datentypen, welche nicht primitiv sind, werden über std:: definiert, string ist z.B. eine Aneinanderreihung des primitiven Datentyps char
    // int ist ein primitiver Datentyp und kann daher direkt verwendet werden.
    // C++ Datentypen: https://www.geeksforgeeks.org/c-data-types/

    // das const Keyword spezifiziert eine Variable als konstant und teilt dem Compiler mit, dass diese nicht verändert werden darf!
    const std::string welcome = "Hello, DiBSE!";
    int number;

    // beim Ausführen folgender Zeile wird daher ein Fehler ausgegeben: operand types are 'const string', da die Variable nicht veränder werden kann.
    // welcome = "test"; // auskommentiert da sonst der restliche Code nicht läuft

    // << ist der Output Operator
    // endl repräsentiert einen Zeilenumbruch inkl. flush des ouput buffers
    std::cout << welcome << std::endl;
    std::cout << "Zeile 2!";

    // Für einen Zeilenumbruch kann auch \n verwendet werden, jedoch ist hier kein flush des buffers gegeben!
    // mit einem doppelten \ kann das \n auskommentiert werden, sodass es in der Ausgabe angezeigt wird.
    std::cout << "\nZeile 3 mittels \\n!" << std::endl;



    // 2. Einlesen eines inputs
    std::cout << "\n2.Einlesen\n----------------------------" << std::endl;
    // Mittels dem Objekt cin welches von stdin liest können eingaben gelesen werden
    // https://en.cppreference.com/w/cpp/io/basic_istream

    //std::string eingabe;

    std::cout << "Eingabe: ";
    std::cin >> eingabe;
    //std::getline(std::cin, eingabe);
    std::cout << "Ausgabe: " << eingabe << std::endl;

    // Werden mit dieser Methode jedoch mehrere Wörter eingegeben wird nur das erste Wort vor dem Leerzeichen gespeichert!
    // Mehrere Wörter müssen mittels der Zeile std::getline(std::cin, eingabe); geholt werden.

}



#endif //GRUNDLAGEN_STREAMS_H
