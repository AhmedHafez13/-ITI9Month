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

    Complex(int _real, int _img) { // <- Constructor with parameters
        real = _real;
        img = _img;
    }

    // 1
    Complex operator+(Complex c) {
        Complex result(real + c.real, img + c.img);
        /*Complex result;
        result.real = real + c.real;
        result.img = img + c.img;*/
        return result;
    }
    // 2
    Complex operator+(int n) {
        Complex result(real + n, img);
        return result;
    }
    // 3
    Complex operator++() { // Prefix
        real++;
        return *this;
    }
    // 4
    Complex operator++(int) { // int-> the key tells its a Postfix
        Complex result(real, img);
        real++;
        return result;
    }
    // 5
    int operator==(Complex c) {
        return real == c.real && img == c.img;
        /*if (real == c.real && img == c.img) {
            return 1;
        }
        return 0;*/
    }
    // 6
    int operator!=(Complex c) {
        return real != c.real || img != c.img;
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

// Stand alone function Takes two params (int and Comoplex)
// and returns a Complex result
Complex operator+(int n, Complex c) {
    Complex result(c.getReal() + n, c.getImg());
    return result;
}

// int built in data type


int main()
{
    cout << endl << "------------------------" << endl;
    cout << "Operator Overloading";
    cout << endl << "------------------------" << endl;

    // Create a Complex c1 without parameters
    Complex c1;
    c1.setReal(10);
    c1.setImg(-12);

    cout << "\n\n=> c1 = ";
    c1.print();

    // Create a Complex c2 with parameters
    Complex c2(7, -5), c3(7, -5);

    cout << "\n\n=> c2 = ";
    c2.print();
    cout << "\n\n=> c3 = ";
    c3.print();


    cout << "\n\n=> sum using member function = ";
    Complex sum = c1.add(c2);
    sum.print();

    cout << "\n\n=> (c1 + c2) sum2 = ";
    Complex sum2 = c1 + c2;
    // sum2 = c1.operator+(c2);
    // c1 -> caller, c2 -> parameter
    // operator+ -> function

    sum2.print();

    cout << "\n\n=> (c1 + 5) sum3 = ";
    Complex sum3 = c1 + 5;
    sum3.print();

    cout << "\n\n=> (4 + c1) sum4 = ";
    Complex sum4 = 4 + c1;
    sum4.print();

    cout << "\n\n=> (++c1) cPrefix = ";
    Complex cPrefix = ++c1;
    cPrefix.print();
    cout << "\n\n=> (c1) = ";
    c1.print();

    // c1 = 11-12J
    cout << "\n\n=> (c1++) cPostfix = ";
    Complex cPostfix = c1++;
    cPostfix.print();
    cout << "\n\n=> (c1) = "; //c1=12-12J
    c1.print();

    int isC1EqualsC2 = c1 == c2;
    cout << "\n\n=> (c1 == c2): " << isC1EqualsC2;

    int isC2EqualsC3 = c2 == c3;
    cout << "\n\n=> (c2 == c3): " << isC2EqualsC3;

    cout << endl;

    return 0;
}
