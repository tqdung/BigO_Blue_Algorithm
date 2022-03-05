#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    vector<int> temp;
    priority_queue<int, vector<int>, greater<int>> m_pq;
    priority_queue<int, vector<int>, greater<int>> remove_pq;
    int n, q, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        if (q == 1 || q == 2)
        {
            cin >> v;
        }
        switch (q)
        {
        case 1:
            m_pq.push(v);
            break;
        case 2:
            remove_pq.push(v);
            break;
        case 3:
            while (!remove_pq.empty() && m_pq.top() == remove_pq.top())
            {
                m_pq.pop();
                remove_pq.pop();
            }

            cout << m_pq.top() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}