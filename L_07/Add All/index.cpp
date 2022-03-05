#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    long long n, val;
    priority_queue<int, vector<int>, greater<int>> q;
    while (true)
    {
        cin >> n;
        if (n <= 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> val;
            q.push(val);
        }
        long long total = 0;
        while (q.size() > 1)
        {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            total += first + second;
            q.push(first + second);
        }
        cout << total << endl;
        q = priority_queue<int, vector<int>, greater<int>>();
    }

    return 0;
}