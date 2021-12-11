#include <iostream>

using namespace std;

class Complex {
    int real;
    int img;

public:
    Complex() {
    }

    Complex(int _real, int _img) {
        real = _real;
        img = _img;
    }

    void setReal(int _real) {
        real = _real;
    }

    int getReal() {
        return real;
    }

    void setImg(int _img) {
        img = _img;
    }

    void setComplex(int _real, int _img) {
        real = _real;
        img = _img;
    }

    int getImg() {
        return img;
    }

    void print() {
        if (img > 0)
            cout << real << "+" << img << "J" << endl;
        else if (img < 0)
            cout << real << img << "J" << endl;
        else
            cout << real << endl;
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
    // Allocate just one place to store a Complex object
    Complex* ptr = new Complex(11, 22);
    ptr->print(); // Output: (11, 22)
    ptr->setComplex(1000, 2000);

    // ptr->print() === ptr[0].print()
    ptr->print(); // Output: (1000, 2000)
    ptr[0].print(); // Output: (1000, 2000)

    // No need in C# and JAVA, as they have a garbage collector
    delete[] ptr;

    // ----- * ----- * -----

    int x, y;
    Complex* arr = new Complex[3];
    for (int i = 0; i < 3; i++) {
        arr[i].setComplex(i * 2, i * 3);
    }

    for (int i = 0; i < 3; i++) {
        cout << "Item " << i + 1 << "> ";
        arr[i].print();
    }
    delete[] arr;

    return 0;
}
