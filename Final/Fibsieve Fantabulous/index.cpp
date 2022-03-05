#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long seconds, root, lackings, row, column;
        cin >> seconds;
        root = ceil(sqrt(seconds * 1.0));
        lackings = root * root - seconds;
        if (lackings < root)
        {
            row = root;
            column = lackings + 1;
        }
        else
        {
            column = root;
            row = seconds - (root - 1) * (root - 1);
        }
        if (root % 2 == 0)
        {
            long long temp = column;
            column = row;
            row = temp;
        }
        cout << "Case " << i << ": " << column << " " << row << endl;
    }

    return 0;
}