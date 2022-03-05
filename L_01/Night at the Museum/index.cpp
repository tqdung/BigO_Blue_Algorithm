#include <iostream>
using namespace std;

int main(void)
{
    char pointer = 'a';
    int distance, count = 0;
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        distance = abs(str[i] - pointer);
        if (distance < 13)
        {
            count += distance;
        }
        else
        {
            count += (26 - distance);
        }
        cout << "distance: " << distance << endl;
        cout << "count: " << count << endl;
        pointer = str[i];
    }

    cout << count << endl;
    return 0;
}