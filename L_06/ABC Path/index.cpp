#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <math.h>

#define MAX 105
using namespace std;
unsigned int longest_path;
int R, C;
int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
const string term = "ABCDE";
char map[MAX][MAX];
int visited[MAX][MAX];

struct Cell
{
    int row, col;
};

bool isValid(int row, int col)
{
    return row >= 0 && row < R && col >= 0 && col < C;
}

int DFS(Cell start)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int r = start.row + dr[i];
        int c = start.col + dc[i];

        if (isValid(r, c) && map[r][c] - map[start.row][start.col] == 1 && visited[r][c] == 0)
        {
            DFS((Cell){r, c});
            count = max(count, visited[r][c]);
        }
    }
    visited[start.row][start.col] = count + 1;
    return visited[start.row][start.col];
}

int main()
{
    int counter = 1;
    while (true)
    {
        int longest_path = 0;
        cin >> R >> C;
        if (R == 0 && C == 0)
        {
            return 0;
        }
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i][j] == 'A')
                {
                    longest_path = max(longest_path, DFS((Cell){i, j}));
                }
            }
        }
        cout << "Case " << counter << ": " << longest_path << endl;
        counter++;
    };

    return 0;
}