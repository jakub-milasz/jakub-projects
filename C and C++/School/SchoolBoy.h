#pragma once
#include "Pupil.h"

class SchoolBoy : public Pupil
{
  public:
    SchoolBoy( string name, int age, string className ) noexcept;

    virtual void printOutfit() final; //nie mozna nadpisac tej metody
};

