//
// Created by lukas on 18.03.2022.
//

#ifndef LESSON_3_TYPE_H
#define LESSON_3_TYPE_H

// https://en.cppreference.com/w/cpp/language/enum
// https://arne-mertz.de/2016/04/strings-vs-enumerators/

// Eine "Enumeration" (Aufzählung) ist ein eindeutiger Typ, 
// dessen Wert auf einen Wertebereich beschränkt ist,
// welcher mehrere ausdrücklich benannte Konstanten ("enumerators")
// enthalten kann.

enum Type {
    Fire, // = 0
    Water, // = 1
    Earth, // = 2
    Ice, // = 3
    Normal, // = 4
    Flight // = 5
};

#endif //LESSON_3_TYPE_H
