#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
  public:
    Person( string name = "", int age = 0 ) noexcept;
    virtual ~Person();
    Person& operator = ( const Person& z ) = default;


    void setName(string newName);
    void setAge(int newAge);
    void setPerson(string newName, int newAge);
    string getName() const;
    int getAge() const;

  private:
    string m_Name;
    int m_Age;
};

inline void Person::setName( string newName )
{
  m_Name = newName;
}
inline void Person::setAge( int newAge )
{
  m_Age = newAge;

}
inline void Person::setPerson( string newName, int newAge )
{
  setName( newName );
  setAge( newAge );
}
inline string Person::getName() const
{
  return m_Name;
}
inline int Person::getAge() const
{
  return m_Age;
}
