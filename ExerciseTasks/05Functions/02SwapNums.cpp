#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void mySwap (int& a, int& b) {
    int c = a;
    a = b;
    b = c;

    cout << a << ", " << b << endl;
}

int main () {
    int a, b;
    
    cin >> a;
    cin >> b;

    mySwap(a, b);

    return 0;
}