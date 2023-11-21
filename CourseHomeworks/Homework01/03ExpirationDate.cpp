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

int daysUntilMonth (int month, int year) {
    if (isLeapYear(year)) {
        switch (month) {
            case 1: return 0; break;
            case 2: return 31; break;
            case 3: return 60; break;
            case 4: return 91; break;
            case 5: return 121; break;
            case 6: return 152; break;
            case 7: return 182; break;
            case 8: return 213; break;
            case 9: return 244; break;
            case 10: return 274; break;
            case 11: return 305; break;
            case 12: return 335; break;
            default: return -1; break;
        }
    } else {
        switch (month) {
            case 1: return 0; break;
            case 2: return 31; break;
            case 3: return 59; break;
            case 4: return 90; break;
            case 5: return 120; break;
            case 6: return 151; break;
            case 7: return 181; break;
            case 8: return 212; break;
            case 9: return 243; break;
            case 10: return 273; break;
            case 11: return 304; break;
            case 12: return 334; break;
            default: return -1; break;
        }
    }
}

int dayIsInMonth (int day, int year) {
    if (day >= 1 && day <= 31) {
        return 1;
    } else if (isLeapYear(year)) {
        if (day >= 32 && day <= 60) {
            return 2;
        } else if (day >= 61 && day <= 91) {
            return 3;
        } else if (day >= 92 && day <= 121) {
            return 4;
        } else if (day >= 122 && day <= 152) {
            return 5;
        } else if (day >= 153 && day <= 182) {
            return 6;            
        } else if (day >= 183 && day <= 213) {
            return 7;            
        } else if (day >= 214 && day <= 244) {
            return 8;            
        } else if (day >= 245 && day <= 274) {
            return 9;            
        } else if (day >= 275 && day <= 305) {
            return 10;            
        } else if (day >= 306 && day <= 335) {
            return 11;            
        } else if (day >= 336 && day <= 366) {
            return 12;            
        }
    } else {
        if (day >= 32 && day <= 59) {
            return 2;
        } else if (day >= 60 && day <= 90) {
            return 3;
        } else if (day >= 91 && day <= 120) {
            return 4;
        } else if (day >= 121 && day <= 151) {
            return 5;
        } else if (day >= 152 && day <= 181) {
            return 6;            
        } else if (day >= 182 && day <= 212) {
            return 7;            
        } else if (day >= 213 && day <= 243) {
            return 8;            
        } else if (day >= 244 && day <= 273) {
            return 9;            
        } else if (day >= 274 && day <= 304) {
            return 10;            
        } else if (day >= 305 && day <= 334) {
            return 11;            
        } else if (day >= 335 && day <= 365) {
            return 12;            
        }
    }

    return -1;
}

int leapYearsBetween (int year1, int year2) {
    int count = abs(year1 - year2) / 4;
    if (isLeapYear(year2))
        count++;

    return count;
}

bool dateIsValid (int prodDay, int prodMonth, int prodYear, int currentDay, int currentMonth, int currentYear) {
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

void moveToDate (int moveDays, unsigned int& day, unsigned int& month, unsigned int& year) {
    moveDays += day - 1;
    
    int fullYears = moveDays / 365;
    int newYear = year + fullYears;
    int bonusLeapDays = leapYearsBetween(year, newYear);
    year = newYear;
    
    moveDays -= fullYears * 365;
    month = dayIsInMonth(moveDays, year);
    if (isLeapYear(year) && month > 2) 
        bonusLeapDays++;

    moveDays -= (daysUntilMonth(month, year) - 1);
    day = moveDays - bonusLeapDays;
}

int main () {
    // Bit position constant for different elements:
    const int monthPos = 5, yearPos = 9, expPos = 18, ctrlPos = 31;
    // Current date 01.11.2023
    const int currDay = 1, currMonth = 11, currYear = 2023;

    uint32_t barCode;
    cin >> barCode;

    unsigned int day = barCode & DAY_MASK;
    unsigned int month = (barCode & MNTH_MASK) >> monthPos;
    unsigned int year = ((barCode & YEAR_MASK) >> yearPos) + MIN_YEAR;
    unsigned int expDays = (barCode & EXP_MASK) >> expPos;
    bool controlBit = (barCode & CTRL_MASK) >> ctrlPos;

    if (isValidControlBit(barCode, controlBit) && dateIsValid(day, month, year, currDay, currMonth, currYear)) {
        moveToDate(expDays, day, month, year);
        if (currYear == year) {
            if (currMonth == month) {
                if (currDay <= day) {
                    cout << "Good" << endl;
                    return 0;
                }
            } else if (currMonth < month) {
                cout << "Good" << endl;
                return 0;
            }
        } else if (currYear < year) {
            cout << "Good" << endl;
            return 0;
        }
    } else {
        cerr << "Invalid" << endl;
        return 1;
    }
    
    cout << "Too old" << endl;
    return 0;
}