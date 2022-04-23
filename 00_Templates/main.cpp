#include <iostream>

// Templates

// Implementieren von parametrisierbarem Code
// Einsetzen der entsprechenden Variable findet zur Compile-Time statt

// Templates werden mit den keywort "template" angegeben
// zwischen den <>-Klammern werden die Variablen definiert
// Bei der Codegenerierung werden die Parameternamen durch die konkreten Werte ersetzt

template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T sum(T array[], int n)
{
    T result = 0;
    for (int i = 0; i < n; ++i) {
        result += array[i];
    }
    return result;
}


int main() {

    std::cout << myMax<int>(3,7) << std::endl;
    std::cout << myMax<double>(5.0,2.0) << std::endl;
    std::cout << myMax<char>('g','e') << std::endl;


    int array1[10] = {1,2,3,4,5,6,7,8,9,10};
    int result = sum<int>(array1, 10);

    std::cout << "Int: "<< result << std::endl;


    float array2[10] = {1.0,2.0,3.0,4.5,5.6,6.9,7.2,8.1,9.7,10.3};
    float result2 = sum<float>(array2, 10);

    std::cout << "Float: " << result2 << std::endl;

    // Template Argument Deduction
    // Weglassen der konkreten Eingabeparameter in den <>-Klammern
    // Compiler versucht automatisch den richtigen Wert abzuleiten

    double array3[10] = {1.0,2.0,3.0,4.5,5.6,6.9,7.2,8.1,9.7,10.3};
    double result3 = sum(array3, 10);

    std::cout << "Double: " << result3 << std::endl;

    return 0;
}
