#include "Worker.h"

Worker::Worker( string name, int age, double salary, int workAge )
{
  setPerson( name, age );
  setSalary( salary );
  setWorkAge( workAge );
}

Worker::~Worker()
{
}

void Worker::printWorker()
{

}