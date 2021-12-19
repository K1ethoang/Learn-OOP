#pragma once // tránh tình trạng đụng độ thư viện - trong mọi tình huống chỉ có 1 thư viện được tạo ra ở tất cả các file

#include <iostream>
#include <string>
#include "Reader.hpp" // gọi lại class Reader bên file Reader.h
using namespace std;

class Child : public Reader // class Child kế thừa lại class Reader t
{
private:
    string fullNameOfRepresentee; // họ tên của người đại diện

public:
    void input();
    void output();
    int calculatingMoneyToMakeCard(); // tính tiền làm thẻ
};

void Child::input()
{
    Reader::input(); // gọi lại method input()
    fflush(stdin);
    cout << "\nNhap ho ten nguoi dai dien: ";
    getline(cin, fullNameOfRepresentee);
}

void Child::output()
{
    Reader::output();
    cout << "Ho ten nguoi dai dien: " << fullNameOfRepresentee << endl;
}

int Child::calculatingMoneyToMakeCard()
{
    return numberOfMonthsInEffect * 5000;
}
