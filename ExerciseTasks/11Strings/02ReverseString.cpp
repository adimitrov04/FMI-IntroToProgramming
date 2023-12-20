#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

/*
-------------------- 02 Reverse string --------------------
Read a string (char array) and reverse it.

------------------------ EXAMPLE: -------------------------
input:  Hello world!
output: !dlrow olleH
-----------------------------------------------------------
*/

int my_strlen (char* str)
{
    if (str == nullptr)
        return 0;

    int count = 0;
    while (*str)
    {
        count++;
        str++;
    }

    return count;
}

void reverse (char* src)
{
    if (src == nullptr)
        return ;

    char* front = (src + 0);
    char* back = (src + my_strlen(src) - 1);

    while (front <= back)
    {
        if (front == back)
            break;

        std::swap(*front, *back);
        front++;
        back--;
    }
}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    reverse(str);
    std::cout << str << endl;

    return 0;
}