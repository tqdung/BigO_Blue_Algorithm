#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 10e4 * 3 + 5;
int t, n, m, a, b;
int visited[MAX];
int flag[MAX];
int path[MAX];
vector<int> graph[MAX];
bool isLoop;

bool DFS(int s)
{
    stack<int> stack;
    stack.push(s);
    visited[s] = true;
    flag[s] = true;

    for (int i = 0; i < graph[s].size(); i++)
    {
        int v = graph[s][i];
        if (flag[v] == true)
        {
            isLoop = true;
            return true;
        }
        if (visited[v] == true)
        {
            continue;
        }
        DFS(v);
    }
    flag[s] = false;
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        isLoop = false;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            flag[i] = false;
            graph[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                DFS(i);
            }
        }
        cout << (isLoop ? "YES" : "NO") << endl;
    }
    return 0;
}