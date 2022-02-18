#include <iostream>

void foo(int input);

void bar(int &input);

int main() {

    // 1. Pointer
    // kurze Wiederholung
    // Ein Pointer ist eine Variable welche eine Memoryadresse einer anderen Variable enthält.
    // Der Pointer kann so geändert werden, dass dieser auf eine andere Variable des gleichen Typs zeigt

    void *ptr1 = nullptr; // nullpointer ist ein pointer zu keiner gültigen Memoryadresse
    std::cout << "Adress of ptr1: " << ptr1 << "\n" << std::endl;

    int var = 8;
    int *ptr2 = &var;

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Adress of var: " << &var << std::endl; // Memoryadress von var
    std::cout << "Value of ptr2: " << ptr2 << std::endl; // gespeicherter Inhalt von ptr2
    std::cout << "Deref. value of ptr2: " << *ptr2 << std::endl; // gespeicherter Wert in der Memoryadresse

    // Veranschaulichung in Clion
    // Breakpoint in Zeile 16 & 28 setzen
    // Debugmodus starten
    // im Menü am unteren Rand auf ptr2 rechtsclicken und "Show in Memory View" drücken
    // Die Memory View öffnet sich und der Wert 8 ist in der Memory View ersichtlich
    // Bei drücken auf "Step over" im Debug Menü wird der Code weiter ausgeführt

    *ptr2 = 10;

    // Hier ist nun ersichtlich wie sich der an der Adresse gespeicherte Wert von 8 auf 10 geändert hat. Die Adresse ist gleich geblieben



    // 2. Reference-Semantic & Value-Semantic
    // Eine Referenz ist ein Alias für eine bereits existierende Variable, eine Referenz kann
    // nach Initialisierung nicht auf eine andere Variable zeigen.

    // Video zur Veranschaulichung:
    // https://external-preview.redd.it/cHNSyYNhvPWK1GUT4iSkwjintUqtc0F-gx2h2GcTB1E.gif?format=mp4&s=24d07f95fbed7d440b8cefba3f65d409aa7e3411

    std::cout << "\nValue-Semantic" << std::endl;
    // Wir erstellen zwei Variablen b und bref
    // b wird mit 5 initialisiert und bref mit b
    // bei der Zeile "int bref = b" wird der Wert von b KOPIERT und bref damit initialisiert
    // ändern wir nun bref auf 2 ändert sich b nicht, da keine Verbindung zwischen den Varibalen besteht

    int b = 5;
    int bref = b;
    bref = 2;

    std::cout << "VS - Value of b: " << b << std::endl;
    std::cout << "VS - Value of bref: " << bref << std::endl;

    std::cout << "\nReference-Semantic" << std::endl;
    // Im zweiten Versuch erstellen wir wieder zwei Variablen a und aref
    // die Variablen werden wie oben beschrieben initialisiert
    // in der Zeile "int& bref = a" wird eine REFERENZ auf die Variable a erstellt,
    // d.h. dei Variablen sind miteinander "verbunden", da aref nun den Wert von a referenziert.
    // Wird nun aref überschrieben, so wird auch der Wert in a geändert da aref eine Referenz auf a ist!


    int a = 5;
    int &aref = a;
    aref = 2;

    std::cout << "RS - Value of a: " << a << std::endl;
    std::cout << "RS - Value of aref: " << aref << std::endl;


    // 3. Beispiel anhand von Funktionen
    std::cout << "\nFunktionsbeispiel Call-by-Value" << std::endl;

    int test = 0;
    std::cout << "main() start: " << test << std::endl;
    foo(test);
    std::cout << "main() end: " << test << std::endl;


    std::cout << "\nFunktionsbeispiel Call-by-Reference" << std::endl;

    int test2 = 0;
    std::cout << "main() start: " << test2 << std::endl;
    bar(test2);
    std::cout << "main() end: " << test2 << std::endl;

    return 0;
}

void foo(int input) {
    std::cout << "foo() start: " << input << std::endl;
    // Übergabe der Variable mittels Value-Semantic,
    // der Gültigkeitsbereich der Variable input endet mit durchlauf der Funktion
    input = 1;
    std::cout << "foo() end: " << input << std::endl;
}

void bar(int &input) {
    std::cout << "foo() start: " << input << std::endl;
    // Übergabe der variable als Referenz, das "Original" wird dadurch verändert
    input = 1;
    std::cout << "foo() end: " << input << std::endl;
}
