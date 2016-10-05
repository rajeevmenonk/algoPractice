#include <iostream>
#include "utils.h"

void quickSort (int *arr, int length)
{
    if (length == 1)
        return;

    int pivot = length -1;
    int lessIndex = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if ( arr[i] < arr[pivot])
        {
            swap(arr[i], arr[lessIndex]);
            lessIndex++;
        }
    }
    swap ( arr[lessIndex], arr[pivot]);

    quickSort (arr, lessIndex);
    quickSort (arr+lessIndex+1, length-lessIndex);
}

int main()
{
    #define LENGTH 10
    int arr[] = { 1, 5, 2, 7, 9, 0, 3, 4, 8, 6};
    quickSort (arr, LENGTH);
    printArray(arr, LENGTH);
}
