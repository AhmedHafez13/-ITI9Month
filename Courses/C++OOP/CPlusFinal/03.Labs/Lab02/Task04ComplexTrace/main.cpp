#include <iostream>

using namespace std;

class Complex {
    int real;
    int img;

public:
    Complex() { // <- Constructor without any parameters
        real = 0;
        img = 0;
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
            cout << "=> " << real << "+" << img << "i";
        else if (img < 0)
            cout << "=> " << real << img << "i";
        else
            cout << "=> " << real;
    }
};

void myFun(Complex c) {
    cout << "\n\n=> myFun is called" << endl;

    cout << "\n=> c is received (myFun), value of c: ";
    c.print();

    // ----- * ----- * -----

    Complex c5(-55, 55);

    cout << "\n\n=> c5 is created (myFun), value of c5: ";
    c5.print();

    cout << "\n\n=> end of (myFun)" << endl;
}

int main()
{
    cout << "\n=> main is called" << endl;

    Complex c1(11, -11);

    cout << "\n=> c1 is created (main), value of c1: ";
    c1.print();

    myFun(c1);

    // ----- * ----- * -----

    Complex c2(22, 22);

    cout << "\n\n=> c2 is created (main), value of c2: ";
    c2.print();

    Complex c3(333, 333);

    cout << "\n\n=> c3 is created (main), value of c3: ";
    c3.print();

    cout << "\n\n=> end of (main)" << endl;

    return 0;
}


