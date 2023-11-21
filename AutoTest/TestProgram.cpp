#include <iostream>
#include <cmath>

using namespace std;

const int SAMPLE_SIZE = 12;
const int errCode = -1;

double testInX[SAMPLE_SIZE] =      {1,  2, -1, -1, 0,      0,     0, -2, -3.9999, 3.56,   -1, 0};
double testInY[SAMPLE_SIZE] =      {1, -1,  1, -1, 6.0001, 0, -7.01,  2,       0,    1, -6.5, 3};
int expectedOutputs[SAMPLE_SIZE] = {3,  5,  2,  6, 1,      1,     0,  2,       1,    7,    8, 7};


// ------------------- CODE ------------------- //
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

int code (double xU, double yU) {
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

    return zoneID;
}
// ------------------- CODE ------------------- //

int result (double in1, double in2, int out) {
    if (code(in1, in2) == out) {
        return 1;
    } else if (code(in1, in2) == errCode) {
        return errCode;
    }

    return 0;
}

void printRes (double in1, double in2, int out, int index) {
    cout << "INPUT: " << in1 << ", " << in2 << endl;
    cout << "OUTPUT: " << code(in1, in2) << endl;
    cout << "EXPECTED: " << out << endl;
    if (result(in1, in2, out) == 1) {
        cout << " >>> SUCCESS! <<<" << endl;
    } else if (result(in1, in2, out) == errCode) {
        cout << " >>> ERROR!!! <<<" << endl;
    } else {
        cout << " >>> FAILURE! <<<" << endl;
    }
    cout << "-----------------------" << endl;
}

int main () {
    int succAttempts = 0; 
    double succRate;

    cout << "programName" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        printRes(testInX[i], testInY[i], expectedOutputs[i], i);
        if (result(testInX[i], testInY[i], expectedOutputs[i]) == 1) {
            succAttempts++;
        }
    }

    succRate = double(succAttempts) / double(SAMPLE_SIZE);
    cout << "SUCCESS RATE: " << succAttempts << '/' << SAMPLE_SIZE << " (" << succRate * 100 << "%)" << endl;

    return 0;
}