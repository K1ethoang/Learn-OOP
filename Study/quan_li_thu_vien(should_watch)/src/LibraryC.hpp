#include "Child.hpp"
#include "Adult.hpp"
#include <iostream>
#include <vector>
using namespace std;

class LibraryC
{
private:
    vector<Child> Children;
    vector<Adult> Adults;

public:
    void input();
    void output();
    long calculatingTotalMoneyToMakeCard();
};

void LibraryC::input()
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "===================== QUAN LI THU VIEN =====================" << endl;
        cout << "|  1. Doc gia tre em" << endl;
        cout << "|  2. Doc gia nguoi lon" << endl;
        cout << "|  0. Thoat" << endl;
        cout << "===================== **************** =====================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
        {
            Child child;
            cout << "\n\n\t\tNHAP THONG TIN TRE EM\n";
            child.input();
            Children.push_back(child);
            break;
        }
        case 2:
        {
            Adult adult;
            cout << "\n\n\t\tNHAP THONG TIN NGUOI LON\n";
            adult.input();
            Adults.push_back(adult);
            break;
        }
        case 0:
            exit = true;
            break;
        default:
            cout << "\n\n\t\tKhong hop le\n";
            system("pause");
            break;
        }

    } while (!exit);
}

void LibraryC::output()
{
    cout << "\n\n\t\t\t==== THONG TIN DOC GIA TRE EM ====\n";
    for (int i = 0; i < Children.size(); i++)
    {
        cout << "\n\n\t\tTHONG TIN TRE EM " << i + 1 << endl;
        Children[i].output();
    }

    cout << "\n\n\t\t\t==== THONG TIN DOC GIA NGUOI LON ====\n";
    for (int i = 0; i < Adults.size(); i++)
    {
        cout << "\n\n\t\tTHONG TIN NGUOI LON " << i + 1 << endl;
        Adults[i].output();
    }
}

long LibraryC::calculatingTotalMoneyToMakeCard()
{
    long sum = 0;
    for (int i = 0; i < Children.size(); i++)
    {
        sum += Children[i].calculatingMoneyToMakeCard();
    }

    for (int i = 0; i < Adults.size(); i++)
    {
        sum += Adults[i].calculatingMoneyToMakeCard();
    }

    return sum;
}