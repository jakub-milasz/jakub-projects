#pragma once
#include "Person.h"
class Worker : public Person
{
public:
  Worker( string name = "", int age = 0, double salary=0, int workAge=0 );
  virtual ~Worker();

  void setSalary( double salary );
  void setWorkAge( int workAge );
  void setWorker( string name, int age, double salary, int workAge );
  double getSalary() const;
  int getWorkAge() const;

  virtual double countSalaryNetto() = 0;
  void printWorker();

private:
  double m_Salary;
  int m_WorkAge;
};

inline void Worker::setSalary( double salary )
{
  m_Salary = salary;
}

inline void Worker::setWorkAge( int workAge )
{
  m_WorkAge = workAge;
}

inline double Worker::getSalary() const
{
  return m_Salary;
}

inline int Worker::getWorkAge() const
{
  return m_WorkAge;
}

inline void Worker::setWorker( string name, int age, double salary, int workAge )
{
  setPerson( name, age );
  setSalary( salary );
  setWorkAge( workAge );
}