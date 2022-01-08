#include <iostream>
using namespace std;

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

int main()
{
    /* Run code first */
    float x = 5.3, y = 3.5;
    int z = 6;
    cout << "x = 5.3 (float), y = 3.5 (float), z = 6 (int)" << endl;
    cout << "\n\tswap";

    swap_(x, y);
    cout << "\nCung kieu du lieu: "
         << "x = " << x << " (float) "
         << "y = " << y << " (float)" << endl;
    swap_(x, y); // chuyển về lại như ban đầu

    _swap(x, z);
    cout << "\n2 kieu du lieu khac nhau: "
         << "x = " << x << " (float) "
         << "z = " << z << " (int)" << endl;
    system("pause");
    return 0;
}