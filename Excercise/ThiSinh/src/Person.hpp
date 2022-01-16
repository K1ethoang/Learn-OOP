#pragma once

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string fullname;
    string homeTown;
    int age;

public:
    Person();
    string getFullname();
    string getHomeTown();
    int getAge();
    virtual void toStream(istream &input); // vừa nhập từ bàn phìm - vừa từ file
    friend istream &operator>>(istream &input, Person &person);
};

Person::Person()
{
    this->fullname = "";
    this->homeTown = "";
    this->age = 0;
}

string Person::getFullname()
{
    return this->fullname;
}

string Person::getHomeTown()
{
    return this->homeTown;
}

int Person::getAge()
{
    return this->age;
}

bool checkAge(const int &age) // hàm ngoài
{
    if (age > 0)
    {
        return true;
    }
    return false;
}

void Person::toStream(istream &input)
{
    fflush(stdin);
    cout << "\nNhap ho va ten: ";
    getline(input, this->fullname);
    cout << "\nNhap que quan: ";
    getline(input, this->homeTown);
    cout << "\nNhap tuoi: ";
    input >> this->age;
    do
    {
        if (!checkAge(this->age))
        {
            cout << "\n\t(!) Tuoi khong hop le, nhap lai: ";
            cin >> this->age;
        }
    } while (!checkAge(this->age));
}

istream &operator>>(istream &input, Person &person)
{
    person.toStream(input);
    return input;
}
