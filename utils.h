#include <iostream>

void swap (int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}


void printArray (int *arr, int length)
{
    std::cout << "\n";
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " " ;
    }
    std::cout << "\n";
}
