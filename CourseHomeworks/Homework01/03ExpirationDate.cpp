#include <iostream>
#include <cmath>

using namespace std;

const uint32_t DAY_MASK = 0b00000000000000000000000000011111;
const uint32_t MNTH_MASK = 0b00000000000000000000000111100000;
const uint32_t YEAR_MASK = 0b00000000000000111111111000000000;
const uint32_t EXP_MASK = 0b01111111111111100000000000000000;
const uint32_t CTRL_MASK = 0b10000000000000000000000000000000;

const int MIN_YEAR = 1900;

/* TASK DESCRIPTION:
--------------------------------------------
Read a barcode number (integer), which encodes a product's production date and expiration
date, and determine whether the given product is within the expiration date.

Let the current date be 01.11.23 (represented as a constant).

There are 3 possible outputs for any input:
    - Good - when the product is good to consume (the production date + the amount of days added
    is before or on the current day);
    - Too old - when the product is expired (the production date + the amount of days added is before
    or on the current day);
    - Invalid - when the given barcode does not describe a valid production date.

The encoding is as follows:
    v Expiry date as number of days after production date         v Month of production
0 | 0 0000 0000 0000                              | 0 0000 0000 | 0000      | 0 0000
^ Control bit                                       ^ Year as yrs after 1900  ^ Day of month

If the expiry date is encoded with an even number of 1's, the control bit should be 0, otherwise
it should be 1. If the value of the control bit does not match that, the input should be marked as
invalid.

INVALID INPUT CASES:
    - Invalid month (month is larger than 12);
    - Invalid day of the month (i.e. February 30th);
        -- Invalid February day depending on leap year (i.e. February 29th 2023);
    - Invalid control bit;
    - Production date is after current date (i.e. 01.01.24)
--------------------------------------------
*/  

bool inRange (int checkVal, int limVal, int initVal = 0) {
    if (checkVal >= initVal && checkVal <= limVal) {
        return true;
    }

    return false;
}

bool isLeapYear (int year) {
    if (!(year % 4) && !(!(year % 100) && year % 400))
        return true;
    
    return false;
}

bool isValidControlBit (int barCode, bool controlBit, int SIZE = 32) {
    int DATA_MASK = (DAY_MASK | MNTH_MASK | YEAR_MASK | EXP_MASK);
    int dataCheckArea = barCode & DATA_MASK;

    dataCheckArea = dataCheckArea ^ (dataCheckArea >> (SIZE / 2));
    dataCheckArea = dataCheckArea ^ (dataCheckArea >> (SIZE / 4));
    dataCheckArea = dataCheckArea ^ (dataCheckArea >> (SIZE / 8));
    dataCheckArea = dataCheckArea ^ (dataCheckArea >> (SIZE / 16));
    dataCheckArea = dataCheckArea ^ (dataCheckArea >> (SIZE / 32));

    bool evenOnesInData = !(dataCheckArea & 1);

    if (controlBit != evenOnesInData) {
        return true;
    }

    return false;
}

bool dateIsValid (int prodDay, int prodMonth, int prodYear,
                  int currentDay, int currentMonth, int currentYear) {
    // Year check
    const int startYear = 1900;
    bool validYear = 0, leapYear = 0;
    if (!(inRange(prodYear, currentYear, startYear))) {
        return false;
    } else {
        leapYear = isLeapYear(prodYear);
    }

    // Month check
    int MAX_MONTH = (prodYear == currentYear) ? currentMonth : 12;

    if (!(inRange(prodMonth, MAX_MONTH, 1)))
        return false;

    // Day check
    int MAX_DAY = 31;

    if (prodYear == currentYear && prodMonth == currentMonth) {
        MAX_DAY = currentDay;
    } else if (prodMonth == 2) {
        if (leapYear) {
            MAX_DAY = 29;
        } else {
            MAX_DAY = 28;
        }
    } else if ((prodMonth >= 8 && prodMonth % 2) || (prodMonth <= 7 && !(prodMonth % 2))) {
        MAX_DAY = 30;
    }

    if (!(inRange(prodDay, MAX_DAY, 1))) {
        return false;
    }

    return true;
}

int main () {
    // Bit position constant for different elements:
    const int monthPos = 5, yearPos = 9, expPos = 18, ctrlPos = 31;
    // Current date 01.11.2023
    const int currDay = 1, currMonth = 11, currYear = 2023;

    uint32_t barCode;
    cin >> barCode;

    unsigned int prodDay = barCode & DAY_MASK;
    unsigned int prodMonth = (barCode & MNTH_MASK) >> monthPos;
    unsigned int prodYear = ((barCode & YEAR_MASK) >> yearPos) + MIN_YEAR;
    unsigned int expDays = (barCode & EXP_MASK) >> expPos;
    bool controlBit = (barCode & CTRL_MASK) >> ctrlPos;

    bool validCode = 0;
    
    return 0;
}