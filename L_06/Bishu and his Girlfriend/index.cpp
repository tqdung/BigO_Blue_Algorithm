#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#define MAX 1001

using namespace std;
vector<int> graph[MAX];
int visited[MAX], dist[MAX], min_dist[MAX];
int min_value;

void BFS(int s, int f)
{
    stack<int> stack;
    stack.push(s);
    visited[s] = true;
    bool exit = false;

    while (!stack.empty())
    {
        int u = stack.top();
        stack.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (visited[v] == false)
            {
                visited[v] = true;
                stack.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    if (dist[f] > 0)
    {
        min_value = min_value <= 0 ? dist[f] : min(min_value, dist[f]);
        min_dist[dist[f]] = min_dist[dist[f]] <= 0 ? f : min(min_dist[dist[f]], f);
    }
}

int main()
{
    int n, u, v, q;
    int arr[MAX];
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        BFS(1, arr[i]);
    }
    cout << min_dist[min_value] << endl;
    return 0;
}