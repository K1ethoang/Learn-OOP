#include "Person.hpp"

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
    float getMath();
    float getPhysic();
    float getChemistry();
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

void Candidate::toStream(istream &input)
{
    string s;
    Person::toStream(input);
    fflush(stdin);
    getline(input, s);
    cout << "\nNhap ten truong: ";
    getline(input, this->schoolName);
    cout << "\nNhap so CMND: ";
    input >> this->identifyCard;
    cout << "\nNhap diem toan: ";
    input >> this->math;
    cout << "\nNhap diem vat ly: ";
    input >> this->physic;
    cout << "\nNhap diem hoa hoc: ";
    input >> this->chemistry;
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