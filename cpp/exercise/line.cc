#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
	Point() = default;// default constructor
    Point(const int &x, const int &y):x_(x),y_(y) {}
    Point(const Point&);   // copy constructor statement
    int GetX() { return x_; }
    int GetY() { return y_; }
private:
    int x_ = 0, y_ = 0;
};
// copy constrctor defination
Point::Point(const Point &p):x_(p.x_),y_(p.y_)
{
     cout << "copy constructor of Point was called." << endl;
}

class Line {
public:
    Line(Point &p1, Point &p2);
    Line(const Line &l):point1_(l.point1_),point2_(l.point2_),length_(l.length_)
	{
	   cout << "copy constructor of Line was called." << endl;
   	}

    double GetLength() { return length_; }
private:
    Point point1_, point2_;
    double length_;
};

Line::Line(Point &p1, Point &p2):point1_(p1),point2_(p2) {
    double xlen = point1_.GetX() - point2_.GetY();
    double ylen = point1_.GetY() - point2_.GetY();
    length_ = sqrt(xlen * xlen + ylen * ylen);
}

int main()
{
    Point p1(1, 1), p2(4, 5);
    Line line(p1, p2);
    Line line2(line);
    cout << "The length of line is: ";
    cout << line.GetLength() << endl;
    cout << "The length of line2 is: ";
    cout << line2.GetLength() << endl;
}

