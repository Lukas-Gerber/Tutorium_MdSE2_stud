//
// Created by lugerber on 21.03.2022.
//

#ifndef LESSON_4_EXCEPTIONS_H
#define LESSON_4_EXCEPTIONS_H

#include <exception>
#include <stdexcept>

class GameException : public std::runtime_error  {
public:
    using std::runtime_error::runtime_error;
};

class InvalidIndexException : public GameException  {
public:
    using GameException::GameException;
};

class AttacksFullException : public GameException  {
public:
    using GameException::GameException;
};

class InvalidArgument : public GameException  {
public:
    using GameException::GameException;
};

class InvalidAttack : public GameException  {
public:
    using GameException::GameException;
};



#endif //LESSON_4_EXCEPTIONS_H
