#include "Admin.h"

Admin::Admin( string name, int age, double salary, int workAge, string position )
{
  setWorker( name, age, salary, workAge );
  setPosition( position );
}

Admin::~Admin()
{
}

double Admin::countSalaryNetto()
{
  double kosztUzysku = 111.25;
  double kwotaWolna = 556.02;
  double taxPercent = 0.18;
  double tax = (getSalary() - kosztUzysku) * taxPercent - kwotaWolna;
  if( tax < 0 ) tax = 0;
  return getSalary()-tax;
}

void Admin::printAdmin()
{
  cout << "Pracownik administracyjny " << getName() << " " << getAge() << " lat " << "pracuje od " << getWorkAge() << " lat" << endl;
  cout << "Obecnie na stanowisku " << getPosition() << ", pensja brutto: " << getSalary() << ", pensja netto: " << countSalaryNetto() << endl;
}