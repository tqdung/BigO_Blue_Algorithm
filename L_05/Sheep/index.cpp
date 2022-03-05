#include <iostream>
#include <string>
#include <queue>
#define MAX 502

using namespace std;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int N, M, sheep = 0, wolfs = 0;
string map[MAX];

struct Cell
{
    int row, col;
};

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < N && c < M;
}

void BFS(Cell s)
{
    int sheepCount = 0, wolfCount = 0;
    bool escape = false;
    queue<Cell> q;
    q.push(s);
    if (map[s.row][s.col] == 'k')
    {
        sheepCount++;
    }
    else if (map[s.row][s.col] == 'v')
    {
        wolfCount++;
    }
    map[s.row][s.col] = '#';
    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (!isValid(r, c))
            {
                escape = true;
                continue;
            }
            if (map[r][c] != '#')
            {
                if (map[r][c] == 'k')
                {
                    sheepCount++;
                }
                if (map[r][c] == 'v')
                {
                    wolfCount++;
                }
                map[r][c] = '#';
                q.push((Cell){r, c});
            }
        }
    }
    if (escape)
    {
        sheep += sheepCount;
        wolfs += wolfCount;
    }
    else
    {
        sheepCount > wolfCount ? sheep += sheepCount : wolfs += wolfCount;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] != '#')
            {
                BFS((Cell){i, j});
            }
        }
    }
    cout << sheep << " " << wolfs << endl;

    return 0;
}