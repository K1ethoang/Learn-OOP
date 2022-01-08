#include <iostream>
using namespace std;

template <class Type>
class Point
{
private:
    Type x;
    Type y;

public:
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(const Type &x_, const Type &y_)
        : x(x_), y(y_) {}

    friend istream &operator>>(istream &is, Point &p)
    {
        cout << "\nNhap toa do x: ";
        is >> p.x;
        cout << "\nNhap toa do y: ";
        is >> p.y;
        return is;
    }

    friend ostream &operator<<(ostream &os, Point p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main()
{
    Point<int> p1(2, 3);
    Point<float> p2(1.3, 5.4);
    cout << "int: " << p1 << endl;
    cout << "float: " << p2 << endl;
    return 0;
}