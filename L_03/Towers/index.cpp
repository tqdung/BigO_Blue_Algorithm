#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1000 + 5

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int towers_count = 1, max_height = 1, cur_height = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            cur_height++;
            max_height = max(cur_height, max_height);
        }
        else
        {
            towers_count++;
            cur_height = 1;
        }
    }
    cout << max_height << " " << towers_count << endl;
    return 0;
}