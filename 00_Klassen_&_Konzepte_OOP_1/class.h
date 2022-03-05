//
// Created by lukas on 26.02.2022.
//

#ifndef KONZEPTE_OOP_CLASS_H
#define KONZEPTE_OOP_CLASS_H


#include <string>

// Klassen sind standardmäßig public
struct Struct {
    std::string structName = "Struct";
};

// Klassen sind standardmäßig private
class Class {

    std::string className = "Class";

    // Um auf private variablen zugreifen zu können, müssen sogenannte Getter & Setter unter der public Sichtbarkeit erstellt werden
public:
    std::string getName(){
        return className;
    }

    // Der this-Pointer ist ein Pointer, welcher auf die Adresse des "eigenen" Objektes verweist.
    // https://en.cppreference.com/w/cpp/language/this
    // Somit kann über das this-keyword auf die eigenen Parameter zugegriffen werden

    void setName(std::string name){
        this->className = name;
    }

    void print(){
        std::cout << "Der name dieser Klasse ist " << this->className << std::endl;
    }

};

class PublicClass {
public:
    std::string publicClassName = "Public Class";
};


#endif //KONZEPTE_OOP_CLASS_H
