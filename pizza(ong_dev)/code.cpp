#include <iostream>
#include <list>
using namespace std;

class PizzaStore;
class Pizza;
class CheesePizza;

int main()
{

    return 0;
}

class PizzaStore
{
};

class Pizza
{
protected:
    string name;
    string dough;
    string sauce;
    list<string> toppings;

public:
    void prepare()
    {
        cout << "\nPreparing " << name;
        cout << "\nTossing dough...";
        cout << "\nAdding sauce...";
        cout << "\nAdding toppings:";
    }
};
