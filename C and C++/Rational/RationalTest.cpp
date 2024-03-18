#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
  Rational test( 1, 3 );
  Rational test2;
  cout << "Podaj ulamek w formacie licznik/mianownik: ";
  cin >> test2;
  cout << "test+test2=" << (test + test2).Value() << endl;
  cout << "test-test2=" << (test - test2).Value() << endl;
  cout << "test*test2=" << (test * test2).Value() << endl;
  cout << "test/test2=" << (test / test2).Value() << endl;
}
