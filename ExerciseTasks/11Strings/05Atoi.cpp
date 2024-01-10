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
    uint num = 0;
    int i = 0;
    while (*str && !(*str > '0' && *str <= '9'))
    {
        i++;
    }

    const char* start = str + i;
    while (*start && (*start >= '0' && *start <= '9'))
    {
        num *= 10;
        num += (*start - '0');
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