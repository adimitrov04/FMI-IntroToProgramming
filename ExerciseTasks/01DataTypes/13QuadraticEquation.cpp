#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Make a quadratic euqation calculator given a, b and c as inputs.
*/

int main () {
    int a, b, c;

    cout << "Enter a: ";
    cin >> a;
    
    cout << "Enter b: ";
    cin >> b;
    
    cout << "Enter c: ";
    cin >> c;

    double discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0) {
        cout << "No real solutions to " << a << "x^2 + (" << b << ")x + (" << c << ")" << endl;
    } else if (discriminant == 0) {
        double x = -(b / (2 * a));
        
        cout << a << "x^2 + (" << b << ")x + (" << c << ")" << endl;
        cout << "x1,2 = " << x << endl;
    } else {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        
        cout << a << "x^2 + (" << b << ")x + (" << c << ")" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    return 0;
}