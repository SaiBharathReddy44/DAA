#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int selected[4] = {0};
    selected[0] = 1;

    int edges = 0;
    int totalCost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = 9999;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (selected[j] == 0 &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << min << endl;

        totalCost += min;
        selected[y] = 1;
        edges++;
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}
