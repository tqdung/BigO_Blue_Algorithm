#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack<int> s;
    int arr[100] = {0};

    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = n; i > 0; i--)
        {
            s.push(i);
        }
        cout << "Discarded cards:";
        while (s.size() > 1)
        {
            cout << " " << s.top();
            if (s.size() > 2)
            {
                cout << ",";
            }
            s.pop();
            if (s.size() > 1)
            {
                int last = s.top();
                s.pop();
                int i = 0;
                while (!s.empty())
                {
                    arr[i] = s.top();
                    s.pop();
                    i++;
                }
                s.push(last);
                for (int j = i - 1; j >= 0; j--)
                {
                    s.push(arr[j]);
                }
            }
        }

        cout << endl
             << "Remaining card: " << s.top() << endl;
        s = stack<int>();
    }
    return 0;
}