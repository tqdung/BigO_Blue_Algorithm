#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
#define MAX 100
const int INF = 10e9;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];

struct option
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
}

void
Prim()
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = false;
        path[i] = -1;
        dist[i] = INF;
    }
    priority_queue<pair<int, int>, vector<int, int>, option> pq;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b, k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> k;
        graph[a].push_back(b, k);
        graph[b].push_back(a, k);
    }
    cout << Prim() << endl;
    return 0;
}