#include <iostream>
#include <stack>
#include <string>

using namespace std;
const int MAX = 10e5 + 5;

int main()
{
    stack<char> s;
    long long res[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        string str;
        cin >> str;
        for (long j = 0; j < str.length(); j++)
        {
            char c = str[j];
            if (c == '<')
            {
                s.push(c);
            }
            else if (s.empty())
            {
                break;
            }
            else
            {
                s.pop();
                total = s.empty() ? j + 1 : total;
            }
        }
        cout << total << endl;
        s = stack<char>();
    }
    return 0;
}