//
// Created by lukas on 11.02.2022.
//

#ifndef GRUNDLAGEN_UEBERLADUNG_H
#define GRUNDLAGEN_UEBERLADUNG_H


#include <iostream>


void print(int value){
    std::cout << "int: " << value << std::endl;
}

void print(double value){
    std::cout << "double: " << value << std::endl;
}

void print(const std::string& value){

    std::cout << "string: " << value << std::endl;
}


#endif //GRUNDLAGEN_UEBERLADUNG_H
