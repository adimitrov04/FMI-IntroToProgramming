#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

/*
---------------------- 07 Title Case ----------------------
Read a cstring and turn it into title case - each word
begins with a capital letter.

------------------------ EXAMPLE: -------------------------
input:  I need 2 burgers!
output: I Need 2 Burgers!
-----------------------------------------------------------
*/

int allocFail ()
{
    std::cerr << "Couldn't allocate memory." << endl;
    return -1;
}

void titleCase (char* str)
{
    if (!str)
        return ;

    if (*str >= 'a' && *str <= 'z')
    {
        *str += 'A' - 'a';    
    }

    str++;

    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            if (*(str - 1) == ' ')
                *str += 'A' - 'a';
        }

        str++;
    }
}

int main ()
{
    char* str = new (std::nothrow) char[CHAR_LIMIT];
    if (str == nullptr)
        return allocFail();

    std::cin.getline(str, CHAR_LIMIT);
    titleCase(str);
    std::cout << str << endl;

    delete[] str;

    return 0;
}