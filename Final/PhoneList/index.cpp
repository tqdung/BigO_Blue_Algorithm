#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string phone_list[n];
        bool flag = true;
        size_t found;
        for (int i = 0; i < n; i++)
        {
            cin >> phone_list[i];
        }
        sort(phone_list, phone_list + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                if (phone_list[i].length() >= phone_list[j].length())

                    continue;

                found = phone_list[j].find(phone_list[i]);

                if (found == 0)
                {

                    flag = false;

                    break;
                }
            }

            if (!flag)
                break;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}