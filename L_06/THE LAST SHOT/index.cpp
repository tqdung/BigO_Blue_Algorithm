#include <iostream>
#include <stack>
#include <vector>
#include <math.h>

#define MAX 10005
using namespace std;
int visited[MAX];
vector<int> graph[MAX];

int DFS(int s)
{
    stack<int> stack;
    stack.push(s);
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = false;
    }
    visited[s] = true;
    int counter = 1;

    while (!stack.empty())
    {
        int u = stack.top();
        stack.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (visited[v] == true)
            {
                continue;
            }
            else
            {
                counter++;
            }
            visited[v] = true;
            stack.push(v);
        }
    }
    visited[s] = false;
    return counter;
}

int main()
{
    int n, m, a, b, max_booms = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        max_booms = max(max_booms, DFS(i));
    }
    cout << max_booms << endl;
    return 0;
}