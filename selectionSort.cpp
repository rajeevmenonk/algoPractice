#include <iostream>

void selectionSort ( int* nums, int len)
{
    for (int i=0; i < len - 1; i++)
    {
        for (int j=i+1; j < len; j++)
        {
             if ( nums[j] < nums[i] )
             {
                  int temp = nums[i];
                  nums[i] = nums[j];
                  nums[j] = temp;
             }
        }
    }
}

int main ()
{
    int a[5] = { 2, 3, 5, 7, 1};
    selectionSort ( a, 5);
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "For " << i << " Array val is " << a[i] << "\n";
    }
}

