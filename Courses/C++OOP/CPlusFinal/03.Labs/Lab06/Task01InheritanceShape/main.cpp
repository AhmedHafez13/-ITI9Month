#include <iostream>

#define PI (3.14285f)

using namespace std;

class Shape {
protected:
    int dim1;
    int dim2;
public:
    Shape(int _dim1) {
        dim1 = _dim1;
    }
    Shape(int _dim1, int _dim2) {
        dim1 = _dim1;
        dim2 = _dim2;
    }

    void setDim1(int _dim1) {
        dim2 = dim1;
    }
    int getDim1() {
        return dim1;
    }

    void setDim2(int _dim2) {
        dim2 = _dim2;
    }
    int getDim2() {
        return dim2;
    }

    virtual float calcArea() = 0;
};

class Rect : public Shape {
public:
    Rect(int length, int width) : Shape(length, width) {

    }

    float calcArea() {
        return dim1 * dim2;
    }
};

class Triangle : public Shape {
public:
    Triangle(int _dim1, int _dim2) : Shape(_dim1, _dim2) {

    }

    float calcArea() {
        return 0.5f * dim1 * dim2;
    }
};

class Circle : public Shape {
public:
    Circle(int _radius) : Shape(_radius) {

    }

    float calcArea() {
        return PI * (float) dim1 * (float) dim1;
    }
};

void calculateArea(Shape* shape) {
    float area = shape->calcArea();

    cout << endl << "Area = " << area << endl;
}

void calculateAreaSum(Shape** shapes, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += shapes[i]->calcArea();
    }
    cout << endl << "Area Sum = " << sum << endl;
}

int main()
{
    Rect rectangle1(10, 5); // 50
    Triangle triangle1(10, 5); // 25
    Circle circle1(10); // 25

    calculateArea(&rectangle1);
    calculateArea(&triangle1);
    calculateArea(&circle1);

    Shape* shapes[5];

    shapes[0] = &rectangle1;
    shapes[1] = &triangle1;
    shapes[2] = new Rect(5, 5); // 25
    shapes[3] = new Triangle(20, 10); // 100
    shapes[4] = new Circle(10); //314.2857142857143

    cout << endl << "Calculate the sum of areas: " << endl;

    calculateAreaSum(shapes, 5);

    return 0;
}
