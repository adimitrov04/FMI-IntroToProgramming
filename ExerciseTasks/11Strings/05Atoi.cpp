#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

/*
------------------------- 05 Atoi -------------------------
Create a function called atoi() which extracts positive
integers (in type int) from a string (char array).

------------------------ EXAMPLE: -------------------------
input:  00523g2
output: 523
-----------------------------------------------------------
*/

void my_strcpychar (char* dest, char* src, int offset)
{
    if (dest == nullptr)
        return ;
    
    *dest = *(src + offset);
}

int atoi (const char* str)
{
    int num = 0;

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

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    int num = atoi(str);
    std::cout << num << endl;

    return 0;
}