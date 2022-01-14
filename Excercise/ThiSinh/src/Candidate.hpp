#include "Person.hpp"
#include "Candidates.hpp"

class Candidate : public Person
{
private:
    string schoolName;
    string identifyCard; // CMND
    float math, physic, chemistry;

public:
    Candidate();
    string getSchoolName();
    string getIdentifyCard();
    void setIdentifyCard(const string &ID);
    float getMath();
    float getPhysic();
    float getChemistry();
    bool validId(const string &ID);
    void toStream(istream &input);
    friend ostream &operator<<(ostream &output, Candidate Candidate);
    float sumOfMark();
};

Candidate::Candidate()
{
    this->schoolName = "";
    this->identifyCard = "";
    this->math = 0.0;
    this->physic = 0.0;
    this->chemistry = 0.0;
}

string Candidate::getSchoolName()
{
    return schoolName;
}

string Candidate::getIdentifyCard()
{
    return identifyCard;
}

void Candidate::setIdentifyCard(const string &ID)
{
    this->identifyCard = ID;
}

float Candidate::getMath()
{
    return math;
}

float Candidate::getPhysic()
{
    return physic;
}

float Candidate::getChemistry()
{
    return chemistry;
}

bool Candidate::validId(const string &ID)
{
    if (ID.length() == 9)
    {
        return true;
    }
    return false;
}

bool checkMark(const float &mark) // hàm ngoài
{
    if (mark > 0 && mark <= 10)
    {
        return true;
    }
    return false;
}

void Candidate::toStream(istream &input)
{
    string s;
    Person::toStream(input);
    getline(input, s);
    cout << "\nNhap ten truong: ";
    getline(input, this->schoolName);
    cout << "\nNhap so CMND: ";
    input >> this->identifyCard;
    do
    {
        if (!validId(this->identifyCard))
        {
            cout << "\n\t(!) CMND khong hop le, Nhap lai: ";
            input >> this->identifyCard;
        }
    } while (!validId(this->identifyCard));
    cout << "\nNhap diem toan: ";
    input >> this->math;
    do
    {
        if (!checkMark(this->math))
        {
            cout << "\n\t(!) Diem khong hop le, Nhap lai: ";
            cin >> this->math;
        }
    } while (!checkMark(this->math));
    cout << "\nNhap diem vat ly: ";
    input >> this->physic;
    do
    {
        if (!checkMark(this->physic))
        {
            cout << "\n\t(!) Diem khong hop le, Nhap lai: ";
            cin >> this->physic;
        }
    } while (!checkMark(this->physic));
    cout << "\nNhap diem hoa hoc: ";
    input >> this->chemistry;
    do
    {
        if (!checkMark(this->chemistry))
        {
            cout << "\n\t(!) Diem khong hop le, Nhap lai: ";
            cin >> this->chemistry;
        }
    } while (!checkMark(this->chemistry));
}

ostream &operator<<(ostream &output, Candidate Candidate)
{
    output << "\nHo va ten: " << Candidate.getFullname();
    output << "\nQue quan: " << Candidate.getHomeTown();
    output << "\nTuoi: " << Candidate.getAge();
    output << "\nTen truong: " << Candidate.schoolName;
    output << "\nSo CMND: " << Candidate.identifyCard;
    output << "\nToan: " << Candidate.math << " / Vat ly: " << Candidate.physic << " / Hoa Hoc: " << Candidate.chemistry;
    return output;
}

float Candidate::sumOfMark()
{
    return math + physic + chemistry;
}
