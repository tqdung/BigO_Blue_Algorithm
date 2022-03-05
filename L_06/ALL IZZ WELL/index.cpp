#include <iostream>
#include <stack>
#include <vector>
#include <string>

#define MAX 105
using namespace std;
bool found;
int R, C;
int visited[MAX][MAX];
int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
const string term = "ALLIZZWELL";
char map[MAX][MAX];

struct Cell
{
    int row, col;
};

bool isValid(int row, int col)
{
    return row >= 0 && row < R && col >= 0 && col < C;
}

void DFS(Cell start, unsigned int count)
{
    if (count == term.size())
    {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int r = start.row + dr[i];
        int c = start.col + dc[i];

        if (isValid(r, c) && map[r][c] == term[count] && !visited[r][c])
        {
            visited[r][c] = true;
            DFS((Cell){r, c}, count + 1);
            visited[r][c] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }
        found = false;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i][j] == term[0] && !found)
                {
                    DFS((Cell){i, j}, 1);
                }
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}