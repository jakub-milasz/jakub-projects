#pragma once
#include "Worker.h"
class Teacher : public Worker
{
public:
  Teacher( string name = "", int age = 0, double salary = 0, int workAge = 0, string tSubject = "", string formTeacher = "" );
  virtual ~Teacher();

  void setTSubject( string tSubject );
  void setFormTeacher( string formTeacher );
  string getTSubject() const;
  string getFormTeacher() const;

  double countTotalBrutto() const;
  virtual double countSalaryNetto() final; 
  void printTeacher();

private:
  string m_TSubject;
  string m_FormTeacher;
};

inline void Teacher::setTSubject( string tSubject )
{
  m_TSubject = tSubject;
}

inline void Teacher::setFormTeacher( string formTeacher )
{
  m_FormTeacher = formTeacher;
}

inline string Teacher::getTSubject() const
{
  return m_TSubject;
}

inline string Teacher::getFormTeacher() const
{
  if ( m_FormTeacher == "" ) return string( " - " );
  return m_FormTeacher;
}
