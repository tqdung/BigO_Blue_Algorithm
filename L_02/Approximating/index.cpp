#include <iostream>
#include <algorithm>
#include <math.h>

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
    if (n <= 2)
    {
        cout << (abs(arr[0] - arr[1]) <= 1 ? 2 : 1) << endl;
        return 0;
    }
    int max_length = 0, left = 0, right = 2, min_value = min(arr[0], arr[1]), max_value = max(arr[0], arr[1]);
    int count = 0;
    while (right < n)
    {
        if (arr[right] > max_value)
        {
            max_value = arr[right];
        }
        if (arr[right] < min_value)
        {
            min_value = arr[right];
        }
        if (max_value - min_value > 1)
        {
            max_length = max(right - left, max_length);
            left = right;
            while (left >= 0)
            {
                count++;
                if (abs(arr[right] - arr[left]) > 1)
                {
                    left++;
                    break;
                }
                left--;
            }
            if (arr[left] > arr[right])
            {
                max_value = arr[left];
            }
            if (arr[left] < arr[right])
            {
                min_value = arr[left];
            }
        }
        count++;
        right++;
    }
    cout << "count: " << count << endl;
    cout << max(max_length, right - left) << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;
// const int MAX = 1e5 + 5;

// int fre[MAX];

// int main()
// {
//     int n, count = 0;
//     cin >> n;
//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     int j = 0, diff = 0;
//     int longest_range = 0;

//     for (int i = 0; i < n; i++)
//     {
//         count++;
//         if (fre[a[i]] == 0)
//         {
//             diff++;
//         }
//         fre[a[i]]++;

//         while (j < n && diff > 2)
//         {
//             count++;
//             if (fre[a[j]] == 1)
//             {
//                 diff--;
//             }
//             fre[a[j]]--;
//             j++;
//         }

//         longest_range = max(longest_range, i - j + 1);
//     }
//     cout << "count: " << count << endl;
//     cout << longest_range;
//     return 0;
// }