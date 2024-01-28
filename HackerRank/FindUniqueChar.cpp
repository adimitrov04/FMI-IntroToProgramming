#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;

bool isUnique (const char* const str, const char* ch)
{
    const char* fwdCheck = ch + 1;
    while (*fwdCheck)
    {
        if (*fwdCheck == *ch)
            return false;

        fwdCheck++;
    }

    if (ch > str)
    {
        const char* bwdCheck = ch - 1;
        while (bwdCheck >= str)
        {
            if (*bwdCheck == *ch)
                return false;
            
            bwdCheck--;
        }
    }

    return true;
}

char getFirstUnique (const char* const str)
{
    const char* current = str;

    while (*current)
    {
        if (isUnique(str, current))
        {
            return *current;
        }
        current++;
    }

    return '0';
}

int main ()
{
    char str[CHAR_LIMIT] = {0,};
    std::cin.getline(str, CHAR_LIMIT);

    std::cout << getFirstUnique(str) << endl;

    return 0;
}