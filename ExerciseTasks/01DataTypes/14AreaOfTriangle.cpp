#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Take 3 sides of a triangle as inputs and calculate its area.
*/

int main () {
    double a, b, c;
    cout << "Enter side a: ";
    cin >> a;

    cout << "Enter side b: ";
    cin >> b;

    cout << "Enter side c: ";
    cin >> c;

    double semiper = (a + b + c) / 2;
    double area = sqrt(semiper * ((semiper - a) * (semiper - b) * (semiper - c)));

    cout << "Area S: " << area << " cm^2" << endl;

    return 0;
}
