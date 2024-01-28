#include <iostream>

using std::endl;

bool isBetween (const int num, const int lowerLim, const int upperLim)
{
    return (num >= lowerLim && num <= upperLim);
}

int extractDigits (const int num)
{
    int sum = 0;
    for (int i = 10, j = 1; j <= 1000; i *= 10, j *= 10)
    {
        int currentDigit = (num % i) / j;
        sum += currentDigit;
        std::cout << currentDigit << endl;
    }
    
    return sum;
}

int main ()
{
    int num = 0;
    std::cin >> num;
    
    if (isBetween(num, 1000, 9999) == false)
        return -1;
    
    std::cout << extractDigits(num) << endl;
    
    return 0;
}
