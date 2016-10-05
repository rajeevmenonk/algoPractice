#include <iostream>
#include "utils.h"

#define parent(child) ((child % 2 == 0 ? (child/2 -1) : (child/2)))
#define childLeft(parentNode) ((parentNode * 2 + 1))
#define childRight(parentNode) ((parentNode * 2 + 2))

void maxHeapify (int *arr, int pos, int length)
{
    int leftChild = childLeft(pos);
    int rightChild = childRight(pos);
    if (rightChild >= length || leftChild >= length)
        return;

    int biggerValue = leftChild;
    if (arr[rightChild] > arr[leftChild])
        biggerValue = rightChild;

    if (arr[pos] < arr[biggerValue])
    {
         swap(arr[pos], arr[biggerValue]);
         maxHeapify(arr, biggerValue, length);
    }
}

void buildHeap ( int *arr, int length)
{
    int iter = length/2 - 1;
    while (iter >= 0)
    {
        maxHeapify(arr, iter, length);
        iter--;
    }
}

void heapSort ( int *arr, int length)
{
    buildHeap(arr, length );
    for (int i = length - 1; i > 0; i--)
    {
        swap( arr[0], arr[i] );
        maxHeapify( arr, 0, i);
    }
}

void percolateUp (int *arr, int pos)
{
    int parentIter = parent(pos);

    if(parentIter == -1)
        return;

    if ( arr[pos] > arr[parentIter] )
    {
       swap( arr[pos], arr[parentIter] );
       percolateUp( arr, parentIter);
    }
}

void insert (int *arr, int pos)
{
    percolateUp(arr, pos);
}

void increaseKey (int *arr, int pos, int newValue)
{
    arr[pos] = newValue;
    percolateUp(arr, pos);
}

int main ()
{
    #define LENGTH 12
    int arr[] = {2, 4, 3, 16, 25, 15, 9, 21, 5, 1, 8, 7};
    heapSort (arr, LENGTH);
    printArray (arr, LENGTH);
    
    int arr1[] = {25, 21, 15, 16, 30, 7, 9, 2, 5, 1, 4, 3};
    percolateUp(arr1, 4);
    printArray (arr1, LENGTH);

    increaseKey(arr1, 11, 40);
    printArray (arr1, LENGTH);

    return 0;
}
