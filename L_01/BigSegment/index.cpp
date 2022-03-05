#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main()
{
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    int left = INF, right = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> L[i] >> R[i];
        left = min(left, L[i]);
        right = max(right, R[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (left == L[i] && right == R[i])
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}