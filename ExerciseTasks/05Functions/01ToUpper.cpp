#include <iostream>

using std::cout;
using std::cin;
using std::endl;

char toUpperCase(char& letr) {
    int dist = letr - 'a';
    
    if (letr >= 'a' && letr <= 'z') {
        return 'A' + dist;
    } else if (letr >= 'A' && letr <= 'Z') {
        return letr;
    }

    cout << "Invalid character.";
    return char(0);
}

int main () {
    char letter;
    cout << "Enter a letter: ";

    cin >> letter;

    cout << toUpperCase(letter) << endl;

    return 0;
}