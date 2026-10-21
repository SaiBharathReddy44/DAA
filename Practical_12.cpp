
#include <iostream>
#include <climits>
using namespace std;

int n = 4;

int cost[10][10] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[10] = {0};
int minCost = INT_MAX;

void tsp(int city, int count, int totalCost, int start)
{
    if (count == n && cost[city][start] != 0)
    {
        int finalCost = totalCost + cost[city][start];

        if (finalCost < minCost)
            minCost = finalCost;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[city][i], start);

            visited[i] = 0;
        }
    }
}

int main()
{
    visited[0] = 1;

    tsp(0, 1, 0, 0);

    cout << "Cost Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << cost[i][j] << " ";
        cout << endl;
    }

    if (minCost == INT_MAX)
        cout << "No possible tour exists.";
    else
        cout << "Minimum travelling cost: " << minCost << endl;

    return 0;
}
