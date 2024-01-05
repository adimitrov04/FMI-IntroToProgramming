#include <iostream>
#include <cstring>

using std::endl;

const int CHAR_LIMIT = 128; // Global maximum characters in a cstring

/*
-------------------- 04 Recursive Strlen ------------------
Create the function strlen(), but make it using recursion.

------------------------ EXAMPLE: -------------------------
input:  abcdef
output: 6
-----------------------------------------------------------
*/

int rec_strlen (char* src)
{
    if (*src == '\0')
        return 0;
    
    return 1 + rec_strlen(src + 1);
}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    std::cout << rec_strlen(str) << endl;

    return 0;
}