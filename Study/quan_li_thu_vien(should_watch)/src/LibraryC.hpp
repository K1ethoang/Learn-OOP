#pragma once
#include "Child.hpp"
#include "Adult.hpp"
#include <vector>

class LibraryC
{
private:
    vector<Reader *> readers; // khái báo mảng 1 chiều chứa lớp cha - vì có virtual cho nên nó sẽ
    // đa hình sang được từng thằng con

public:
    void input();
    void output();
    long calculatingTotalMoneyToMakeCard();
};

void LibraryC::input()
{
    int choose;
    bool exit = false;

    Reader *reader; // khai báo con trỏ lớp cha
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
            reader = new Child(); // tạo 1 đối tượng độc giả trẻ em
            cout << "\n\n\t\tNHAP THONG TIN TRE EM\n";
            reader->input();
            reader->setIsChild(true); // set cho nó role độc giả trẻ em
            readers.push_back(reader);
            break;
        case 2:
            reader = new Adult();
            cout << "\n\n\t\tNHAP THONG TIN NGUOI LON\n";
            reader->input();
            reader->setIsChild(false); // ngược lại là role độc giả người lớn
            readers.push_back(reader);
            break;
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
    int childCount = 1, adultCount = 1;
    cout << "\n\n\t\t\t==== THONG TIN DOC GIA ====\n";
    for (int i = 0; i < readers.size(); i++)
    {
        if (readers[i]->getIsChild()) // nếu là trẻ em
        {
            cout << "\n\n\t\tTHONG TIN DOC GIA TRE EM " << childCount << endl;
            readers[i]->output();
            childCount++;
        }
        else // nếu là người lớn
        {
            cout << "\n\n\t\tTHONG TIN DOC GIA NGUOI LON " << adultCount << endl;
            readers[i]->output();
            adultCount++;
        }
    }
}

long LibraryC::calculatingTotalMoneyToMakeCard()
{
    long sum = 0;
    for (int i = 0; i < readers.size(); i++)
    {
        sum += readers[i]->calculatingMoneyToMakeCard();
    }

    return sum;
}