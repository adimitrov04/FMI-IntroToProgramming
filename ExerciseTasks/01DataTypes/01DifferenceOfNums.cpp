#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Task:
Read two numbers from console and output their difference.
*/

int main () {
    int a = 0;
    cout << "Enter number A: ";
    cin >> a;
    
    int b = 0;
    cout << "Enter number B: ";
    cin >> b;

    cout << (a - b) << endl;

    return 0;
}
