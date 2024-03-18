#pragma once
#include "Pupil.h"

class SchoolGirl : public Pupil
{
  public:
    SchoolGirl( string name, int age, string className ) noexcept;

    virtual void printOutfit() override;
};

