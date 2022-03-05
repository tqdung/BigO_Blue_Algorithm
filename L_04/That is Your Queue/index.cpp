#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    int p, n, x, test_case = 1, temp;
    char command;
    queue<int> q;
    while (true)
    {
        cin >> p >> n;
        if (p == 0 || n == 0)
            break;
        for (int i = 1; i <= min(p, n); i++)
        {
            q.push(i);
        }
        cout << "Case " << test_case++ << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> command;
            if (command == 'N')
            {
                temp = q.front();
                cout << temp << endl;
                q.pop();
                q.push(temp);
            }
            else
            {
                cin >> x;
                int queue_size = q.size();
                q.push(x);

                for (int j = 0; j < queue_size; j++)
                {
                    temp = q.front();
                    q.pop();
                    if (temp != x)
                    {
                        q.push(temp);
                    }
                }
            }
        }
        q = queue<int>();
        /* code */
    }
    return 0;
}