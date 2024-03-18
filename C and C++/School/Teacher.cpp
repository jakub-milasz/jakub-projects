#include "Teacher.h"

Teacher::Teacher( string name, int age, double salary, int workAge, string tSubject, string formTeacher )
{
  setWorker( name, age, salary, workAge );
  setTSubject( tSubject );
  setFormTeacher( formTeacher );
}

Teacher::~Teacher()
{
}

double Teacher::countTotalBrutto() const
{
  double salary = getSalary();
  double percent = 1 + ( double )getWorkAge() / 100;
  int bonus = 400;
  if ( getWorkAge() > 20 ) percent = 1.2;
  else if ( getWorkAge() < 5 ) percent = 1;
  salary *= percent;
  if ( m_FormTeacher != "" ) salary += bonus;
  return salary;
}

double Teacher::countSalaryNetto()
{
  double salary = countTotalBrutto();
  double kosztUzysku = 111.25;
  double kwotaWolna = 556.02;
  double taxPercent = 0.18;
  
  double tax = (0.8 * salary - kosztUzysku / 2 + 0.2 * salary - kosztUzysku) * taxPercent - kwotaWolna;
  return salary-tax;
}

void Teacher::printTeacher()
{
  cout << "Nauczyciel " << getName() << " " << getAge() << " lat" << " pracuje w zawodzie od " << getWorkAge() << " lat," << endl;
  cout << "Wychowawca: " << getFormTeacher() << ", przedmiot: " << getTSubject() << ", pensja brutto: " << countTotalBrutto() << ", pensja netto: " << countSalaryNetto() << endl;
}