#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {0};
    int n, k;
    cin >> n >> k;
    string s, password;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr[s.size()]++;
    }
    cin >> password;
    int bestTime = 0, worstTime = 0;

    for (int i = 0; i < password.size(); i++)
    {
        bestTime += arr[i];
    }
    worstTime = bestTime + arr[password.size()] - 1;
    bestTime += (bestTime / k) * 5;
    worstTime += (worstTime / k) * 5;

    cout << bestTime + 1 << " " << worstTime + 1;
    return 0;
}
