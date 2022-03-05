#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nA, nB, k, m;
    cin >> nA >> nB;
    cin >> k >> m;
    int value;

    vector<int> v1, v2;
    vector<int>::iterator it;
    int i;
    for (i = 0; i < nA; i++)
    {
        cin >> value;
        v1.push_back(value);
    }
    for (i = 0; i < nB; i++)
    {
        cin >> value;
        v2.push_back(value);
    }

    cout << (v1[k - 1] < v2[v2.size() - m] ? "YES" : "NO") << endl;

    return 0;
}