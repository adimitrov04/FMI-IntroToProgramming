#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

/*
---------------------- 04 Palindrome ----------------------
Read a string (char array) and determine whether or not it
is a palindrome.

------------------------ EXAMPLE: -------------------------
input:  abcba
output: 1
-----------------------------------------------------------
*/

int my_strlen (char* src)
{
    if (src == nullptr)
        return 0;
    
    int count = 0;
    while (*src)
    {
        count++;
        src++;
    }

    return count;
}

bool isPalindrome (char* src)
{
    if (src == nullptr)
        return false;

    char* front = src;
    char* back = src + (my_strlen(src) - 1);

    while (front <= back)
    {
        if (front == back)
            break;

        if (*front != *back)
            return false;
        
        front++;
        back--;
    }

    return true;
}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    std::cout << isPalindrome(str);

    return 0;
}