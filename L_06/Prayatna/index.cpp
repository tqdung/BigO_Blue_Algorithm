#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#define MAX 100005
using namespace std;

int visited[MAX];
vector<int> graph[MAX];

void DFS(int s)
{
    stack<int> stack;
    stack.push(s);
    visited[s] = true;
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
            }
        }
    }
}

int main()
{
    int t, n, e;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int u, v;
        cin >> n >> e;
        if (e == 0)
        {
            cout << n << endl;
            break;
        }
        for (int j = 0; j < n; j++)
        {
            visited[j] = false;
            graph[j].clear();
        }
        for (int j = 0; j < e; j++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                counter++;
                DFS(i);
            }
        }
        cout << counter << endl;
    }
    return 0;
}