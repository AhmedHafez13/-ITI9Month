#include <iostream>

using namespace std;

int main()
{
    int x = 11;

    cout << "x value: " << x << endl;

    int &y = x;

    y = 22;

    cout << "x value after modifying using ref y: " << x << endl;

    return 0;
}
