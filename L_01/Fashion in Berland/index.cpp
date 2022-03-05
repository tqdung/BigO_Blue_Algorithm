#include <iostream>
#include <vector>
using namespace std;

bool checkJacket(vector<int> &v, int n)
{
    if (n == 1)
    {
        return v[0] == 1;
    }
    int counter = 0;
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        if (*it == 0)
            counter++;
        if (counter > 1)
            return false;
    }
    return counter == 1;
}

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
    string result = checkJacket(v, number);
    if (result == true)
    {
        cout << "YES"
    }
    else
    {
        cout << "NO";
    }
    return 0;
}