#include "Pupil.h"

int Pupil::m_baseID = 10000; //przekonwertowac na stringa

Pupil::Pupil( string name, int age, string className ) noexcept : Person( name, age )
{
  //setName( name );
  //setAge( age );
  setClassName( className );
  clearNotes();
  m_ID = to_string( m_baseID++ );
}
Pupil::~Pupil()
{
}

void Pupil::clearNotes()
{
  memset( m_Notes, 0, sizeof( m_Notes ) );
}

double Pupil::calcAve()
{
  double sum = 0;
  int count = 0;
  for ( int i = 0; i < MAXSUBJECTS; i++ )
  {
    sum += m_Notes[i];
    if(m_Notes[i] != 0 ) count++;
  }
  if ( count != 0 ) m_Ave = sum / count;
  else m_Ave = 0;
  return m_Ave;
}
void Pupil::printPupil()
{
  cout << getID() << " " << getName() << " (" << getClassName() << ") " << getAge() << " lat ";
  cout << "Average: " << calcAve() << endl;
  cout << "\t";
  printOutfit();
}