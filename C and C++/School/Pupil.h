#pragma once
#include "Person.h"

//typedef enum {POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI} Subjects;
enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI }; //dla C++
#define MAXSUBJECTS NIEMIECKI+1

class Pupil : public Person
{
  public:
    Pupil(string name = "", int age = 0, string className="") noexcept;
    virtual ~Pupil();

    void setClassName( string newClassName );
    string getClassName() const;
    string getID() const;

    void clearNotes();
    double calcAve();
    double getAve() const;
    void setNote( Subjects subject, double note );
    void printPupil();
    virtual void printOutfit() = 0; //mozna zmienic w klasie dziedziczacej, nie mozna tworzyc obiektow klasy abstrakcyjnej

  protected: //prywatne z pkt widzenia innych klas, publiczne z pkt widzenia klas dziedziczacych
    string m_ID;

  private:
    string m_className;
    double m_Ave;
    double m_Notes[MAXSUBJECTS];
    static int m_baseID;
};

inline void Pupil::setClassName( string newClassName )
{
  m_className = newClassName;
}
inline string Pupil::getClassName() const
{
  return m_className;
}
inline string Pupil::getID() const
{
  return m_ID;
}
inline void Pupil::setNote( Subjects subject, double note )
{
  if( note >= 2 && note <= 5 && subject >= POLSKI  && subject <= NIEMIECKI )
  m_Notes[subject] = note;
  else
  {
    cout << "Bledna ocena lub przedmiot - student o ID: " << getID() << endl;
    return;
  }
}
inline double Pupil::getAve() const
{
  return m_Ave;
}