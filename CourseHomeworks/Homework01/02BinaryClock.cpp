#include <iostream>
#include <cmath>

using namespace std;

/* TASK DESCRIPTION:
--------------------------------------------
Read an unsigned integer from the console which represents a time value in binary.

Bits 0-5 of the number represent the seconds, bits 6-11 represent the minutes,
bits 12-17 represent the hour.

The hour fragment is calculated as such - bits 12-15 represent the first digit of the
hour and bits 16 and 17 represent the second digit - the tenths.

The last bit represents the time format - 12-hour vs 24-hour.
If bit 18 is 1, then the format is 24 hours;
If it is 0, the format is 12 hours.

Determine whether the given number is valid, and if it is output the resulting time
in the format: HH:MM:SS
--------------------------------------------
*/

void printLeadingZero (int number) {
    if (number < 10) {
        cout << '0' << number;
    } else {
        cout << number;
    }
}

int main () {
    const uint32_t SEC_MASK = 0b0000000000000111111;
    const uint32_t MIN_MASK = 0b0000000111111000000;
    const uint32_t HOUR_DIG_MASK = 0b0001111000000000000;
    const uint32_t HOUR_TNTH_MASK = 0b0110000000000000000;
    const uint32_t FORMAT_MASK = 0b1000000000000000000;

    uint32_t inputTime;
    cout << "Enter time number: ";
    cin >> inputTime;

    int SECONDS = inputTime & SEC_MASK;
    int MINUTES = (inputTime & MIN_MASK) >> 6;
    int HOURS = (((inputTime & HOUR_TNTH_MASK) * 10) >> 16) + ((inputTime & HOUR_DIG_MASK) >> 12);

    bool _24HourMode = (inputTime & FORMAT_MASK) >> 18;

    bool validNumber = 0;
    if (SECONDS <= 59 && MINUTES <= 59) {
        if (_24HourMode && (HOURS <= 24)) {
            validNumber = 1;
        } else if (!_24HourMode && (HOURS <= 12)) {
            validNumber = 1;
        }
    }

    if (validNumber) {
        printLeadingZero(HOURS); cout << ':';
        printLeadingZero(MINUTES); cout << ':';
        printLeadingZero(SECONDS); cout << endl;
    } else {
        cerr << "Invalid data" << endl;
    }


    return 0;
}