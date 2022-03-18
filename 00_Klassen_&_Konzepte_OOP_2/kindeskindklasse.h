//
// Created by lugerber on 16.03.2022.
//

#ifndef KLASSEN___KONZEPTE_OOP_2_KINDESKINDKLASSE_H
#define KLASSEN___KONZEPTE_OOP_2_KINDESKINDKLASSE_H


#include <iostream>
#include "kindklasse1.h"

class Kindeskindklasse : public Kindklasse1{
private:

    int index;

public :

    using Kindklasse1::Kindklasse1;

    Kindeskindklasse(const std::string &konstruktorName, int konstruktorAge, int index)
            : Kindklasse1(konstruktorName, konstruktorAge), index(index){}

    virtual ~Kindeskindklasse() {}

    void foo(){
        std::cout << "Calling Kindeskindklasse::foo()" << std::endl;
    }

    virtual void bar(){
        std::cout << "Calling Kindeskindklasse::bar()" << std::endl;
    }

    int getIndex() const {
        return index;
    }

};


#endif //KLASSEN___KONZEPTE_OOP_2_KINDESKINDKLASSE_H
