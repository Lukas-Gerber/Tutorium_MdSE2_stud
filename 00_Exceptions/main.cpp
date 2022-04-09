#include <iostream>
#include "exceptions.h"

class Entity {
public:
    Entity() {
        std::cout << "Created Entity!" << std::endl;
    }

    virtual ~Entity() {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void print() {
        std::cout << "print" << std::endl;
    }

    void errorIndexFunc() {
        //errorArgumentFunc();
        throw InvalidIndexException("Entity::errorIndexException(): Invalid Index");
    }

    void errorArgumentFunc() {
        throw InvalidArgumentException("Entity::errorIndexException(): Invalid Argument");

    }

    double division(double a, double b) {
        if (b == 0) {
            throw "Division by zero!";
        }
        return (a / b);
    }
};




int main() {

    // Exceptions
    // Dienen zur Fehlerbehandlung, sodass ein sicherer und konsistenter Zustand des Programms gewährleistet ist
    // 3 Schritte:
    // - Erkennen von Fehlern
    // - Weitermelden von Fehlern
    // - Beheben von & Aufräumen nach Fehlern

    // Exceptions können in jedem codeblock mit dem "throw"-keyword geworfen werden
    // Mittels try-catch-Blöcken können Exceptions gefangen werden
    // im try-Teil wird der Code gegeben, welcher "getestet" werden soll
    // im catch-Teil werden die entsprechenden exceptions abgefangen, hier wird auch angegeben welchen Typ die zu fangende exception hat


    Entity *entity = new Entity();

    try {
        entity->print();

        auto result = entity->division(1, 0);
        // Wird bei b eine 0 eingesetzt, wird eine Exception geworfen
        // Diese wird von dem catch-All block abgefangen, wenn kein anderer geeigneter catch block existiert
        std::cout << "Result: " << result << std::endl;

        //entity->errorArgumentFunc();
        entity->errorIndexFunc();


        // es können mehrere catch-blöcke hintereinander angeführt werden
    } catch (InvalidIndexException &e) { // Hier werden Exceptions vom typ InvalidIndexException gefangen
        std::cerr << "Error: " << e.what() << std::endl;

    } catch (InvalidArgumentException &e) {
        std::cerr << "Error: " << e.what() << std::endl;

/*    } catch (const char *msg) { // auskommentiern um exception der Null-Division zu fangen
        std::cerr << "Error: " << msg << std::endl;*/

    } catch (...) { // Catch-All Block
        std::cerr << "Fehler" << std::endl;
    }

    delete entity;


}
