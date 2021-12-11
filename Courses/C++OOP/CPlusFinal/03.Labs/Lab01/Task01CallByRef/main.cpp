#include <iostream>

using namespace std;

void swap(int &x, int &y);

int main()
{
    cout << endl << "--------------------" << endl;
    cout << "Call By Reference";
    cout << endl << "--------------------" << endl << endl;

    int a, b;

    cout << "Enter the first value a:" << endl;
    cin >> a;

    cout << "Enter the second value b:" << endl;
    cin >> b;

    cout << "\n\n==> Before swapping a=" << a << " b=" << b;

    swap(a, b);

    cout << "\n==> After swapping a=" << a << " b=" << b << endl;

    return 0;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
