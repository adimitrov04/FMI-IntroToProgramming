#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Task:
Output the number values of '1', '9' and 'b'. Also output the value of '0'.
*/

int main () {
    char one = '1';
    char nine = '9';
    char bee = 'b';
    char zero = '0';

    cout << "\'1\': " << int(one) << endl;
    cout << "\'9\': " << int(nine) << endl;
    cout << "\'b\': " << int(bee) << endl;
    cout << "\'0\': " << int(zero) << endl;

    return 0;
}