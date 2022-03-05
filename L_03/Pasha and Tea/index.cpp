#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
typedef std::numeric_limits<double> dbl;

int main()
{
    int n, w;
    cin >> n >> w;
    double arr[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + (2 * n));
    double m = min(arr[0], arr[n] / 2);
    double x = min(3.0 * m * n, w * 1.0);
    cout.precision(dbl::digits10);
    cout << x << endl;
    return 0;
}