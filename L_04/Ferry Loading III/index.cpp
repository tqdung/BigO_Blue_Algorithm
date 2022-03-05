#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define MAX 10005

struct Car
{
    int index, time;
};

int main()
{
    int n, t, m, Q;
    int res[MAX];
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        queue<Car> queueSide[2];
        cin >> n >> t >> m;

        if (i != 0)
        {
            cout << endl;
        }
        for (int i = 0; i < m; i++)
        {
            int time;
            string side;
            cin >> time >> side;
            Car car;
            car.index = i;
            car.time = time;
            if (side == "left")
            {
                queueSide[0].push(car);
            }
            else
            {
                queueSide[1].push(car);
            }
        }

        int curSide = 0, curTime = 0, counter = 0, nextTime;
        while (counter < m)
        {
            if (queueSide[0].empty() && !queueSide[1].empty() || queueSide[1].empty() && !queueSide[0].empty())
            {
                nextTime = (queueSide[0].empty() ? queueSide[1].front().time : queueSide[0].front().time);
            }
            else
            {
                nextTime = min(queueSide[0].front().time, queueSide[1].front().time);
            }
            curTime = max(curTime, nextTime);
            int j = 0;
            while (!queueSide[curSide].empty())
            {
                Car car = queueSide[curSide].front();
                if (car.time <= curTime && j < n)
                {
                    res[car.index] = curTime + t;
                    queueSide[curSide].pop();
                    counter++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            curTime += t;
            curSide = 1 - curSide;
        }
        for (int i = 0; i < m; i++)
        {
            cout << res[i] << endl;
        }
    }
    return 0;
}