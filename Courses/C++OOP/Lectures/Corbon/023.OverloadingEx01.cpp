// ----- * ----- Overloading ----- * ----- //

int add(int x, int y) {
    return x + y;
}

float add(float x, float y) {
    return x + y;
}

int add(int x, int y, int z) {
    return x + y + z;
}

int add(int a1, int a2, int a3, int a4) {
    return a1 + a2 + a3 + a4;
}

int main()
{
    cout << "call add with 2 int parameters" << endl;          
    int res1 = add(5, 10);
    cout << "res1 = " << res1 << endl << endl;

    cout << "call add with 2 float parameters" << endl;
    float res2 = add((float) 5.3, (float) 4.2);
    cout << "res2 = " << res2 << endl << endl;

    cout << "call add with 3 parameters" << endl;
    int res3 = add(5, 10, 20);
    cout << "res3 = " << res3 << endl << endl;

    cout << "call add with 4 parameters" << endl;
    int res4 = add(5, 10, 20, 5);
    cout << "res3 = " << res4 << endl << endl;

    return 0;
}