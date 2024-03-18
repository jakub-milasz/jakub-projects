#pragma once
#include <iostream>
#include <cmath>
using namespace std;


class Rational
{
public:
  Rational( int Num=0, int Denum=1 );
  Rational( const Rational& r );

  void setNumerator( int Num );
  void setDenominator( int Denum );
  void setRational( int Num, int Denum );

  int getNumerat() const;
  int getDenominat() const;

public:
  Rational& operator = ( const Rational& r );
  friend const Rational operator + ( const Rational& rLeft, const Rational& rRight );
  friend const Rational operator - ( const Rational& rLeft, const Rational& rRight );
  friend const Rational operator * ( const Rational& rLeft, const Rational& rRight );
  friend const Rational operator / ( const Rational& rLeft, const Rational& rRight );

  Rational& operator += ( const Rational& r );
  Rational& operator -= ( const Rational& r );
  Rational& operator *= ( const Rational& r );
  Rational& operator /= ( const Rational& r );

  double Value() const;
  operator double() const;
  void NWD();

  friend istream& operator >> ( istream& in, Rational& r );
  friend ostream& operator << ( ostream& out, const Rational& r );

private:
  int m_Numerator;
  int m_Denominator;
};

inline void Rational::setNumerator( int Num )
{
  m_Numerator = Num;
}
inline void Rational::setDenominator( int Denum )
{
  m_Denominator = Denum;
}
inline void Rational::setRational( int Num, int Denum )
{
  setNumerator( Num );
  setDenominator( Denum );
}
inline int Rational::getNumerat() const
{
  return m_Numerator;
}
inline int Rational::getDenominat() const
{
  return m_Denominator;
}
inline void Rational::NWD()
{
  int r = m_Numerator % m_Denominator;
  int x = abs(m_Numerator);
  int y = abs(m_Denominator);

  while( r != 0 )
  {
    x = y;
    y = r;
    r = x % y;
  }
  setRational( m_Numerator / y, m_Denominator / y );
}