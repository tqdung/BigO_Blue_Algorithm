#include <iostream>
#define MAX 100000 + 5
using namespace std;

int main()
{
    int map[MAX] = {0};
    int n, k;
    cin >> n >> k;
    int arr[n];
    int count = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (map[arr[i]] == 0)
        {
            count++;
        }
        map[arr[i]]++;
        while (count == k)
        {
            map[arr[j]]--;
            if (map[arr[j]] == 0)
            {
                cout << j + 1 << " " << i + 1;
                return 0;
            }
            j++;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}