#include <iostream>
#include <queue>
#include <string>
#define MAX 501

using namespace std;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int N, M;
string cave[MAX];

struct Cell
{
    int row, col;
};

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < N && c < M;
}

bool BFS(Cell s, Cell f)
{
    queue<Cell> q;
    q.push(s);
    cave[s.row][s.col] = 'X';

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (r == f.row && c == f.col && cave[r][c] == 'X')
            {
                return true;
            }
            if (isValid(r, c) && cave[r][c] == '.')
            {
                cave[r][c] = 'X';
                q.push((Cell){r, c});
            }
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> cave[i];
    }
    Cell s, f;
    cin >> s.row >> s.col >> f.row >> f.col;
    s.row -= 1;
    s.col -= 1;
    f.row -= 1;
    f.col -= 1;
    bool valid = BFS(s, f);
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}