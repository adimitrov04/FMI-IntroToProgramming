#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

/*
---------------------- 03 String Cat ----------------------
Create a function which takes two strings (char arrays) as
input and returns an address to a new dynamic string which
is a concatenation of the two.

------------------------ EXAMPLE: -------------------------
input:  Hello
        world
output: &(Helloworld)
-----------------------------------------------------------
*/

int my_strlen (char* src)
{
    int count = 0;
    
    if (src == nullptr)
        return count;

    while (*src)
    {
        count++;
        src++;
    }

    return count;
}

void my_strcpy (char* dest, char* src)
{
    if (dest == nullptr)
        return ;

    while (*src)
    {
        *dest = *src;
        
        dest++;
        src++;
    }
    *dest = '\0';
}

void my_strcat (char* str1, char* str2)
{
    if (str1 == nullptr)
        return ;

    char* start = str1 + my_strlen(str1);
    my_strcpy(start, str2);
}

/**
 * Concatenate two cstrings
 * 
 * @return An address to a dynamic cstring
 */
char* dynamic_strcat (char* str1, char* str2)
{
    if (str1 == nullptr && str2 == nullptr)
        return nullptr;

    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    
    char* cat = new (std::nothrow) char[(size1 + size2) + 1];
    if (cat == nullptr)
    {
        delete[] cat;
        return nullptr;
    }

    my_strcpy(cat, str1);
    my_strcat(cat, str2);

    return cat;
}

int main ()
{
    char str1[CHAR_LIMIT] = {0,};
    std::cin.getline(str1, CHAR_LIMIT);
    
    char str2[CHAR_LIMIT] = {0,};
    std::cin.getline(str2, CHAR_LIMIT);

    char* concat = dynamic_strcat(str1, str2);

    std::cout << concat << endl;
    // std::cout << &(concat) << endl;

    return 0;
}