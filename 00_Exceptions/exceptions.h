//
// Created by lukas on 03.04.2022.
//



#ifndef EXCEPTIONS_EXCEPTIONS_H
#define EXCEPTIONS_EXCEPTIONS_H

#include <exception>

class ProgramException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class InvalidIndexException : public ProgramException{
public:
    using ProgramException::ProgramException;
};

class InvalidArgumentException : public ProgramException{
public:
    using ProgramException::ProgramException;
};

#endif //EXCEPTIONS_EXCEPTIONS_H
