#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

float add(float x, float y) {
    return x + y;
}

double add(double x, double y) {
    return x + y;
}

int main()
{
    int i1 = 11, i2 = 22;
    float f1 = 1.5f, f2 = 3.2f;
  	double d1 = 2.3, d2 = 4.2;

    cout << endl << "i1 + i2, this will call -> int add(int x, int y)" << endl;
    int res1 = add(i1, i2);
    cout << "res1 = " << res1 << endl << endl;

    cout << "f1 + f2, this will call -> float add(float x, float y)" << endl;
    float res2 = add(f1, f2);
    cout << "res2 = " << res2 << endl << endl;

    cout << "d1 + d2, this will call -> double add(double x, double y)" << endl;
    double res3 = add(d1, d2);
    cout << "res3 = " << res3 << endl << endl;

    return 0;
}
