#include <iostream>
#include <cmath>

using namespace std;

/* TASK DESCRIPTION:
--------------------------------------------
Read the coordinates of a point U(x, y) in a Descartes coordinate system as input,
and determine which zone the point lays in on a given figure (in task description).

The zones are:
Red, Green, Pink, Yellow, Blue, Purple and Grey. 

If the given point lays on the contour line, output "Point U(x, y) is on the edge." 
If the point lays in no zone and isn't on the line, then output should be 
"Point U(x, y) is outside."

The coordinates of the following points are known:
H(-2, -6), E(2, -6), F(-1, 5), I(1, 5), O(0, 0), L(4, 0);
As well as the abscissa:
A(3, _), B(3, _), C(-3, _), D(-3, _);

The accuracy of the input and output numbers should be 3 decimal places (0.000).
--------------------------------------------
*/


bool isNearEnough (double coord_1, double coord_2) {
    const double Eps = 0.001; // Accuracy constant

    if (abs(coord_1 - coord_2) < Eps) {
        return true;
    }

    return false;
}

bool isBetween (double num, double lowerLim, double upperLim, bool closed = 0) {
    if (closed) {
        if ((num < upperLim || isNearEnough(num, upperLim)) && (num > lowerLim || isNearEnough(num, lowerLim))) {
            return true;
        } else {
            return false;
        }
    } else {
        if (num < upperLim && num > lowerLim) {
            return true;
        } else {
            return false;
        }
    }    
}

double distance (double x1, double y1, double x2, double y2) {
    double dist = 0;
    dist = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

    return dist;
}

double linearFunc (double slope, double x, double b = 0) {
    double y = slope * x + b;

    return y;
}

int main () {
    short unsigned int zoneID = -1;
    // 0 - Outside; 1 - Edge; 2 - Red; 3 - Green; 4 - Pink; 5 - Yellow; 6 - Blue; 7 - Purple; 8 - Grey

    //Point definition:
    const int xO = 0, yO = 0;    // O(0, 0)
    const int xF = -1, yF = 5;   // F(-1, 5)
    const int xI = 1, yI = yF;   // I(1, 5)
    const int xL = 4, yL = yO;   // L(4, 0)
    const int xQ = xO, yQ = 6;   // Q(0, 6)
    const int xJ = xO, yJ = -yQ; // L(0, -6)
    
    const int xH = -2, yH = -6; // H(-2, -6)
    const int xE = 2, yE = yH;  // E(2, -6)
    const int xG = xH, yG = -7; // G(-2, -7)
    const int xP = xE, yP = yG; // P(2, -7)

    const double rad = xL - xO; // Radius OL = 4.0

    const double xA = 3, yA = -sqrt((rad * rad) - (xA * xA)); // A(3, yA)
    const double xB = 3, yB = -yA;                            // B(3, -yA)
    const double xC = -3, yC = sqrt((rad * rad) - (xC * xC)); // C(3, yC)
    const double xD = -3, yD = -yC;                           // D(3, -yC)

    double middleSlope = yB / xB; // Defining the slope of the function described by the segment DB.

    double xU, yU;
    cout << "Enter x: ";
    cin >> xU;

    cout << "Enter y: ";
    cin >> yU;

    if (isBetween(yU, yJ, yQ, 1) && isNearEnough(xU, xO)) {
        zoneID = 1; // Point lays on the segment QJ.
    } else if (isNearEnough(distance(xO, yO, xU, yU), rad)) {
        zoneID = 1; // Point lays on circle.
    } else if (distance(0, 0, xU, yU) < rad) {
        // If we are inside the circle
        if (isNearEnough(xU, xA) && isBetween(yU, yA, yB, true)) {
            zoneID = 1; // Point lays on AB.
        } else if (isNearEnough(xU, xC) && isBetween(yU, yD, yC, true)) {
            zoneID = 1; // Point lays on CD.
        } else if (isNearEnough(yU, linearFunc(middleSlope,xU))) {
            zoneID = 1; // Point lays on DB.
        } else if (isBetween(xU, 0, xL)) {
            if (xU > xB) {
                zoneID = 7; // Point is in purple zone.
            } else if (yU > linearFunc(middleSlope, xU)) {
                zoneID = 3; // Point is in green zone.
            } else {
                zoneID = 5; // Point is in yellow zone.
            }
        } else if (isBetween(xU, xC, 0)) {
            if (isNearEnough(yU, linearFunc(-middleSlope, xU))) {
                zoneID = 1; // Point lays one CO.
            } else if (yU > linearFunc(-middleSlope, xU)) {
                zoneID = 2; // Point is in red zone.
            } else if (yU < linearFunc(middleSlope, xU)) {
                zoneID = 6; // Point is in blue zone.
            } else {
                zoneID = 4; // Point is in pink zone.
            }
        }
    } else if (isNearEnough(yU, yF) && isBetween(xU, xF, xI, 1)) {
        zoneID = 1; // Point lays on FI.
    } else if (isNearEnough(xU, xH) && isBetween(yU, yG, yH, 1)) {
        zoneID = 1; // Point lays on HG.
    } else if (isNearEnough(xU, xE) && isBetween(yU, yP, yE, 1)) {
        zoneID = 1; // Point lays on EP.
    } else if (isNearEnough(yU, yH) && isBetween(xU, xH, xE, 1)) {
        zoneID = 1; // Point lays on HE.
    } else if (isNearEnough(yU, yG) && isBetween(xU, xG, xP, 1)) {
        zoneID = 1; // Point lays on GP.
    } else if (isBetween(xU, xH, xE) && isBetween(yU, yG, yH)) {
        zoneID = 8; // Point is in grey zone.
    } else {
        zoneID = 0; // Point does not lay anywhere.
    }

    switch (zoneID) {
        case 0:
        cout << "Outside" << endl; break;

        case 1:
        cout << "On the edge" << endl; break;

        case 2:
        cout << "Red" << endl; break;
        
        case 3:
        cout << "Green" << endl; break;
        
        case 4:
        cout << "Pink" << endl; break;
        
        case 5:
        cout << "Yellow" << endl; break;
        
        case 6:
        cout << "Blue" << endl; break;
        
        case 7:
        cout << "Purple" << endl; break;
        
        case 8:
        cout << "Grey" << endl; break;

        default:
        cerr << "ERROR!" << endl; break;
    }

    return 0;
}