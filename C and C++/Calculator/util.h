#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>

char GetOper();
int IsOper( char c );
double GetNum();
double Eval( double arg1, double arg2, char oper );
int Prior( char oper );

#endif 

