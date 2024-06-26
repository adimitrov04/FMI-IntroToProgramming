#include <iostream>
#include <new>

using std::endl;

typedef char** list;

const int capitalDiff = 'A' - 'a'; // The difference between capital and lowercase letters
const int MAX_STRING = 1000;       // Max length of a string
const int MAX_CODE = 10;        // Max length of each encryption key
const int ALPHABET = 26;           // Number of letters in the English alphabet
const int CHAR_LIMIT = 256;

namespace mystr
{

bool letterIs (const char ch, const char letter)
{
    if (ch == letter || ch == (letter - capitalDiff))
        return true;

    return false;
}

bool isLetter (const char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return true;

    if (ch >= 'A' && ch <= 'Z')
        return true;

    return false;
}

/**
 * Jump to a given word in a string.
 */
char* strjump (char* str, const int word)
{
    char* wrd = str;
    int currentWord = 1;

    while (*str && currentWord < word)
    {
        if (isLetter(*str) && *(str - 1) == ' ')
        {
            currentWord++;
            wrd = str;
        }

        str++;
    }

    if (currentWord < word)
        wrd = nullptr;

    return wrd;
}

int strlen (const char* str)
{
    if (!str)
        return 0;

    int count = 0;
    while (*str)
    {
        count++;
        str++;
    }

    return count;
}

int strwordlen (const char* wrd)
{
    if (!wrd)
        return 0;

    int len = 0;
    while (*wrd && *wrd != ' ')
    {
        len++;
        wrd++;
    }

    return len;
}

void strcpy (char* dest, const char* src)
{
    if (!dest || !src)
        return ;
    
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
}

void strcpyword (char* dest, const char* wrd)
{
    while (*wrd && *wrd != ' ')
    {
        *dest = *wrd;
        dest++;
        wrd++;
    }

    *dest = '\0';
}

}

/*
--------------------- 02 Cryptography ---------------------
Create a program which can encrypt a string by replacing
each letter in it with a string(len <= 10) according to a
table, generated by the user. Let the program not
differentiate lower- and uppercase letters.

The program first takes as input an integer - K - followed
by K pairs of a character and a string, separated by a
space. Each pair should be on a new line. This represents
the table, according to which, each string will be
encrypted.

Then, read an integer N, followed by N strings, which are
to be encrypted using the algorithm, as well as an integer
M, followed by M strings to be decrypted.

The encrypted and decrypted strings should be stored
dynamically.

------------------------ EXAMPLE: -------------------------
input:  8
        i ala
        l bala
        d cana
        e h
        t disco
        o electro
        c pro
        a some
        
        1
        I l0ve to code!
        
        1
        ala somem discoelectroelectro proelectroelectrobala!

output: ala bala0vh discoelectro proelectrocanah!
        i am too cool!
-----------------------------------------------------------
*/

int allocFail ()
{
    std::cerr << "FAIL: Couldn't allocate memory.";
    return -1;
}

bool isInList (char ch, list searchIn, const int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        if (mystr::letterIs(searchIn[i][0], ch))
            return true;
    }

    return false;
}

int inputFail (char* find, char* replace, const list dest, const int destSize)
{
    using namespace mystr;

    if (!replace)
    {
        std::cerr << "Invalid input: no key set... try again:" << endl;
        return 1;
    }

    if (!isLetter(*find) || mystr::strwordlen(find) > 1 || mystr::strlen(replace) > 10)
    {
        std::cerr << "Invalid input: incorrect format... try again:" << endl;
        return 2;
    }

    if (isInList(*find, dest, destSize))
    {
        std::cerr << "Invalid input: key already set for letter... try again:" << endl;
        return 2;
    }

    return 0;
}

void deleteList (char** list, const int size)
{
    if (size == 0)
        return ;

    for (int i = 0; i < size; i++)
    {
        delete[] list[i];
    }

    delete[] list;
}

void deleteList (list* list, const int size)
{
    if (size == 0)
        return ;

    for (int i = 0; i < size; i++)
    {
        delete[] list[i];
    }

    delete[] list;
}

