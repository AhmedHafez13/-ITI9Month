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
        //ul.setX(x1);
        //ul.setY(y1);
        //lr.setX(x2);
        //lr.setY(y2);

        // No need to those 2 lines below when using (Constructor Chain)
        //ul.setXY(x1, y1);
        //lr.setXY(x2, y2);
    }

    Rect(Point _ul, Point _lr): ul(_ul), lr(_lr) // Copy Constructor *2
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
        circle(center.getX(), center.getY(), radius);
    }
};

// ----- * ----- Line Class ----- * ----- //
class Line {
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
    Rect* rectangles;       // Pointer to an array of Rects
    int rectanglesCount;    // Rectangles Count
    Circle* circles;        // Pointer to an array of Circles
    int circlesCount;       // Circles Count
    Line* lines;            // Pointer to an array of lines
    int linesCount;         // Lines Count

public:
    Picture() {
        rectangles = NULL;
        rectanglesCount = 0;

        circles = NULL;
        circlesCount = 0;
    }

    Picture(Rect* _rectangles, Circle* _circles, Line* _lines,
            int _rectanglesCount, int _circlesCount, int _linesCount)
    {
        rectangles = _rectangles;
        rectanglesCount = _rectanglesCount;

        circles = _circles;
        circlesCount = _circlesCount;

        lines = _lines;
        linesCount = _linesCount;
    }

    void print() {
        for (int i = 0; i < rectanglesCount; i++) {
            rectangles[i].print();
        }
        for (int i = 0; i < circlesCount; i++) {
            circles[i].print();
        }
        for (int i = 0; i < linesCount; i++) {
            lines[i].print();
        }
    }

    void draw() {
        for (int i = 0; i < rectanglesCount; i++) {
            rectangles[i].draw();
        }
        for (int i = 0; i < circlesCount; i++) {
            circles[i].draw();
        }
        for (int i = 0; i < linesCount; i++) {
            lines[i].draw();
        }
    }
};


// ----- * ----- Starting Point ----- * ----- //
int main() {
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");


    // * ----- Rectangles ----- * //
    Rect rects[2] = {
        Rect(295, 120, 305, 140),
        Rect(260, 240, 340, 260)
    };

    // * ----- Circles ----- * //
    Circle circles[1] = {
        Circle(300, 190, 50)
    };

    // * ----- Lines ----- * //
    Line lines[4] = {
        Line(250, 50, 350, 50),
        Line(350, 50, 380, 120),
        Line(380, 120, 220, 120),
        Line(220, 120, 250, 50)
    };

    // * ----- Picture ----- * //
    Picture pic(rects, circles, lines, 2, 1, 4);
    pic.print();
    pic.draw();


    Sleep(10000);
    closegraph();

    return 0;
}
