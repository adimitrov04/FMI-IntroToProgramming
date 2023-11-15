#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Find the n-th member of a geometric progression given the first member,
the quotient and n.
*/

int main () {
    int firstMember, q, n;

    cout << "Enter a1: ";
    cin >> firstMember;
    
    cout << "Enter q: ";
    cin >> q;
    
    cout << "Enter n: ";
    cin >> n;

    int nthMember = firstMember * pow(q,(n - 1));

    cout << "a" << n << " = " << nthMember << endl; 

    return 0;
}