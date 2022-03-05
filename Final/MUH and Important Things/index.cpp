#include <iostream>
#include <algorithm>

#define MAX 2002
using namespace std;
int jobs_complex[MAX];

int main()
{
    int n;
    cin >> n;
    int counter = 0;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);
    for (int i = 0; i + 1 < n; i++)
    {
        if (arr[i].first == arr[i + 1].first)
            counter++;
        if (counter == 2)
        {
            cout << "YES" << endl;
            for (int j = 0; j < n; j++)
            {
                cout << arr[j].second + 1 << " ";
            }
            cout << endl;
            counter = 0;
            for (int j = 0; j + 1 < n; j++)
            {
                if (arr[j].first == arr[j + 1].first)
                {
                    counter++;
                    swap(arr[j].second, arr[j + 1].second);
                    for (int k = 0; k < n; k++)
                        cout << arr[k].second + 1 << " ";
                    cout << endl;
                    swap(arr[j].second, arr[j + 1].second);
                }
                if (counter == 2)
                    return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}