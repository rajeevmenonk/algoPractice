#include <iostream>
#include <vector>
#include <stdint.h>

using namespace std;
void computeUniqueSteps (vector<uint64_t> &uqComb, uint64_t index)
{
    uint64_t numSteps = index + 1;

    if (numSteps == 1)
    {
        uqComb[index] = 1;
        return;
    }
    if (numSteps == 2)
    {
        // There are two ways to do this. Take 2 steps at a time or 
        // take 1 step twice.
        uqComb[index] = 1 + uqComb[0];
        return;
    }
    if (numSteps == 3)
    {
        uqComb[index] = 1 + uqComb[1] + uqComb[0];
        return;
    }

    uqComb[index] =  (uqComb[index-1] + uqComb[index-2] + uqComb[index-3]);
}

int main ()
{
    uint64_t totalSize;
    cin >> totalSize;

    vector<uint64_t> uqComb (totalSize ,0);

    for (uint64_t i = 0; i < totalSize; i++)
    {
        computeUniqueSteps(uqComb, i);
    }
    cout << uqComb[totalSize - 1];
}
