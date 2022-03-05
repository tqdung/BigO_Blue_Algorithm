#include <iostream>
#include <queue>
#include <string>
#define MAX 22

using namespace std;
int w, h;
int visited[MAX][MAX];
string land[MAX];
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell
{
    int row, col;
};

bool isValid(int r, int c)
{
    return r >= 0 && r < h && c >= 0 && c < w;
}

int BFS(Cell s)
{
    int counter = 0;
    queue<Cell> q;
    q.push(s);
    counter += 1;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            visited[i][j] = false;
        }
    }

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (isValid(r, c) && visited[r][c] == false && land[r][c] == '.')
            {
                visited[r][c] = true;
                counter++;
                q.push((Cell){r, c});
            }
        }
    }
    return counter;
}

int main()
{
    int t;
    cin >> t;
    int j = 1;
    while (t--)
    {
        bool sFound = false;
        Cell s;
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            cin >> land[i];
            if (!sFound)
            {
                int sIdx = land[i].find('@');
                if (sIdx >= 0)
                {
                    sFound = true;
                    s.row = i;
                    s.col = sIdx;
                }
            }
        }
        cout << "Case " << j << ": " << BFS(s) << endl;
        j++;
    }

    return 0;
}