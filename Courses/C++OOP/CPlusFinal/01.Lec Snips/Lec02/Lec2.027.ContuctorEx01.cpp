class Complex {
    int real;
    int img;

public:
    Complex() { // <- Constructor without any parameters

    }

    Complex(int _real, int _img) { // <- Constructor with parameters
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
    Complex c1(10, -12);
    Complex c2(7, 5);

    cout << "\n\n=> c1 = ";
    c1.print();

    cout << "\n\n=> c2 = ";
    c2.print();

    cout << "\n\n=> sum = ";
    Complex sum = c1.add(c2);
    sum.print();

    return 0;
}