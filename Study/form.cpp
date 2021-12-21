#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string m_name;
    int m_age;

public:
    Person(const string &name = "", int age = 0)
        : m_name(name), m_age(age) {}

    int getAge() const
    {
        return m_age;
    }

    string getName() const
    {
        return m_name;
    }
};

// Developer publicly inheriting Person
class Developer : public Person
{
private:
    float m_numberOfHoursCoding;

public:
    Developer(const string &name = "", int age = 0, float numberOfHoursCoding = 0)
        : Person{m_name, m_age}, // call Person(const std::string&, int) to initialize these fields
          m_numberOfHoursCoding{numberOfHoursCoding}
    {
    }

    float getNumberOfHoursCoding() const
    {
        return m_numberOfHoursCoding;
    }
};

int main()
{
    Developer d{"kiet", 17, 20.4};
    cout << d.getName() << " - " << d.getAge() << " - " << d.getNumberOfHoursCoding();
    return 0;
}