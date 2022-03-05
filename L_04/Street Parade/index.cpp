#include <iostream>
#include <stack>

using namespace std;
#define MAX 1000 + 5

int main()
{
    int n;
    int arr[MAX];
    stack<int> s;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i = 0, nextCar = 1;
        while (i < n)
        {
            if (arr[i] == nextCar)
            {
                i++;
                nextCar++;
            }
            else if (!s.empty() && s.top() == nextCar)
            {
                nextCar++;
                s.pop();
            }
            else
            {
                s.push(arr[i]);
                i++;
            }
        }
        while (!s.empty() && s.top() == nextCar)
        {
            nextCar++;
            s.pop();
        }
        cout << (nextCar - 1 == n ? "yes" : "no") << endl;
        s = stack<int>();
    }
    return 0;
}