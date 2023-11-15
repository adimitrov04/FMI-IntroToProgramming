#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Task:
Read 3 numbers from console and output their average.
*/

int main () {
    double a = 0;
    cin >> a;

    double b = 0;
    cin >> b;
    
    double c = 0;
    cin >> c;

    double avg = (a + b + c) / 3;

    cout << "Average is: " << avg << endl;

    return 0;
}