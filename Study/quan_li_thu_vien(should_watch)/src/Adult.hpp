#pragma once // tránh tình trạng đụng độ thư viện - trong mọi tình huống chỉ có 1 thư viện được tạo ra ở tất cả các file

#include <iostream>
#include <string>
#include "Reader.hpp" // gọi lại class Reader bên file Reader.h
using namespace std;

class Adult : public Reader // class Adult kế thừa lại class Reader t
{
private:
    string indentityCard;

public:
    void input();
    void output();
    int calculatingMoneyToMakeCard(); // tính tiền làm thẻ
};

void Adult::input()
{
    Reader::input();
    fflush(stdin);
    cout << "\nNhap CMND: ";
    getline(cin, indentityCard);
}

void Adult::output()
{
    Reader::output();
    cout << "So CMND: " << indentityCard << endl;
}

int Adult::calculatingMoneyToMakeCard()
{
    return numberOfMonthsInEffect * 10000;
}
