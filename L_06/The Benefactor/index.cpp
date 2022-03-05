#include <iostream>
#include <string.h>
#include <vector>
#include <stack>

#define MAX 50000 + 5
using namespace std;

struct Triad
{
    int v, w;
};

int V, E, leaf;
long long max_dist;
long long dist[MAX];
vector<Triad> graph[MAX];

void DFS(int source)
{
    memset(dist, -1, sizeof(dist));
    stack<int> stack;
    dist[source] = 0;
    stack.push(source);

    while (!stack.empty())
    {
        int u = stack.top();
        stack.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].v;
            int w = graph[u][i].w;

            if (dist[v] == -1)
            {
                dist[v] = dist[u] + w;
                stack.push(v);

                if (dist[v] > max_dist)
                {
                    max_dist = dist[v];
                    leaf = v;
                }
            }
        }
    }
}

int main()
{
    int t, u, v, w;
    cin >> t;

    while (t--)
    {
        cin >> V;
        E = V - 1;

        for (int i = 0; i <= V; i++)
        {
            graph[i].clear();
        }

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v >> w;
            graph[u].push_back((Triad){v, w});
            graph[v].push_back((Triad){u, w});
        }

        max_dist = 0;

        DFS(1);
        DFS(leaf);

        cout << max_dist << endl;
    }

    return 0;
}