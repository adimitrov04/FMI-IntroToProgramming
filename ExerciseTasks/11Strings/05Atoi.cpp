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

int atoi (const char* src)
{
    if (src == nullptr)
        return -1;
    
    int result = 0;
    
    bool numberStarted = 0;
    while (*src)
    {
        if (*src >= '0' && *src <= '9')
        {
            if (numberStarted)
            {
                result = (result * 10) + (*src - '0');
            }
            else if (*src != '0')
            {
                numberStarted = true;
                result = (result * 10) + (*src - '0');
            }
        }
        else
        {
            if (numberStarted)
                break;
        }

        src++;
    }

    return result;
}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    int num = atoi(str);
    std::cout << num << endl;

    return 0;
}