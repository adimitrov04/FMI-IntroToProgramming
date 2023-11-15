#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

/*
Task:
Read a sum of money from the console in BGN and output its equivalent into
USD, EUR and JPY.
*/

int main () {
    double bgn = 0.0;
    cout << "Enter sum in BGN: ";
    cin >> bgn;

    double usd = round(bgn * 54) / 100.00;
    double eur = round(bgn * 51) / 100.00;
    long double jpy = (bgn * 8073) / 100.00;

    cout << "USD: " << usd << ' ' << endl;
    cout << "EUR: " << eur << ' ' << endl;
    cout << "JPY: " << jpy << ' ' << endl;
    
    return 0;
}