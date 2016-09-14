#include <iostream>

// The code is not complete. The code breaks when the 
// input size is not a power of 2. TEST
void combineArray ( int *num, int start, int end)
{
    int mid = (start + end) /2;
    int a[mid - start + 1];
    int b[end -mid + 1];
    int alen=0, blen=0;

    for ( int i = start; i <= mid; i++)
    {
        a[i-start] = num[i];
        alen++;
    }

    for ( int i = mid+1; i <= end; i++)
    {
        b[i-mid -1] = num[i];
        blen++;
    }

    int aiter =0, biter=0, numiter = start;
    while ( aiter < alen && blen > biter)
    {
        if ( a[aiter] > b[biter] )
        {
            num[numiter] = b[biter];
            biter++;
        } 
        else
        {
            num[numiter] = a[aiter];
            aiter++;
        }
        numiter++;
    }

    while (aiter < alen)
    {
        num[numiter] = a[aiter];
        aiter++;
    }

    while (biter < blen)
    {
        num[numiter] = b[biter];
        biter++;
    }
}

void mergeSort ( int* nums, int start, int end)
{

    if (start == end)
        return;

    mergeSort (nums, start, (start + end) /2 );
    mergeSort (nums, (start + end) / 2 + 1, end);

    combineArray (nums, start, end);
}

int main ()
{
    #define LENGTH 4
    int a[5] = { 2, 3, 5, 1};
    mergeSort ( a, 0, LENGTH - 1);
    
    for (int i = 0; i < LENGTH; i++)
    {
        std::cout << "\n For " << i << " Array val is " << a[i];
    }
}

