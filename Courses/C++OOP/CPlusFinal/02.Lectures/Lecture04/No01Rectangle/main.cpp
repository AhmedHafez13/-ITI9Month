#include <iostream>

#include "graphics.h"

using namespace std;

// ----- * ----- Point Class ----- * ----- //
class Point {
    int x;
    int y;

    public:
    Point() {
        x = y = 0;
        cout << endl <<"\nPoint Parameterless Default Constructor" << endl;
    }

    Point(int _x) {
        x = y = _x;
        cout << "\nPoint Constructor (x, x)\n";
    }

    Point(int _x, int _y) {
        cout << "\nPoint Constructor (x, y)\n";
        x = _x;
        y = _y;
    }

    Point(const Point& point) {
        cout << endl << "Point Copy Constructor" << endl;
        x = point.x;
        y = point.y;
    }

    ~Point() {
        cout << endl << "Point Destructor";
        print();
    }

    void setX(int _x) {
        x = _x;
    }

    int getX() {
        return x;
    }

    void setY(int _y) {
        y = _y;
    }

    int getY() {
        return y;
    }

    void setXY(int _x, int _y) {
        x = _x;
        y = _y;
    }

    void print() { // (x, y)
        cout << "> (" << x << ", " << y << ")" << endl;
    }
};

// ----- * ----- Rect Class ----- * ----- //
class Rect {
    private:
    Point ul; // upper left point
    Point lr; // lower right point

    public:
    /*Rect() {
        cout << "\nPoint Parameterless Default Constructor\n";
    }*/

    //                     Constructor Chain ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    Rect(int x1, int y1, int x2, int y2): ul(x1, y1), lr(x2, y2)
    {
        cout << "\nRectangle Constructor (x1, y1, x2, y2)\n";
        //ul.setX(x1);
        //ul.setY(y1);
        //lr.setX(x2);
        //lr.setY(y2);

        // No need to those 2 lines below when using (Constructor Chain)
        //ul.setXY(x1, y1);
        //lr.setXY(x2, y2);
    }

    Rect(Point _ul, Point _lr): ul(_ul), lr(_lr) // Copy Constructor *4
    {
        cout << "\nRectangle Constructor (_ul, _lr)\n";
        //ul = _ul;
        //lr = _lr;
    }

    ~Rect() {
        cout << endl << "Rect Destructor" << endl;
    }

    void setUL(int x, int y) {
        ul.setX(x);
        ul.setY(y);
    }

    void setUL(Point p) {
        ul = p;
    }

    Point getUL() {
        return ul;
    }

    void setLR(int x, int y) {
        lr.setX(x);
        lr.setY(y);
    }

    void setLR(Point p) {
        lr = p;
    }

    Point getLR() {
        return lr;
    }

    void print() {
        cout << endl << "ul";
        ul.print();
        cout << "lr";
        lr.print();
    }

    void draw() {
        // Draw rectangle
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

// ----- * ----- Circle Class ----- * ----- //
class Circle {
    Point center;
    int radius;

    public:
    Circle() {
        cout << endl << "Circle Parameterless Default Constructor" << endl;
        // TODO: (x, y) = (0, 0), r = 1
        center.setXY(0, 0);
        radius = 1;
    }

    Circle(int x, int y): center(x, y)
    {
        cout << endl << "Circle Constructor (x, y, r), center(x, y)" << endl;
        // TODO r = 1
        radius = 1;
    }

    Circle(int x, int y, int r): center(x, y)
    {
        cout << endl << "Circle Constructor (x, y, r), center(x, y)" << endl;
        // TODO r = 1
        radius = r;
    }

    Circle(Point p, int r): center(p)
    {
        cout << endl << "Circle Constructor (x, y, r)" << endl;
        // TODO
        radius = r;
    }

    ~Circle() {
        cout << endl << "Circle Destructor" << endl;
        // TODO
    }

    void setCenter(Point p) {
        // TODO
        center = p;
    }

    void setCenter(int x, int y) {
        // TODO
        center.setXY(x, y);
    }

    Point getCenter() {
        // TODO
        return center;
    }

    void setRadius(int r) {
        radius = r;
    }

    int getRadius() {
        // TODO
        return radius;
    }

    void print() {
        // TODO
        cout << endl << "center";
        center.print();
        cout << "radius > " << radius;
    }

    void draw() {
        // TODO
        circle(center.getX(), center.getY(), radius);
    }
};

// ----- * ----- Line Class ----- * ----- //
class Line {
    // TODO
};

// ----- * ----- Starting Point ----- * ----- //
int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");

    Rect r(300, 100, 400, 300);
    r.draw();
    r.print();

    Circle c(150, 200, 100);
    c.draw();

    //Sleep(5000);
    getch();
    closegraph();


    // #01 for testing, test all constructors
    /*
    Point p1(5, 9);
    //p1.setX(11);
    //p1.setY(22);

    p1.print();
    */

    // #02 for testing
    /*
    Rect r1;
    r1.ul.print();
    r1.lr.print();
    */

    /*
    Rect r1;

    r1.setUL(10, 20);
    r1.setLR(30, 40);

    r1.getUL().print();
    r1.getLR().print();
    */

    /*
    Rect r1;

    Point p1(50, 60), p2(70, 80);
    r1.setLR(p1);
    r1.setUL(p2);

    // Print using points
    r1.getLR().print();
    r1.getUL().print();

    // Print using rect
    r1.print();
    */

    /*
    Rect r1(10, 15, 20, 25);

    r1.print();
    */

    /*
    Point lr(44, 44);
    Point ul(66, 66);
    Rect r1(lr, ul); // Copy Constructor * 2

    r1.print();
    */



    return 0;
}
