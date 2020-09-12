#include <iostream>
using namespace std;

class Polygon
{
};
class Quadrilateral : public Polygon
{
};
class Parallelogram : public Quadrilateral
{
};
class Rhombus : public Parallelogram
{
};
class Rectangle : public Parallelogram
{
};
class Square : public Rhombus, public Rectangle
{
};

int main(void)
{
    return 0;
}