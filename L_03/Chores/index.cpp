#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    cout << arr[b] - arr[b - 1] << endl;

    return 0;
}