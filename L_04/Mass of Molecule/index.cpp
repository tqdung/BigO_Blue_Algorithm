#include <iostream>
#include <string>
#include <stack>

using namespace std;
#define MAX 105

int main()
{
    stack<int> s;
    string formula;
    int mass_of_molecule[MAX];
    int mass = 0;
    mass_of_molecule['H'] = 1;
    mass_of_molecule['C'] = 12;
    mass_of_molecule['O'] = 16;

    cin >> formula;

    for (int i = 0; i < formula.size(); i++)
    {
        if (isalpha(formula[i]))
        {
            s.push(mass_of_molecule[formula[i]]);
        }
        else if (formula[i] == '(')
        {
            s.push(-1);
        }
        else if (formula[i] == ')')
        {
            int temp = 0;
            while (s.top() != -1)
            {
                /* code */
                temp += s.top();
                s.pop();
            }
            s.pop();
            s.push(temp);
        }
        else if (isdigit(formula[i]))
        {
            int temp = s.top() * (formula[i] - '0');
            s.pop();
            s.push(temp);
        }
    }
    while (!s.empty())
    {
        int top = s.top();
        if (top != -1)
        {
            mass += top;
        }
        s.pop();
    }
    cout << mass << endl;
    return 0;
}