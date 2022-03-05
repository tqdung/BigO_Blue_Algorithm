#include <iostream>

using namespace std;

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == 'z')
        {
            s[i] = 'a';
        }
        else
        {
            s[i]++;
            break;
        }
    }
    cout << (s == t ? "No such string" : s) << endl;
    return 0;
}