#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Given coordinates x and y as input, output the distance of the point
A(x,y) form the origin O(0,0).
*/

int main () {
    int x, y;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    int distance = sqrt((x * x) + (y * y));

    cout << "Distance d = " << distance << endl;

    return 0;
}