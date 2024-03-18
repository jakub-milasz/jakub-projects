#include "Rational.h"

Rational::Rational( int Num, int Denum )
{
  setRational( Num, Denum );
}
Rational::Rational( const Rational& r )
{
  *this = r;
}

Rational& Rational::operator = ( const Rational& r )
{
  m_Numerator = r.getNumerat();
  m_Denominator = r.getDenominat();
  return *this;
}
const Rational operator + ( const Rational& rLeft, const Rational& rRight )
{
  return Rational( (rLeft.getNumerat() * rRight.getDenominat() + rRight.getNumerat() * rLeft.getDenominat()), rLeft.getDenominat() * rRight.getDenominat() );
}
const Rational operator - ( const Rational& rLeft, const Rational& rRight )
{
  return Rational( (rLeft.getNumerat() * rRight.getDenominat() - rRight.getNumerat() * rLeft.getDenominat()), rLeft.getDenominat() * rRight.getDenominat() );
}
const Rational operator * ( const Rational& rLeft, const Rational& rRight )
{
  return Rational( (rLeft.getNumerat() * rRight.getNumerat()), rLeft.getDenominat() * rRight.getDenominat() );
}
const Rational operator / ( const Rational& rLeft, const Rational& rRight )
{
  return Rational( (rLeft.getNumerat() * rRight.getDenominat()), rLeft.getDenominat() * rRight.getNumerat() );
}

Rational& Rational::operator += ( const Rational& r )
{
  *this = *this + r;
  return *this;
}
Rational& Rational::operator -= ( const Rational& r )
{
  *this = *this - r;
  return *this;
}
Rational& Rational::operator *= ( const Rational& r )
{
  *this = *this * r;
  return *this;
}
Rational& Rational::operator /= ( const Rational& r )
{
  *this = *this / r;
  return *this;
}

double Rational::Value() const
{
  return m_Numerator / ( double )m_Denominator;
}
Rational::operator double() const
{
  return Value();
}

istream& operator >> ( istream& in, Rational& r )
{
  int num = 0;
  int denum = 0;
  char c;
  in >> num >> c >> denum;
  r.setRational( num, denum );
  return in;
}
ostream& operator << ( ostream& out, const Rational& r )
{
  Rational x = r;
  x.NWD();
  cout << x.m_Numerator << "/" << x.m_Denominator;
  return out;
}