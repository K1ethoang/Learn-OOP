#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <iomanip>

// vẫn còn lỗi trong việc đọc file

class Employee
{
private:
    string code;
    string name;
    int day, month, year;
    string address;
    float coefficientsSalary; // hệ số lươn
    float baseSalary;         // lương cơ bản

public:
    virtual void importEmployees(ifstream &);
    virtual void output();
};

class Programmer : public Employee
{
private:
    float overtimeMoney; // tiền làm ngoài giờ

public:
    void importEmployees(ifstream &);
    void output();
};

class Designer : public Employee
{
private:
    float bonusMoney; // tiền thưởng

public:
    void importEmployees(ifstream &);
    void output();
};

void menu(Employee *employee[], int &n);

int main()
{
    int n = 0;
    Employee *employees[100]; // khai báo mảng 1 chiều các con trỏ lưu trữ 2 loại nhân viên
    menu(employees, n);
    return 0;
}

void menu(Employee *employees[], int &n)
{

    int choose;
    bool exit = false;

    ifstream fileIn;
    fileIn.open("../file/nhanVien.txt", ios_base::in);
    do
    {
        system("cls");
        cout << "1. Doc du lieu tu file \"nhanVien.txt\"";
        cout << "\n2. Xuat danh sach";
        cout << "\n0. thoat";

        cout << "\n\nNhap lua chon: ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            fileIn >> n;
            cout << fileIn.tellg() << endl;
            Employee *employee = NULL;
            for (int i = 0; i < n; i++)
            {
                char classify; // lấy kí tự đầu để phân loại nhân viên
                fileIn >> classify;
                cout << fileIn.tellg() << endl;
                fileIn.seekg(-1, ios::cur); // đưa con trỏ chỉ vị về đầu dòng
                if (classify == 'P')
                {
                    employee = new Programmer();
                    employee->importEmployees(fileIn);
                }
                else if (classify == 'D')
                {
                    employee = new Designer();
                    employee->importEmployees(fileIn);
                }
                employees[i] = employee;
            }
            system("pause");
            break;
        }
        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\t\tTHONG TIN NHAN VIEN THU " << i + 1 << endl;
                employees[i]->output();
            }
            system("pause");
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "\n\t\tKhong hop le" << endl;
            system("pause");
            break;
        }
    } while (!exit);
    fileIn.close();
}

// đọc file trong lớp cha
void Employee::importEmployees(ifstream &fileIn)
{
    getline(fileIn, code, ',');

    fileIn.seekg(1, ios::cur); // dịch con trỏ chỉ vị của vị trí hiện tại sang bên phải 1 byte
    getline(fileIn, name, ',');

    fileIn >> day;
    fileIn.seekg(1, ios::cur);
    fileIn >> month;
    fileIn.seekg(1, ios::cur);
    fileIn >> year;

    fileIn.seekg(2, ios::cur);
    getline(fileIn, address, ',');

    fileIn >> coefficientsSalary;

    fileIn.seekg(1, ios::cur);
    fileIn >> baseSalary;
}

void Employee::output()
{
    cout << "\nMa nhan vien: " << code << endl;
    cout << "Ho ten nhan vien: " << name << endl;
    cout << "Ngay sinh: " << day << "/" << month << "/" << year << endl;
    cout << "Dia chi: " << address << endl;
    cout << "He so luong: " << coefficientsSalary << endl;
    cout << "Luong co ban: " << (size_t)baseSalary << endl;
}

// ! Class Programmer
void Programmer::importEmployees(ifstream &fileIn)
{
    Employee::importEmployees(fileIn);
    fileIn.seekg(1, ios::cur);
    fileIn >> overtimeMoney;
}

void Programmer::output()
{
    Employee::output();
    cout << "Tien lam them gio: " << overtimeMoney << endl;
}

// ! Class Designer
void Designer::importEmployees(ifstream &fileIn)
{
    Employee::importEmployees(fileIn);
    fileIn.seekg(1, ios::cur);
    fileIn >> bonusMoney;
}

void Designer::output()
{
    Employee::output();
    cout << "Tien thuong: " << bonusMoney << endl;
}