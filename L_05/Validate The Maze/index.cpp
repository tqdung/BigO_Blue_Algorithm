#include <iostream>
#include <queue>
#include <vector>
#define MAX 20 + 5

using namespace std;
struct Cell
{
    int row, col;
};
string maze[MAX];
bool visited[MAX][MAX];
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int m, n;

bool isValid(int r, int c)
{
    return r >= 0 && r < m && c >= 0 && c < n;
}

bool BFS(Cell s, Cell f)
{
    queue<Cell> q;
    q.push(s);
    visited[s.row][s.col] = true;

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();
        if (u.row == f.row && u.col == f.col)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (isValid(r, c) && maze[r][c] == '.' && visited[r][c] == false)
            {
                visited[r][c] = true;
                q.push((Cell){r, c});
            }
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        // init maze
        for (int i = 0; i < m; i++)
        {
            cin >> maze[i];
        }
        vector<Cell> entrance;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = false;
                if (maze[i][j] == '.' && (i == 0 || j == 0 || i == m - 1 || j == n - 1))
                {
                    entrance.push_back((Cell){i, j});
                }
            }
        }
        if (entrance.size() != 2)
        {
            cout << "invalid" << endl;
            continue;
        }
        Cell s = entrance[0];
        Cell f = entrance[1];
        bool valid = BFS(s, f);
        cout << (valid ? "valid" : "invalid") << endl;
    }

    return 0;
}