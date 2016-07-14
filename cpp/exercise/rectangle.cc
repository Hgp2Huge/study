#include <iostream>

class Point {
public:
    Point(int x, int y):x_(x), y_(y) {}
    Point(const Point &p):x_(p.x_), y_(p.y_) {}
    virtual ~Point() {}

    int GetX() { return x_; }
    int GetY() { return y_; }
    void Print();
private:
    int x_;
    int y_;
};

void Point::Print()
{
    std::cout << "(" << x_ << ", " << y_ << ")";
}

class Rectangle {
public:
    Rectangle(int x, int y, unsigned int width, unsigned int height);
    Rectangle(Point &p, unsigned int width, unsigned int height);
    ~Rectangle() {}

    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }
    Point GetLeftTop() const;
    Point GetLeftBottom() const;
    Point GetRightTop() const;
    Point GetRightBottom() const;

    int GetArea() const;

private:
    int x_; // LeftTop x
    int y_; // LeftTop y
    unsigned int width_;
    unsigned int height_;
};

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height)
    :x_(x), y_(y), width_(width), height_(height)
{
}

Rectangle::Rectangle(Point &p, unsigned int width, unsigned int height)
{
    x_ = p.GetX();
    y_ =p.GetY();
    width_ = width;
    height_ = height;
}

Point Rectangle::GetLeftTop() const
{
    return Point(x_, y_);
}
Point Rectangle::GetLeftBottom() const
{
    return Point(x_, y_-height_);
}
Point Rectangle::GetRightTop() const
{
    return Point(x_+width_, y_);
}
Point Rectangle::GetRightBottom() const
{
    return Point(x_+width_, y_-height_);
}

int Rectangle::GetArea() const
{
    return width_*height_;
}



int main()
{
    Rectangle RectangleFromXY(-5, 5, 10, 10);
    Point MyPoint(-10,10);
    Rectangle RectangleFromPoint(MyPoint, 20, 20);

    std::cout << "The four Points of RectangleFromXY is: " << std::endl;
    RectangleFromXY.GetLeftTop().Print();
    RectangleFromXY.GetLeftBottom().Print();
    RectangleFromXY.GetRightTop().Print();
    RectangleFromXY.GetRightBottom().Print();
    std::cout << std::endl;
    std::cout << "The area of RectangleFromXY is: ";
    std::cout << RectangleFromXY.GetArea() << std::endl;


    std::cout << "The four Points of RectangleFromPoint is: " << std::endl;
    RectangleFromPoint.GetLeftTop().Print();
    RectangleFromPoint.GetLeftBottom().Print();
    RectangleFromPoint.GetRightTop().Print();
    RectangleFromPoint.GetRightBottom().Print();
    std::cout << std::endl;
    std::cout << "The area of RectangleFromPoint is: ";
    std::cout << RectangleFromPoint.GetArea() << std::endl;

    return 0;
}
