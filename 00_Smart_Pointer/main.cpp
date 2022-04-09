#include <iostream>
#include <memory>


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
};


int main() {

    // Smart Pointer
    // Im Header <memory> definiert
    // 3 Arten von Smart Pointer:
    // - unique
    // - shared
    // - weak

    std::cout << "Unique pointer" << std::endl;
    std::cout << "------------------" << std::endl;
    // 1. Unique Pointer
    // können nicht kopiert werden
    // Objekt wird am Ende des Gültigkeitsbereiches automatisch zerstört

    {
        std::unique_ptr<Entity> uptr1(new Entity);

        // 1.1 Kopieren eines unique pointer - TEST
        // Bei dem folgenden Versuch den Pointer zu kopieren, wird eine Fehlermeldung angezeigt:
        // "Call to deleted Constructor of ..."
        // Der Grund hierfür ist, dass der Kopierkonstruktor bei unique pointern auf delete gesetzt wurde
        // und dadurch nicht aufgerufen werden kann
        ////std::unique_ptr<Entity> copy = uptr1; // auskommentieren um die Fehlermeldung ansehen zu können


        // bevorzugte Art einen unique pointer zu erstellen, da sicherer und wenn Konstruktor eine Exception werfen sollte,
        // entsteht kein wilder Zeiger ohne Referenz
        std::unique_ptr<Entity> uptr2 = std::make_unique<Entity>();
    }

    std::cout << "------------------" << std::endl;
    std::cout << "Shared pointer" << std::endl;
    std::cout << "------------------" << std::endl;
    // 2.shared Pointer
    // kann kopiert werden
    // verwendet Reference Counting

    {
        // Hier ist der Unterschied der zwei Vorgehensweisen größer:
        // Wenn man new aufruft werden ZWEI heap-allocations gemacht:
        // - der Kontrollblock für z.B. Reference counting
        // - das Objekt welches gemanaged werden soll
        std::shared_ptr<Entity> sptr1(new Entity);

        // Bei make_shared wird nur EINE heap-allocation aufgerufen
        // eine genauere Erklärung hierzu unter: https://stackoverflow.com/a/20895705
        std::shared_ptr<Entity> sptr2(std::make_shared<Entity>());
        // Reference count wird auf 1 gesetzt
        std::cout << "sptr2-count: " << sptr2.use_count() << std::endl;

        {
            // Kopieren von shared pointern
            // Reference count wird um 2 erhöht, da sptr3 & sptr4 hinzukommen (Kopie von sptr2)
            std::shared_ptr<Entity> sptr3 = sptr2;
            std::cout << "sptr2-count: " << sptr2.use_count() << std::endl;

            std::shared_ptr<Entity> sptr4 = sptr2;
            std::cout << "sptr2-count: " << sptr2.use_count() << std::endl;

            // end of scope sptr3 & sptr4 werden zerstört
            // Reference count wird um 2 verringert
        }
        std::cout << "sptr2-count: " << sptr2.use_count() << std::endl;

    }
    // Der Reference count sinkt auf 0 und das Objekt wird zerstört


    std::cout << "------------------" << std::endl;
    std::cout << "Weak pointer" << std::endl;
    std::cout << "------------------" << std::endl;
    // 3.weak Pointer
    // erhöht nicht den Reference Count
    // Bei Objektzerstörung Pointer automatisch auf NULL gesetzt
    {
        std::shared_ptr<Entity> sptr5 = std::make_shared<Entity>();
        std::cout << "sptr2-count: " << sptr5.use_count() << std::endl;
        // std::shared_ptr<Entity> sptr6 = sptr5; // shared pointer erhöht den reference count um 1
        std::weak_ptr<Entity> wptr1 = sptr5; // weak pointer erhöht den reference count nicht!
        std::cout << "sptr2-count: " << sptr5.use_count() << std::endl;
    }

    std::cout << "------------------" << std::endl;
    std::cout << "Beispiel aus der Vorlesung zu Weak pointer" << std::endl;
    std::cout << "------------------" << std::endl;

    {
        std::weak_ptr<Entity> ptr1;
        {
            std::shared_ptr<Entity> ptr2(new Entity);
            std::cout << "ptr2-count: " << ptr2.use_count() << std::endl;
            ptr1 = ptr2;
            std::cout << "ptr1-count: " << ptr2.use_count() << std::endl;
            std::cout << "ptr2-count: " << ptr2.use_count() << std::endl;
        }
        std::cout << "ptr1-count: " << ptr1.use_count() << std::endl;

        std::shared_ptr<Entity> ptr3 = ptr1.lock();
        if (!ptr3) {
            std::cout << "ptr3 evaluates to false! Reference count was 0 and Object got destroyed!" << std::endl;
        }
    }

    return 0;
}
