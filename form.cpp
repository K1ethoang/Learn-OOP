#include <iostream>
using namespace std;

class Student
{
    // attribute (field, property)
private: // access modifier
    string fullName;
    string code;
    float averageScore;
    // Operation (method, function)
public:
    Student();  // constructor
    ~Student(); // deconstructor
    void inputInformation();
    void outputInformation();
    // GETTER and SETTER

    // get -> lấy dữ liệu
    string getCode()
    {
        return this->code;
    }

    // set -> đặt dữ liệu
    void setCode(string code)
    {
        this->code = code;
    }
};

Student::Student()
{
    fullName = "";
    code = "";
    averageScore = 0;
}

Student::~Student()
{
}

void Student::inputInformation()
{
    cout << "\nNhap ho ten: ";
    getline(cin, fullName);
    cout << "\nNhap ma sinh vien: ";
    getline(cin, code);
    cout << "\nNhap diem trung binh: ";
    cin >> averageScore;
}

void Student::outputInformation()
{
    cout << "\nHo ten: " << fullName;
    cout << "\nMa sinh vien: " << code;
    cout << "\nDiem trung binh: " << averageScore;
}

int main()
{
    Student s1; // đối tượng giá trị (Java, C# không có)

    cout << "\n\t\tNHAP THONG TIN SINH VIEN\n";
    s1.inputInformation();
    s1.setCode("123");
    cout << "\n\t\tTHONG TIN SINH VIEN\n";
    s1.outputInformation();
    return 0;
}