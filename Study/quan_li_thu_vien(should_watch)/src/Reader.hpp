#pragma once // tránh tình trạng đụng độ thư viện - trong mọi tình huống chỉ có 1 thư viện được tạo ra ở tất cả các file

#include <iostream>
#include <string>
using namespace std;

class Reader
{
protected:
    string fullName;
    string cardMakingDate;      // dd/mm/yyyy
    int numberOfMonthsInEffect; // số tháng có hiệu lực của thẻ
    bool isChild;               // true: trẻ em, false: người lớn

public:
    virtual void input(); // phương thưc ảo
    virtual void output();
    void setIsChild(bool isChild_);
    bool getIsChild();
    virtual int calculatingMoneyToMakeCard() = 0; // tính tiền làm thẻ
    // khai báo phương thức thuần ảo - các lớp con kế thừa sẽ đi định nghĩa
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

void Reader::setIsChild(bool isChild_)
{
    this->isChild = isChild_;
}

bool Reader::getIsChild()
{
    return this->isChild;
}