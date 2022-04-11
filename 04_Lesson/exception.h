//
// Created by lukas on 27.03.2022.
//

#ifndef LESSON_4_EXCEPTION_H
#define LESSON_4_EXCEPTION_H

#include <exception>

class GameException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class StorageFullException : public GameException {
public:
    using GameException::GameException;
};

class InvalidArgument : public GameException {
public:
    using GameException::GameException;
};

class InvalidIndexException : public GameException {
public:
    using GameException::GameException;
};

class InvalidAttackException : public GameException {
public:
    using GameException::GameException;
};

#endif //LESSON_4_EXCEPTION_H
