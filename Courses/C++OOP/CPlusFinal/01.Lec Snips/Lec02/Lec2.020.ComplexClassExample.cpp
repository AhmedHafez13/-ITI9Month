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
};

int main()
{
    Complex c1;
  
    c1.setReal(10);
    c1.setImg(20);

    cout << "\n\n=> img is positive" << endl;
    c1.print();	// output> 10+20J

  	// ----- * ----- * -----

    c1.setReal(10);
    c1.setImg(-5);

    cout << "\n\n=> img is negative" << endl;
    c1.print();	// output> 10-5J

  	// ----- * ----- * -----

    c1.setReal(10);
    c1.setImg(0);

    cout << "\n\n=> img equals zero" << endl;
    c1.print();	// output> 10

    return 0;
}
