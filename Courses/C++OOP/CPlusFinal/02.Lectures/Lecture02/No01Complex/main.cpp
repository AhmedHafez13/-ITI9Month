#include <iostream>

using namespace std;

class Complex {
    int real;
    int img;

public:
    void setReal(int _real) {
        real = _real;
    }

    int getReal() {
        return real;
    }

    void setImg(int _img) {
        img = _img;
    }

    int getImg() {
        return img;
    }

    void print() {
        if (img > 0)
            cout << real << "+" << img << "J";
        else if (img < 0)
            cout << real << img << "J";
        else
            cout << real;
    }

    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.img = img + c.img;
        return result;
    }
};

int main()
{
    /*
    Complex c1;
    c1.setReal(10);
    c1.setImg(20);
    //cout << c1.getReal() << endl << c1.getImg();
    cout << "\n\n=> img is positive" << endl;
    c1.print();


    c1.setReal(10);
    c1.setImg(-5);

    cout << "\n\n=> img is negative" << endl;
    c1.print();


    c1.setReal(10);
    c1.setImg(0);

    cout << "\n\n=> img equals zero" << endl;
    c1.print();
    */

    /*
    Complex c1, c2, sum;

    // Set c1 value and print
    c1.setReal(10);
    c1.setImg(0);
    cout << "\n\n=> c1 = ";
    c1.print();

    // Set c2 value and print
    c2.setReal(10);
    c2.setImg(5);
    cout << "\n\n=> c2 = ";
    c2.print();

    cout << "\n\n=> sum = ";
    sum = c1.add(c2);
    sum.print();


    return 0;
}
