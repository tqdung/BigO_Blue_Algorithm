#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 5;
bool fre_x[MAX], fre_y[MAX];

bool compare(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.first == y.first)
    {
        return x.second < y.second;
    }
    return x.first < y.first;
}

int main()
{
    pair<int, int> points[8];
    vector<int> X, Y;

    for (int i = 0; i < 8; i++)
    {
        cin >> points[i].first;
        cin >> points[i].second;
        if (!fre_x[points[i].first])
        {
            X.push_back(points[i].first);
            fre_x[points[i].first] = true;
        }
        if (!fre_y[points[i].second])
        {
            Y.push_back(points[i].second);
            fre_y[points[i].second] = true;
        }
    }
    if (X.size() != 3 || Y.size() != 3)
    {
        cout << "ugly" << endl;
        return 0;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(points, points + 8, compare);

    int index = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && i == 1)
            {
                continue;
            }
            if (X[i] == points[index].first && Y[j] == points[index].second)
            {
                index++;
            }
            else
            {
                cout << "ugly";
                return 0;
            }
        }
    }

    cout << "respectable";
    return 0;
}