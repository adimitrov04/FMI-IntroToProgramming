#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

/*
Task:
Get the coordinates of 4 points as input from console and calculate the
area of the formed quadrangle. 
*/

int main () {
    int xA, yA;
    cout << "Enter coordinates of point A:" << endl;
    cin >> xA >> yA;
    cout << "A(" << xA << ',' << yA << ')' << endl;

    int xB, yB;
    cout << "Enter coordinates of point B:" << endl;
    cin >> xB >> yB;
    cout << "B(" << xB << ',' << yB << ')' << endl;

    int xC, yC;
    cout << "Enter coordinates of point C:" << endl;
    cin >> xC >> yC;
    cout << "C(" << xC << ',' << yC << ')' << endl;

    int xD, yD;
    cout << "Enter coordinates of point D:" << endl;
    cin >> xD >> yD;
    cout << "D(" << xD << ',' << yD << ')' << endl;

    double AB = sqrt((abs(xA - xB) * abs(xA - xB)) + (abs(yA - yB) * abs(yA - yB)));
    double BC = sqrt((abs(xB - xC) * abs(xB - xC)) + (abs(yB - yC) * abs(yB - yC)));
    double CD = sqrt((abs(xC - xD) * abs(xC - xD)) + (abs(yC - yD) * abs(yC - yD)));
    double DA = sqrt((abs(xD - xA) * abs(xD - xA)) + (abs(yD - yA) * abs(yD - yA)));

    double AC = sqrt((abs(xA - xC) * abs(xA - xC)) + (abs(yA - yC) * abs(yA - yC)));
    double BD = sqrt((abs(xB - xD) * abs(xB - xD)) + (abs(yB - yD) * abs(yB - yD)));
    
    cout << "AB: " << AB << " cm" << endl;
    cout << "BC: " << BC << " cm" << endl;
    cout << "CD: " << CD << " cm" << endl;
    cout << "DA: " << DA << " cm" << endl;

    double sABD = (AB + BD + DA) / 2;
    double areaABD = sqrt(sABD * ((sABD - AB) * (sABD - BD) * (sABD - DA)));

    double sBCD = (BC + BD + CD) / 2;
    double areaBCD = sqrt(sBCD * ((sBCD - BC) * (sBCD - BD) * (sBCD - CD)));

    cout << "Area of ABCD: " << (areaABD + areaBCD) << " cm^2" << endl; 

    return 0;
}