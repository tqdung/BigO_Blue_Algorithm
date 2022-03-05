#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string transform(string &expression)
{
    stack<char> s;
    string temp;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            continue;
        }
        else if (expression[i] == ')')
        {
            temp += s.top();
            s.pop();
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
        {
            s.push(expression[i]);
        }
        else
        {
            temp += expression[i];
        }
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    string exp;
    for (int i = 0; i < n; i++)
    {
        cin >> exp;
        v.push_back(exp);
    }
    vector<string>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << transform(*it) << endl;
    }
    return 0;
}