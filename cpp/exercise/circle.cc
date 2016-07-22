#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.14

class Circle
{
public:
    Circle(const double &r): radius(r) {}
    ~Circle() {}

    double GetRadius() { return radius; }
    double GetArea() const;

private:
    double radius;
};

double Circle::GetArea() const
{
    return PI * radius * radius;
}


int main()
{
    double r;
    Circle myCircle(2);

    cout << "Area of myCircle(2) is: "<< fixed << setprecision(2)
        << myCircle.GetArea() << endl;

    cout << "Radius of your circle: ";
    cin >> r;
    Circle yourCircle(r);

    cout << "Area of your circle is: "<< fixed << setprecision(2)
        << yourCircle.GetArea() << endl;

    return 0;
}

