#include <iostream>


class Box {

public:
    int laenge;
    int breite;
    int hoehe;

    Box() {}

    Box(int laenge, int breite, int hoehe) :
            laenge(laenge), breite(breite), hoehe(hoehe) {
        std::cout << "Konstruktor: " << *this;
    }

// Friend
    friend std::ostream &operator<<(std::ostream &out, const Box &b);
// Operatorenüberladung in Klasse
/*    Box operator+(const Box &b) {
        Box box;
        box.laenge = this->laenge + b.laenge;
        box.breite = this->breite + b.breite;
        box.hoehe = this->hoehe + b.hoehe;
        return box;
    }*/
};

// Operatorenüberladungen global
Box operator+(const Box &a, const Box &b) {
    Box box;
    box.laenge = a.laenge + b.laenge;
    box.breite = a.breite + b.breite;
    box.hoehe = a.hoehe + b.hoehe;
    return box;
}

std::ostream &operator<<(std::ostream &out, const Box &b) {
    out << "L:" << b.laenge << " B:" << b.breite << " H:" << b.hoehe << std::endl;
    return out;
}



int main() {

    // Operatorenüberladung
    // https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

    Box box1(5, 5, 10);
    Box box2(5, 5, 10);
    Box box3;

    box3 = box1 + box2;

    std::cout << "Ausgabe1 = L:" << box3.laenge << " B:" << box3.breite << " H:" << box3.hoehe << std::endl;
    std::cout << "Ausgabe2 = " << box3 << std::endl;

    return 0;
}