void print (list src, const int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << src[i] << endl;
    }
}

void encrypt (list* keyList, char* str)
{

}

void decrypt (list* keyList, char* str);

int main ()
{   
    int numberOfKeys = 0;
    std::cin >> numberOfKeys;

    list* keyList = new (std::nothrow) list[2];
    if (!keyList)
    {
        return allocFail();
    }

    keyList[0] = new (std::nothrow) char*[numberOfKeys];
    list plaintext = keyList[0];
    if (!plaintext)
    {
        delete[] keyList;
        return allocFail();
    }

    keyList[1] = new (std::nothrow) char*[numberOfKeys];
    list code = keyList[1];
    if (!code)
    {
        delete[] plaintext;
        delete[] keyList;
        return allocFail();
    }

    char buffer[CHAR_LIMIT] = {0,};
    char* find;
    char* replace;
    
    std::cin.ignore(); // Ignore the \n from the std::cin before
    for (int i = 0; i < numberOfKeys; i++)
    {
        std::cin.getline(buffer, CHAR_LIMIT);

        find = buffer;
        replace = mystr::strjump(buffer, 2);

        if (inputFail(find, replace, plaintext, i))
        {
            //std::cout << buffer << endl;
            i--;
            continue;
        }

        plaintext[i] = new (std::nothrow) char;
        if (!plaintext[i])
        {
            deleteList(plaintext, i);
            deleteList(code, i);
            delete[] keyList;

            return allocFail();
        }
        *plaintext[i] = find[0];

        code[i] = new (std::nothrow) char[mystr::strlen(replace) + 1];
        if (!plaintext[i])
        {
            deleteList(plaintext, i);
            deleteList(code, i);
            delete[] keyList;

            return allocFail();
        }
        mystr::strcpy(code[i], replace);
    }

    int encryptCount = 0, decryptCount = 0;
    
    std::cin >> encryptCount;
    list plaintextStr = new (std::nothrow) char*[encryptCount];
    if (!plaintextStr)
    {
        deleteList(plaintext, numberOfKeys);
        deleteList(code, numberOfKeys);
        delete[] keyList;

        return allocFail();
    }

    std::cin.ignore();
    for (int i = 0; i < encryptCount; i++)
    {
        std::cin.getline(buffer, CHAR_LIMIT);
        plaintextStr[i] = new (std::nothrow) char[mystr::strlen(buffer) + 1];
        if (!plaintextStr[i])
        {
            deleteList(plaintext, numberOfKeys);
            deleteList(code, numberOfKeys);
            delete[] keyList;

            deleteList(plaintextStr, i);

            return allocFail();
        }

        mystr::strcpy(plaintextStr[i], buffer);
    }

    std::cin >> decryptCount;
    list encryptedStr = new (std::nothrow) char*[decryptCount];
    if (!encryptedStr)
    {
        deleteList(plaintext, numberOfKeys);
        deleteList(code, numberOfKeys);
        delete[] keyList;
        
        deleteList(plaintextStr, encryptCount);

        return allocFail();
    }

    std::cin.ignore();
    for (int i = 0; i < decryptCount; i++)
    {
        std::cin.getline(buffer, CHAR_LIMIT);
        encryptedStr[i] = new (std::nothrow) char[mystr::strlen(buffer) + 1];
        if (!encryptedStr[i])
        {
            deleteList(plaintext, numberOfKeys);
            deleteList(code, numberOfKeys);
            delete[] keyList;

            deleteList(plaintextStr, encryptCount);
            deleteList(encryptedStr, i);

            return allocFail();
        }

        mystr::strcpy(encryptedStr[i], buffer);
    }

    

    // Clear allocated memory
    deleteList(plaintext, numberOfKeys);
    deleteList(code, numberOfKeys);
    delete[] keyList;

    deleteList(plaintextStr, encryptCount);
    deleteList(encryptedStr, decryptCount);

    return 0;
}