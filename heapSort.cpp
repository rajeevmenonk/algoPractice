#include <iostream>

int parent ( int child)
{
    int parent = child / 2;
    if ( child  % 2 == 0)
        parent--;
    return parent;
}

int childLeft ( int parent)
{
    return (parent * 2 + 1);
}

int childRight ( int parent)
{
    return (parent * 2 + 2);
}

int main ()
{
    int i = 0;

}
