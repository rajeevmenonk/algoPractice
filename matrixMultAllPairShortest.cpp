#include <iostream>
#include <vector>
#include <climits>
#include <stdint.h>

using namespace std;
int main ()
{
    vector<vector<uint32_t> > graph(6, vector<uint32_t>(6, UINT_MAX));

    graph[0][1] = 3;
    graph[0][2] = 2;
    graph[1][4] = 5;
    graph[1][2] = 1;
    graph[2][1] = 4;
    graph[2][3] = 3;
    graph[3][0] = 5;
    graph[4][2] = 5;
    graph[4][5] = 2;
    graph[5][2] = 1;
    graph[5][3] = 4;
    graph[5][4] = 4;

    for (int i = 0; i < 6; i++)
    {
        graph[i][i] = 0;
    }

    for (int k = 0 ; k < 6; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (!(graph[i][k] == UINT_MAX ||
                    graph[k][j] == UINT_MAX) && 
                   graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout <<"\n";
    }

}
