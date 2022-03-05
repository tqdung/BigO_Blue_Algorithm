#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX 252
using namespace std;
int n, m, k, lake_count;
int visited[MAX][MAX];
string map[MAX];

struct Cell
{
    int row, col;
};

bool isValid(int r, int c)
{
    return r >= 0 && r < m && c > 0 && c < n;
}

vector<Cell> lakes[1000];
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

void DFS(Cell s)
{
    stack<Cell> stack;
    stack.push(s);
    visited[s.row][s.col] = true;
    bool isOcean = false;
    vector<Cell> temp;

    while (!stack.empty())
    {
        Cell u = stack.top();
        stack.pop();
        temp.push_back(u);
        if ((u.row == 0 || u.row == m - 1 || u.col == 0 || u.col == n - 1) && map[u.row][u.col] == '.')
        {
            isOcean = true;
        }
        for (int i = 0; i < 4; i++)
        {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (isValid(r, c) && visited[r][c] == false && map[r][c] == '.')
            {
                Cell v = {r, c};
                visited[r][c] = true;
                stack.push(v);
            }
        }
    }
    if (!isOcean && temp.size() > 0)
    {
        for (int i = 0; i < temp.size(); i++)
        {
            lakes[lake_count].push_back(temp[i]);
        }
        lake_count++;
    }
}

bool compare(const vector<Cell> &a, const vector<Cell> &b)
{
    return a.size() < b.size();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> map[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && map[i][j] == '.')
            {
                DFS((Cell){i, j});
            }
        }
    }
    sort(lakes, lakes + lake_count, compare);

    int sum_cell = 0;

    for (int i = 0; i < lake_count - k; i++)
    {
        sum_cell += lakes[i].size();

        for (int j = 0; j < lakes[i].size(); j++)
        {
            Cell u = lakes[i][j];
            map[u.row][u.col] = '*';
        }
    }

    cout << sum_cell << endl;

    for (int i = 0; i < m; i++)
    {
        cout << map[i] << endl;
    }
    return 0;
}