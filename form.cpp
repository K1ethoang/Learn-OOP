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
    Student sv; // đối tượng giá trị (Java, C# không có) -> chỉ có ở C++
    sv.inputInformation();
    sv.outputInformation();

    Student *sv1 = new Student; // đối tượng con trỏ (Java, C# chỉ có thằng này)
    cout << sv1->getCode();

    delete sv1;
    return 0;
}