#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    long total = 0;
    vector<long> v;
    vector<long>::iterator it;
    long value;

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }
    if (x > 1)
    {
        sort(v.begin(), v.end());
    }
    for (it = v.begin(); it != v.end(); it++)
    {
        total += *it * x;
        if (x > 1)
        {
            x = x - 1;
        }
    }

    cout << total << endl;

    return 0;
}