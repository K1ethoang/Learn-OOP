#include <iostream>
#include <list>
using namespace std;

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
};

void Pizza::prepare()
{
    cout << "\nPreparing " << name;
    cout << "\nTossing dough...";
    cout << "\nAdding sauce...";
    cout << "\nAdding toppings:";
}

class CheesePizza
{
};

int main()
{

    return 0;
}
