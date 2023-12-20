#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

/*
-------------------- 01 Capitalize --------------------
Read a string (char array) from console and capitalize
all letters in it.

---------------------- EXAMPLE: -----------------------
input:  abCDeef1$
output: ABCDEEF1$
-------------------------------------------------------
*/

/**
 * Capitalize all lowercase letters in a string.
 * 
 * @param src The address of the source.
 */
void capitalize (char* src)
{
    if (src == nullptr)
        return ;

    const int capitalChange = 'A' - 'a';
    while (*src)
    {
        if (*src >= 'a' && *src <= 'z')
            *src += capitalChange;
        
        src++;
    }
}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    capitalize(str);
    std::cout << str << endl;

    return 0;
}