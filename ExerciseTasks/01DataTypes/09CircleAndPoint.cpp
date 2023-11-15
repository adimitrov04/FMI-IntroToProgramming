#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Given coordinates x and y as input, as well as the radius of a circle, 
determine whether the point A(x,y) lays on the circle with radius r.
*/

int main () {
    int r = 0;
    cout << "Enter circle radius: ";
    cin >> r;
    
    int x, y;
    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    int distance = sqrt((x * x) + (y * y));

    //cout << "Distance = " << distance << endl;
    double eps = 0.0001;
    bool isOnCircle = 0;
    
    if (abs(distance - r) < eps) {
        isOnCircle = 1;
    } else {
        isOnCircle = 0;
    }

    cout << isOnCircle << endl;

    return 0;
}