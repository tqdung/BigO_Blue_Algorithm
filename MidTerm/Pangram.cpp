#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool checked[26] = {false};
    int total = 0;

    if (n < 26)
    {
        cout << "NO";
        return 0;
    }

    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int charCode, index;
    for (int i = 0; i < n; i++)
    {
        charCode = int(arr[i]);
        index = charCode >= 97 ? charCode - 97 : charCode - 65;
        if (checked[index] == false)
        {
            checked[index] = true;
            total++;
        }
    }
    if (total != 26)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    return 0;
}