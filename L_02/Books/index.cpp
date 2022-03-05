#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int books, time;
    cin >> books >> time;
    int arr[books];

    for (int i = 0; i < books; i++)
    {
        cin >> arr[i];
    }

    int max_books = 0, read_books = 0, j = 0;
    ;
    for (int i = 0; i < books; i++)
    {
        while (time < arr[i])
        {
            time += arr[j];
            j++;
            read_books--;
        }
        time -= arr[i];
        read_books++;
        max_books = max(max_books, read_books);
    }
    cout << max_books << endl;
    return 0;
}