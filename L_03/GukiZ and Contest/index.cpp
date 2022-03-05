#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 2000 + 5

int main()
{
    int n;
    cin >> n;
    int arr[n], sorted_arr[n];
    int map[MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }
    sort(sorted_arr, sorted_arr + n);
    int j = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (map[sorted_arr[i]] == 0)
        {
            map[sorted_arr[i]] = j;
        }
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << map[arr[i]] << " ";
    }
    return 0;
}