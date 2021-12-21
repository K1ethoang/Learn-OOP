#include <bits/stdc++.h>
using namespace std;

// ! Function Template
// cùng kiểu dữ liệu
template <class T>
void swap_(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 2 kiểu dữ liệu khác nhau
template <class T, class X>
void _swap(T &a, X &b)
{
    T temp = a;
    a = (T)b;
    b = (X)temp;
}

// ! Class Template
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
    Point<double> point;
    cin >> point;
    cout << point;
    cout << "\n\n\t\tswap" << endl;

    swap_<double>(point.x, point.y);
    cout << point;

    return 0;
}