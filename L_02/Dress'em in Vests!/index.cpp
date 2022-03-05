#include <iostream>
#include <vector>

using namespace std;

struct Vest
{
    int u, v;
};

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int expect_sizes[n], sizes_in_stock[m];

    for (int i = 0; i < n; i++)
    {
        cin >> expect_sizes[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> sizes_in_stock[i];
    }

    vector<Vest> v;
    vector<Vest>::iterator it;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (expect_sizes[i] - x <= sizes_in_stock[j] && sizes_in_stock[j] <= expect_sizes[i] + y)
        {
            Vest *vest = new Vest();
            vest->u = i + 1;
            vest->v = j + 1;
            v.push_back(*vest);
            i++;
            j++;
        }
        else if (expect_sizes[i] + y < sizes_in_stock[j])
        {
            i++;
        }
        else if (expect_sizes[i] - x > sizes_in_stock[j])
        {
            j++;
        }
    }
    cout << v.size() << endl;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << it->u << " " << it->v << endl;
    }

    return 0;
}