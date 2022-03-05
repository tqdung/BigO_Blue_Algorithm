#include <iostream>
#include <queue>
#define MAX 100005

using namespace std;

int keys[MAX];
int dist[MAX];
int s, f, n;

int BFS(int s, int f)
{
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            int v = (u * keys[i]) % 100000;
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (v == f)
                {
                    return dist[v];
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> s >> f >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }
    int distance = BFS(s, f);
    cout << distance << endl;
    return 0;
}