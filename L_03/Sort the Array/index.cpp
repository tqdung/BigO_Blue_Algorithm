#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
        v2[i] = v1[i];
    }

    sort(v2.begin(), v2.end());
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] != v2[i])
        {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v1[i] != v2[i])
        {
            right = i;
            break;
        }
    }
    for (int i = left, j = right; i < j; i++, j--)
    {
        swap(v1[i], v1[j]);
    }
    if (v1 != v2)
    {
        cout << "no";
        return 0;
    }

    cout << "yes" << endl;
    cout << left + 1 << " " << right + 1;
    return 0;
}