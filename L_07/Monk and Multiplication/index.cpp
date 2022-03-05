#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (i < 2)
        {
            cout << -1 << endl;
            continue;
        }
        long long max1, max2, max3;
        max1 = pq.top();
        pq.pop();
        max2 = pq.top();
        pq.pop();
        max3 = pq.top();
        pq.pop();
        pq.push(max1);
        pq.push(max2);
        pq.push(max3);
        cout << max1 * max2 * max3 << endl;
    }
}