//
// Created by lukas on 27.02.2022.
//

#ifndef KONZEPTE_OOP_KAPSELUNG_H
#define KONZEPTE_OOP_KAPSELUNG_H


#include <string>

class Kapselung {
// Kapselung
    // Mittels Kapselung werden interne Details vor der "Außenwelt" versteckt
    // Es gilt zu vermeiden, dass illegale Zustände entstehen
    // Mit Getter & Setter kann auf diese "versteckten" Parameter zugegriffen werden
    // Es ist jedoch zu beachten, dass vor dem Zugriff z.B. mittels Setter eine Überprüfung auf Richtigkeit erfolgen muss,
    // ansonsten könnten illegale Zustände die Folge sein!
private:
    std::string name = "Max Mustermann";
protected:
    int age = 0;
public:

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        // Überprüfung auf Richtigkeit der Eingabe und anschließendes setzen des Wertes
        if(age > 0) {
            this->age = age;
        }
        // Hier sollte eine Rückmeldung bei falscher Eingabe passieren, das überlasse ich eurer Fantasie ;)
    }

};

#endif //KONZEPTE_OOP_KAPSELUNG_H
