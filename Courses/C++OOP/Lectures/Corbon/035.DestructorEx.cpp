#include <iostream>

using namespace std;

class Complex {
    int real;
    int img;

public:
    Complex() { // <- Constructor without any parameters

    }

    Complex(int _real) { // <- Constructor with 1 parameter
    real = _real;
    img = 0;
    }

    Complex(int _real, int _img) { // <- Constructor with 2 parameters
        real = _real;
        img = _img;
    }

    ~Complex() { // Destructor
        cout << "\n----- * Destructor is called! * ----- ";
        print();
    }

    void print() {
        if (img > 0)
            cout << "=> " << real << "+" << img << "J";
        else if (img < 0)
            cout << "=> " << real << img << "J";
        else
            cout << "=> " << real;
    }
};

void myFun() {
    cout << "\n=> myFun is called" << endl;

    Complex c10(10, -7);

    cout << "\n=> c10 is created (myFun), value of c10:" << endl;
    c10.print();

    cout << "\n\n=> end of myFun" << endl;
}

int main()
{
    cout << "\n=> main is called" << endl;

    myFun();

    cout << "\n\n=> end of main" << endl;

    return 0;
}