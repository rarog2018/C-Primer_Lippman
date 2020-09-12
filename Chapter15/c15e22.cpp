#include <iostream>
#include <utility>
using namespace std;

class Polygon
{
public:
    // for simplicity
    typedef pair<double, double> coordinate;
    // constructors
    Polygon() = default;
    Polygon(coordinate, coordinate, coordinate);

    // methods that do some calculations like f.e.
    // area should be a pure virtual function in Polygon class, and each class
    // should at certain level should redefine it
    virtual double area() const = 0;
    // same with perimeter, althought the classes below Quadrilateral do not
    // need to redefine it, because for every quadrilateral a perimeter is the
    // sum of its four sides
    virtual double perimeter() const = 0;

protected:
    // each polygon will have at least 3 coordinates
    coordinate a;
    coordinate b;
    coordinate c;
};
class Quadrilateral : public Polygon
{
public:
    Quadrilateral(coordinate, coordinate, coordinate, coordinate);
    double perimeter() const override;

protected:
    // additional coordinate besides the 3 inherited from Polygon
    coordinate d;
};
class Parallelogram : public Quadrilateral
{
    // can have a method that will validate if the figure is indeed a parallelogram
};
class Rhombus : public Parallelogram
{
    // check if rhombus
};
class Rectangle : public Parallelogram
{
    // check if rectangle
};
class Square : public Rhombus, public Rectangle
{
    // check if both rhombus and rectangle
};

int main(void)
{
    return 0;
}