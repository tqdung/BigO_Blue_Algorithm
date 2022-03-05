#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, j = n - 1, max = 0, turn = 0;
    while (i <= j)
    {
        if (arr[i] < arr[j])
        {
            max = arr[j];
            j--;
        }
        else
        {
            max = arr[i];
            i++;
        }
        if (turn % 2 == 0)
        {
            a += max;
        }
        else
        {
            b += max;
        }
        turn++;
    }
    cout << a << " " << b << endl;
    return 0;
}