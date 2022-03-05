#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    for (int i = 0, j = 0; i < n && j < m; j++)
    {
        if (arr2[j] >= arr1[i])
        {
            count++;
            i++;
        }
    }
    cout << n - count << endl;
    return 0;
}