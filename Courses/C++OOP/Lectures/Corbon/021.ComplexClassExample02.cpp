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
  
  	/*
    Output
    -------
    => c1 = 10
	=> c2 = 10+5J
	=> sum = 20+5J
    */

    return 0;
}
