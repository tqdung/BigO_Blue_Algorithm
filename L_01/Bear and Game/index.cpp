#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int number, value;
    cin >> number;
    vector<int> v;
    for (int i = 0; i < number; i++)
    {
        cin >> value;
        v.push_back(value);
    }
    vector<int>::iterator it;
    int mins = 0;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (mins + 15 < *it)
        {
            mins += 15;
            cout << mins << endl;
            return 0;
        }
        mins = *it;
    }
    mins = min(mins + 15, 90);
    cout << mins << endl;
    return 0;
}