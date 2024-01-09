#include <iostream>

using std::endl;

const int CHAR_LIMIT = 256;
const char STOP_CODE[3] = {'.', 'q', '\0'};

/*
---------------------- 06 Sort Words ----------------------
Read a dynamic list of words and sort that list
alphabetically.

------------------------ EXAMPLE: -------------------------
input:  banana
        apple
        orange

output: apple
        banana
        orange
-----------------------------------------------------------
*/

namespace mystr
{

int strlen (const char* str)
{
    if (*str == '\0')
        return 0;
    
    return 1 + strlen(str + 1);
}

void strcpy (char* dest, const char* src)
{
    if (dest == nullptr)
        return ;
    
    while (src && *src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int strcmp (const char* str1, const char* str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

void strclear (char* str)
{
    if (str == nullptr)
        return ;
    
    *str = '\0';
    str++;
    
    while (*str)
    {
        *str = 0;
        str++;
    }

    *str = 0;
}

void print (char* str)
{
    if (!str)
        std::cout << "null";

    while (*str)
    {
        std::cout << *str;
        str++;
    }
}

}

void copy (char** src, const int size1, char** dest, const int size2)
{
    for (int i = 0; i < size1 && i < size2; i++)
    {
        dest[i] = src[i];
    }
}

void printList (char** list, const int size)
{
    for (int i = 0; i < size; i++)
    {
        mystr::print(list[i]);
        std::cout << endl;
    }
}

void clearList (char** list, const int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] list[i];
    }
}

int findFirst (char** list, const int size)
{
    char* pMin = list[0];
    int minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (mystr::strcmp(list[i], pMin) < 0)
        {
            pMin = list[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void sortList (char** list, const int size)
{
    if (size == 0)
        return ;

    int min = findFirst(list, size);
    std::swap(*list, *(list + min));

    sortList(list + 1, size - 1);
}

int main ()
{
    char** wordList = nullptr;
    int wordCount = 0;

    char currentWord[CHAR_LIMIT] = {0,};
    std::cin.getline(currentWord, CHAR_LIMIT);

    while (mystr::strcmp(currentWord, STOP_CODE) != 0)
    {
        wordCount++;
        
        // Allocate memory for new list of pointers 
        char** newDest = new (std::nothrow) char*[wordCount];
        if (newDest == nullptr)
        {
            std::cerr << "Could not allocate space. (pointer)" << endl;
            break;
        }

        // Copy pointer list to new destination
        if (wordCount > 1)
            copy(wordList, wordCount - 1, newDest, wordCount);
        
        // Allocate memory for new word
        newDest[wordCount - 1] = new (std::nothrow) char[mystr::strlen(currentWord) + 1];
        
        char* pNew = newDest[wordCount - 1];
        if (pNew == nullptr)
        {
            delete[] newDest;
            std::cerr << "Could not allocate space. (word)" << endl;
            break;
        }
        
        // Copy new word into heap
        mystr::strcpy(pNew, currentWord);
        //std::clog << "New word added: " << pNew << endl;

        // Free up previous destination and move to the new one
        delete[] wordList;
        wordList = newDest;
        //std::clog << "NEW LOCATION: " << wordList << endl;
        newDest = nullptr;
        
        // Get new word
        mystr::strclear(currentWord);
        std::cin.getline(currentWord, CHAR_LIMIT);
    }
    
    std::cout << endl;
    sortList(wordList, wordCount);
    printList(wordList, wordCount);

    // Memory clean up
    clearList(wordList, wordCount);

    return 0;
}