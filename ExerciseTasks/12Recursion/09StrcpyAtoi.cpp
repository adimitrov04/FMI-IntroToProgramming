#include <iostream>

using std::endl;

typedef unsigned int uint;

const int CHAR_LIMIT = 256;

/*
--------------------- 09 Strcpy, Atoi ---------------------
Write the strcpy() and atoi() functions recursively.

------------------------ EXAMPLE: -------------------------
input:  ??
output: ??
-----------------------------------------------------------
*/

namespace rec
{

void strcpy (char* dest, const char* src)
{
    if (*src == '\0')
        return ;

    *dest = *src;
    strcpy(dest + 1, src + 1);
}

uint atoi (const char* str)
{
    uint num = 0;

    const char* check = str;
    while (*check && (*check <= '0' || *check > '9'))
    {
        check++;
    }

    const char* dig = (str + (check - str));
    while (*dig && (*dig >= '0' && *dig <= '9'))
    {
        num = (num * 10) + (*dig - '0');
        dig++;
    }

    return num;
}

}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    uint num = rec::atoi(str);
    std::cout << num;

    return 0;
}