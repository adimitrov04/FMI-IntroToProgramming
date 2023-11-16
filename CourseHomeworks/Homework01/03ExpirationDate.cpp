#include <iostream>
#include <cmath>

#define DAY_MASK 0b00000000000000000000000000011111
#define MNTH_MASK 0b00000000000000000000000111100000
#define YEAR_MASK 0b00000000000000111111111000000000
#define EXP_MASK 0b01111111111111100000000000000000
#define CTRL_MASK 0b10000000000000000000000000000000

using namespace std;

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

int main () {
    // Bit position constant for different elements:
    const int monthPos = 5;
    const int yearPos = 9;
    const int expPos = 18;
    const int ctrlPos = 31;

    const int currentDay = 1, currentMonth = 11, currentYear = 2023;
    const int initialExpYear = 1900;

    uint32_t barCode;
    cin >> barCode;

    unsigned int prodDay = barCode & DAY_MASK;
    unsigned int prodMonth = (barCode & MNTH_MASK) >> monthPos;
    unsigned int prodYear = ((barCode & YEAR_MASK) >> yearPos) + initialExpYear;
    unsigned int expiryDays = (barCode & EXP_MASK) >> expPos;
    bool controlBit = (barCode & CTRL_MASK) >> ctrlPos;

    bool validCode = 0;

    // unfinished...

    return 0;
}