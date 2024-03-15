#include "Pupil.h"
#include "SchoolBoy.h"
#include "SchoolGirl.h"
#include "Teacher.h"
#include "Admin.h"
#include "Worker.h"

#define PUPIL_NO 7
#define TEACHER_NO 6
#define ADMIN_NO 3

void sortPupil( Pupil** tab, int PupilNo );
void printPupils( Pupil** tab, int PupilNo );
void printTeachers( Teacher** tab, int PupilNo );
void printAdmins( Admin** tab, int PupilNo );

int main()
{
  Teacher* teachers[TEACHER_NO] = {NULL};
  Admin* admins[ADMIN_NO] = {NULL};
  Pupil* pupils[PUPIL_NO] = {NULL};


  teachers[0] = new Teacher( "Piotr Kamysz", 45, 5000, 15, "matematyka", "3C" );
  teachers[1] = new Teacher( "Jacek Bak", 35, 4300, 4, "fizyka", "1B" );
  teachers[2] = new Teacher( "Anna Nowak", 40, 4500, 12, "chemia");
  teachers[3] = new Teacher( "Krzysztof Wokulski", 38, 4000, 10, "informatyka", "4TA" );
  teachers[4] = new Teacher( "Janusz Ziobro", 55, 4100, 24, "polski");
  teachers[5] = new Teacher( "Marek Stach", 50, 4000, 19, "angielski");

  admins[0] = new Admin("Krzysztof Stanowski", 38, 5500, 10, "specjalista");
  admins[1] = new Admin("Janusz Ziobro", 57, 12000, 30, "starszy specjalista");
  admins[2] = new Admin("Marek Dworski", 52, 4000, 25, "mlodszy specjalista");

  pupils[0] = new SchoolBoy("Jacek Sasin", 20, "4TA");
  pupils[1] = new SchoolGirl("Anna Grot", 17, "1B");
  pupils[2] = new SchoolGirl("Maria Nowak", 20, "4TD");
  pupils[3] = new SchoolBoy("Jan Kowalczyk", 18, "2C");
  pupils[4] = new SchoolGirl("Katarzyna Kowalska", 19, "3D" );
  pupils[5] = new SchoolBoy("Robert Kwerenda", 19, "3C");
  pupils[6] = new SchoolBoy( "Tomasz Zaborakowski", 19, "3C" );


  pupils[0]->setNote( NIEMIECKI, 4 );
  pupils[0]->setNote( MATEMATYKA, 5 );
  pupils[0]->setNote( FIZYKA, 3 );
  pupils[0]->setNote( CHEMIA, 2 );
  pupils[0]->setNote( POLSKI, 3.5 );
  pupils[0]->setNote( INFORMATYKA, 4.5 );
  pupils[0]->setNote( ANGIELSKI, 3.5 );

  pupils[1]->setNote( NIEMIECKI, 5 );
  pupils[1]->setNote( MATEMATYKA, 2.5 );
  pupils[1]->setNote( FIZYKA, 3 );
  pupils[1]->setNote( CHEMIA, 4.5 );
  pupils[1]->setNote( INFORMATYKA, 4 );
  pupils[1]->setNote( ANGIELSKI, 3.5 );

  pupils[2]->setNote(FIZYKA, 5);
  pupils[2]->setNote( CHEMIA, 2.5 );
  pupils[2]->setNote( INFORMATYKA, 4 );
  pupils[2]->setNote( ANGIELSKI, 3.5 );
  pupils[2]->setNote(POLSKI, 4.5);

  pupils[3]->setNote( NIEMIECKI, 4 );
  pupils[3]->setNote( ANGIELSKI, 3.5 );
  pupils[3]->setNote( POLSKI, 4.5 );
  pupils[3]->setNote( MATEMATYKA, 5 );

  pupils[4]->setNote( NIEMIECKI, 3.5 );
  pupils[4]->setNote( MATEMATYKA, 4.5 );
  pupils[4]->setNote( FIZYKA, 4.5 );
  pupils[4]->setNote( POLSKI, 5 );
  pupils[4]->setNote( INFORMATYKA, 5 );

  pupils[5]->setNote( NIEMIECKI, 3.5 );
  pupils[5]->setNote( FIZYKA, 3 );
  pupils[5]->setNote( CHEMIA, 3.5 );
  pupils[5]->setNote( POLSKI, 4 );
  pupils[5]->setNote( ANGIELSKI, 5 );

  pupils[6]->setNote( NIEMIECKI, 3 );
  pupils[6]->setNote( MATEMATYKA, 2 );
  pupils[6]->setNote( FIZYKA, 3 );
  pupils[6]->setNote( CHEMIA, 2 );
  pupils[6]->setNote( POLSKI, 3 );
  pupils[6]->setNote( INFORMATYKA, 3 );
  pupils[6]->setNote( ANGIELSKI, 3.5 );

  printPupils( pupils, PUPIL_NO );
  sortPupil( pupils, PUPIL_NO );
  cout << endl << "Posortowani uczniowie:" << endl;
  printPupils( pupils, PUPIL_NO );

  cout << endl;
  printAdmins( admins, ADMIN_NO );

  cout << endl;
  printTeachers( teachers, TEACHER_NO );
}

void printPupils( Pupil** tab, int PupilNo )
{
  for ( int i = 0; i < PupilNo; i++ )
  {
    tab[i]->printPupil();
  }
}

void printTeachers( Teacher** tab, int TeacherNo )
{
  for ( int i = 0; i < TeacherNo; i++ )
  {
    tab[i]->printTeacher();
  }
}

void printAdmins( Admin** tab, int AdminNo )
{
  for ( int i = 0; i < AdminNo; i++ )
  {
    tab[i]->printAdmin();
  }
}

void sortPupil( Pupil** tab, int PupilNo )
{
  for ( int i = 1; i < PupilNo; i++ )
  {
    int j = i - 1;
    Pupil* v = tab[i];
    while( j >= 0 && v->getName() > tab[j]->getName() )
    {
      tab[j + 1] = tab[j--];
    } 
    tab[j + 1] = v;
  }
}
