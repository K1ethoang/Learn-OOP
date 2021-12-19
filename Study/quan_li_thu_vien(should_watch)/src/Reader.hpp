// #pragma once // tránh tình trạng đụng độ thư viện - trong mọi tình huống chỉ có 1 thư viện được tạo ra ở tất cả các file

#include <iostream>
#include <string>
using namespace std;

class Reader
{
protected:
    string fullName;
    string cardMakingDate;      // dd/mm/yyyy
    int numberOfMonthsInEffect; // số tháng có hiệu lực của thẻ
public:
    void input();
    void output();
};

void Reader::input()
{
    fflush(stdin);
    cout << "\nNhap ho ten doc gia: ";
    getline(cin, fullName);

    cout << "\nNhap ngay lam the (dd/mm/yyyy): ";
    getline(cin, cardMakingDate);

    cout << "\nNhap so thang hieu luc cua the: ";
    cin >> numberOfMonthsInEffect;
}

void Reader::output()
{
    cout << "\nHo ten doc gia: " << fullName << endl;
    cout << "Ngay lam the (dd/mm/yyyy): " << cardMakingDate << endl;
    cout << "So thang hieu luc cua the: " << numberOfMonthsInEffect << endl;
}
