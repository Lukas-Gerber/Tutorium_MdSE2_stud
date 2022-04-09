#include <iostream>

class Box {
public:
    int breite;

    Box(int breite) : breite(breite) {}

};


int main() {

    {
        int a;

        int b = 3;
        int *p = &b;
    }


    int *p = new int;
    Box *b1 = new Box(10);
    Box *b2 = b1;

    return 0;

    // Hands on https://pythontutor.com/cpp.html#mode=edit

}
