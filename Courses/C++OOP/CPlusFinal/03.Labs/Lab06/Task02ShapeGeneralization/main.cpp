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

// ----- * ----- GeoShape Class ----- * ----- //
class GeoShape {
public:
    virtual void print() = 0;
    virtual void draw() = 0;
};

// ----- * ----- Rect Class ----- * ----- //
class Rect : public GeoShape {
    Point ul; // upper left point
    Point lr; // lower right point

    public:
    /*Rect() {
        cout << "\nPoint Parameterless Default Constructor\n";
    }*/

    //                       Constructor Chain ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    Rect(int x1, int y1, int x2, int y2): ul(x1, y1), lr(x2, y2)
    {
        cout << "\nRectangle Constructor (x1, y1, x2, y2)\n";
    }

    Rect(Point _ul, Point _lr): ul(_ul), lr(_lr) // Copy Constructor *2
    {
        cout << "\nRectangle Constructor (_ul, _lr)\n";
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
class Circle : public GeoShape {
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
        circle(center.getX(), center.getY(), radius);
    }
};

// ----- * ----- Line Class ----- * ----- //
class Line : public GeoShape {
    Point p1; // first point
    Point p2; // second point

public:
    //                 Constructor Chain ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    Line(int x1, int y1, int x2, int y2): p1(x1, y1), p2(x2, y2)
    {
        cout << "\Line Constructor (x1, y1, x2, y2)\n";
    }

    ~Line() {
        cout << endl << "Line Destructor" << endl;
    }

    void print() {
        cout << endl << "p1";
        p1.print();
        cout << "p2";
        p2.print();
    }

    void draw() {
        line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
};

// ----- * ----- Picture Class ----- * ----- //
class Picture {
    GeoShape** shapes;
    int shapesCount;

public:
    Picture() {
        shapes = NULL;
        shapesCount = 0;
    }

    Picture(GeoShape** _shapes, int _shapesCount)
    {
        shapes = _shapes;
        shapesCount = _shapesCount;
    }

    void print() {
        if (shapes != NULL) {
            for (int i = 0; i < shapesCount; i++) {
                shapes[i]->print();
            }
        }
    }

    void draw() {
        if (shapes != NULL) {
            for (int i = 0; i < shapesCount; i++) {
                shapes[i]->draw();
            }
        }
    }
};


void drawShape(GeoShape* shape) {
    shape->draw();
}

void drawShapes(GeoShape** shapes, int n) {
    for (int i = 0; i < n; i++)
        shapes[i]->draw();
}

// ----- * ----- Starting Point ----- * ----- //
int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");

    // * ----- Picture ----- * //
    GeoShape* shapes[6];
    shapes[0] = new Rect(50, 200, 100, 400);
    shapes[1] = new Rect(200, 180, 250, 400);
    shapes[2] = new Rect(350, 200, 400, 400);
    shapes[3] = new Rect(130, 140, 320, 180);
    shapes[4] = new Circle(75, 160, 20);
    shapes[5] = new Circle(375, 160, 20);

    Picture pic(shapes, 6);
    pic.print();
    pic.draw();

    /*
    // * ----- * ----- * CAT * ----- * ----- * //
    // * ----- Rectangles ----- * //
    Rect rects[3] = {
        Rect(200, 400, 100, 200),
        Rect(400, 250, 200, 200),
        Rect(500, 400, 400, 200)
    };

    // * ----- Circles ----- * //
    Circle circles[2];

    circles[0].setCenter(150, 150);
    circles[0].setRadius(50);

    circles[1].setCenter(175, 90);
    circles[1].setRadius(20);

    // * ----- Line ----- * //
    Line lines[1] = {Line(500, 200, 600, 100)};

    // * ----- Picture ----- * //
    Picture pic(rects, circles, lines, 4, 2, 1);
    pic.print();
    pic.draw();
    */

    Sleep(10000);
    closegraph();

    /*
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");

    Rect r(400, 300, 300, 100);
    r.draw();
    r.print();

    Circle c(150, 200, 100);
    c.draw();

    Sleep(2000);

    closegraph();
    */



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
