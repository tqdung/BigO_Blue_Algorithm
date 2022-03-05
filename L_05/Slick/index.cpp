#include <iostream>
#include <queue>
#include <vector>
#define MAX 251

using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int slick[MAX * MAX];
int table[MAX][MAX];
int N, M;

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
    queue<Cell> q;
    q.push(s);
    table[s.row][s.col] = 0;
    int count = 1;

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = u.row + dr[i];
            int c = u.col + dc[i];
            if (isValid(r, c) && table[r][c] == 1)
            {
                table[r][c] = 0;
                q.push((Cell){r, c});
                count++;
            }
        }
    }
    slick[count]++;
}

int main()
{
    while (true)
    {
        cin >> N >> M;
        if (M == 0 && N == 0)
        {
            break;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> table[i][j];
                slick[i * M + j + 1] = 0;
            }
        }
        int slicks = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (table[i][j] == 1)
                {
                    slicks++;
                    BFS((Cell){i, j});
                }
            }
        }
        cout << slicks << endl;
        for (int i = 1; i <= N * M; i++)
        {
            if (slick[i])
            {
                cout << i << " " << slick[i] << endl;
            }
        }
    };

    return 0;
}