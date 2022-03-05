#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long k, n, w;
    cin >> k >> n >> w;

    long totalBanana = (w * (w + 1)) / 2;
    long totalMoney = totalBanana * k;
    long borrow = max(totalMoney - n, 0L);
    cout << borrow << endl;

    return 0;
}