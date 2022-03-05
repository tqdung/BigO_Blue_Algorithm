#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 10e5 + 5;
int n, m;
vector<int> graph[MAX];
int arr[MAX], visited[MAX], cats[MAX];

int BFS(int s)
{
    int restaurans = 0;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    cats[s] = arr[s];

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                if (arr[v] == 1)
                {
                    cats[v] = cats[u] + 1;
                }
                if (cats[v] <= m)
                {
                    if (graph[v].size() == 1)
                    {
                        restaurans++;
                    }
                    else
                    {
                        q.push(v);
                    }
                }
            }
        }
    }
    return restaurans;
}

int main()
{
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << BFS(1) << endl;
    return 0;
}