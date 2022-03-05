#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
const int MAX = 2e5 + 5;

struct Query
{
    long long time, duration;
};

int main()
{
    long long res[MAX];
    queue<long long> queryQueue;
    int n = 5, b = 1;
    long long nextTime = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        Query query;
        cin >> query.time >> query.duration;
        while (!queryQueue.empty() && queryQueue.front() <= query.time)
        {
            queryQueue.pop();
        }

        if (queryQueue.size() <= b)
        {
            nextTime = max(nextTime, query.time) + query.duration;
            res[i] = nextTime;
            queryQueue.push(nextTime);
        }
        else
        {
            res[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}