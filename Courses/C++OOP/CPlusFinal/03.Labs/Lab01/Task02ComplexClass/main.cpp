#include <iostream>

using namespace std;

class ComplexNumber
{
    int real, imaginary;

    public:
    void setReal(int _real)
    {
        real = _real;
    }

    void setImaginary(int _imaginary)
    {
        imaginary = _imaginary;
    }

    int getReal()
    {
        return real;
    }

    int getImaginary()
    {
        return imaginary;
    }

    void print()
    {
        cout << endl;
        if (imaginary > 0) {
            cout << "==>" << real << "+" << imaginary << "i";
        } else if (imaginary < 0) {
            cout << "==>" << real << imaginary << "i";
        } else {
            cout << "==>" << real;
        }
    }

    ComplexNumber add(ComplexNumber number)
    {
        ComplexNumber result;
        result.real = real + number.real;
        result.imaginary = imaginary + number.imaginary;
        return result;
    }
};

void printComplex(ComplexNumber number);
ComplexNumber addComplex(ComplexNumber c1, ComplexNumber c2);

int main()
{
    cout << endl << "--------------------" << endl;
    cout << "Complex Class";
    cout << endl << "--------------------" << endl << endl;

    ComplexNumber c1, c2;

    c1.setReal(5);
    c1.setImaginary(2);

    c2.setReal(-3);
    c2.setImaginary(6);

    cout << endl << endl << "Print Using Object Function print()";
    c1.print();
    c2.print();

    cout << endl << endl<< "Print Using standalone Function printComplex()";
    printComplex(c1);
    printComplex(c2);

    cout << endl << endl << "Sum two numbers using Object Function add()";
    ComplexNumber res1 = c1.add(c2);
    printComplex(res1);

    cout << endl << endl << "Sum two numbers using standalone Function addComplex()";
    ComplexNumber res2 = addComplex(c1, c2);
    printComplex(res2);

    return 0;
}

void printComplex(ComplexNumber number)
{
    cout << endl;
    if (number.getImaginary() > 0) {
        cout << "==>" << number.getReal() << "+" << number.getImaginary() << "i";
    } else if (number.getImaginary() < 0) {
        cout << "==>" << number.getReal() << number.getImaginary() << "i";
    } else {
        cout << "==>" << number.getReal();
    }
}

ComplexNumber addComplex(ComplexNumber c1, ComplexNumber c2)
{
    ComplexNumber result;
    result.setReal(c1.getReal() + c2.getReal());
    result.setImaginary(c1.getImaginary() + c2.getImaginary());
    return result;
}
