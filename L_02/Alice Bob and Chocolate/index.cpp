#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = n - 1, consume1 = 0, consume2 = 0, count1 = 0, count2 = 0;
    while (i <= j)
    {
        if (consume1 == consume2 && i == j)
        {
            count1++;
            break;
        }
        if (consume1 == 0)
        {
            count1++;
            consume1 = arr[i];
            i++;
        }
        if (consume2 == 0)
        {
            count2++;
            consume2 = arr[j];
            j--;
        }
        if (consume1 < consume2)
        {
            consume2 -= consume1;
            consume1 = 0;
        }
        else if (consume1 > consume2)
        {
            consume1 -= consume2;
            consume2 = 0;
        }
        else
        {
            consume1 = consume2 = 0;
        }
    }

    cout << count1 << " " << count2 << endl;

    return 0;
}