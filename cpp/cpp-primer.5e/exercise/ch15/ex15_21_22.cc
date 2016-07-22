/*
 *Exercise 15.21:
 *Choose one of the following general abstractions containing a family of types (or choose one of your own).
 *Organize the types into an inheritance hierarchy:
 *(a) Graphical file formats (such as gif, tiff, jpeg, bmp)
 *(b) Geometric primitives (such as box, circle, sphere, cone)
 *(c) C++ language types (such as class, function, member function)
 */

/*
 *Exercise 15.22:
 *For the class you chose in the previous exercise, identify
 *some of the likely virtual functions as well as public and protected members.
 */

#include <string>

class GeometricShape {
public:
    GeometricShape() = default;
    GeometricShape(const std::string &n) :
        name(n) {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~GeometricShape() = default;

private:
    std::string name;
};

class Rectangle : public GeometricShape {
public:
    Rectangle() = default;
    Rectangle(const std::string &n, const double &w, const double &h) :
        GeometricShape(n), width(w), height(h) {}

    double area() const override {
        return width * height;
    }
    double perimeter() const override {
         return 2 * (width + height);
    }

    virtual ~Rectangle() = default;

protected:
    double width;
    double height;
};


int main()
{
     return 0;
}
