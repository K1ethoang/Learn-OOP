#include <iostream>
using namespace std;

class A
{
public:
    virtual void alert() // phương thức ảo
    {
        cout << "Class A day" << endl;
    }
    virtual void calculate() = 0; // phương thức thuần ảo
};

class B : public A
{
public:
    void alert()
    {
        cout << "Class B day" << endl;
    }
    void calculate()
    {
        cout << "Have done" << endl;
    }
};

class C : public A
{
public:
    void alert()
    {
        cout << "Class C day" << endl;
    }
};

int main()
{
    A *a = new B();
    a->calculate();
    a->alert();

    delete a;
    return 0;
}