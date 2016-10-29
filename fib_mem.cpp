#include <iostream>
#include <map>

using namespace std;

map <int, int> cache;

int fib (int n)
{
    if ( n == 1 || n == 2)
        return 1;

    map <int, int>::iterator iter = cache.find(n);

    if (iter != cache.end())
        return iter->second;

    int val = fib(n-1) + fib(n-2);
    cache.insert(pair<int, int>(n,val));
    return val;
}

int main ()
{
    int n;
    cin >> n;
    cout << "Fib is " << fib(n);
}
