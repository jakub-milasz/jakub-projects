#pragma once
#include "Worker.h"
class Admin : public Worker
{
public:
  Admin( string name = "", int age = 0, double salary = 0, int workAge = 0, string position = "" );
  virtual ~Admin();

  void setPosition( string position );
  string getPosition() const;

  virtual double countSalaryNetto() override;
  void printAdmin();

private:
  string m_Position;
};

inline void Admin::setPosition( string position )
{
  m_Position = position;
}

inline string Admin::getPosition() const
{
  return m_Position;
}