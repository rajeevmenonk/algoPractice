#include <iostream>
#include <vector>

using namespace std;

int fib (int n)
{
    vector <int> fib_sol (n, 0);

    fib_sol[0] = 1;
    fib_sol[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fib_sol[i] = fib_sol[i-1] + fib_sol[i-2];
    }
    return fib_sol[n-1];
}

int main ()
{
    int n;
    cin >> n;
    cout << "Fib is " << fib(n);
}
