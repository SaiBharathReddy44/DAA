#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[10];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return find(parent[x]);
}

void unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootB] = rootA;
}

int main()
{
    int n = 4;
    int e = 5;

    Edge edges[5] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges, edges + e, [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int rootU = find(edges[i].u);
        int rootV = find(edges[i].v);

        if (rootU != rootV)
        {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unite(rootU, rootV);
            count++;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}
