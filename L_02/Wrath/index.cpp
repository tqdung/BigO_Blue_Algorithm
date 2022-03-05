#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0, j = n - 1, last_kill_pos = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        j = min(j, i);
        last_kill_pos = max(0, i - arr[i]);
        if (j > last_kill_pos)
        {
            count += (j - last_kill_pos);
            j = last_kill_pos;
        }
    }
    cout << n - count << endl;
    return 0;
}
