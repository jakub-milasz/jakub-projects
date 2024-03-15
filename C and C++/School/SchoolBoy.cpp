#include "SchoolBoy.h"

SchoolBoy::SchoolBoy( string name, int age, string className ) noexcept : Pupil( name, age, className )
{
  m_ID = "M_" + m_ID;
}

void SchoolBoy::printOutfit()
{
  cout << "biala/niebieska koszula z krawatem, szkolna marynarka, polbuty, granatowe/czarne spodnie." << endl;
}