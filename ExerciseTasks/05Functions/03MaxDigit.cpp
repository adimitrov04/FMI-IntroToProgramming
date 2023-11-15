#include <iostream>

using std::cout;
using std::cin;
using std::endl;

short maxDigit (int num) {
    unsigned int maxDig = 0;

    unsigned int currentDig;
    for (int stepBack = 1, stepForw = 10; stepBack < num; stepBack *= 10, stepForw *= 10) {
        currentDig = (num % stepForw) / stepBack;
        if (currentDig == 9) {
            maxDig = 9;
            break;
        } else if (currentDig > maxDig) {
            maxDig = currentDig;
        }
    }

    return maxDig;
}

int main () {
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;

    cout << "The largest digit of " << num << " is " << maxDigit(num) << endl;

    return 0;
}