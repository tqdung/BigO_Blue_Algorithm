#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int getMax(queue<int> qq)
{
    int maxValue = -1;
    for (int i = 0; i < qq.size(); i++)
    {
        int value = qq.front();
        qq.pop();
        maxValue = max(value, maxValue);
        qq.push(value);
    }
    return maxValue;
}

void printer()
{
    int n, myPosition;
    cin >> n >> myPosition;
    int priority_arr[n];

    queue<int> q;
    int maxPriority = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> priority_arr[i];
        q.push(priority_arr[i]);
        maxPriority = max(maxPriority, priority_arr[i]);
    }

    int total = 0;
    while (!q.empty())
    {
        int value = q.front();
        // cout << "Front: " << value << " Max: " << maxPriority << endl;
        q.pop();
        if (value != maxPriority)
        {
            if (myPosition != 0)
            {
                myPosition--;
            }
            else
            {
                myPosition = q.size();
            }
            q.push(value);
        }
        else
        {
            total++;
            if (myPosition == 0)
            {
                cout << total << endl;
                return;
            }
            myPosition--;
            maxPriority = getMax(q);
        }
    }

    cout << total << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        printer();
    }
    return 0;
}