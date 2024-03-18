#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dstack.h"
#include "util.h"
#include <math.h>

using namespace std;

double ONP();

int main()
{
	printf( "Podaj wyrazenie: " );
	printf( "Wartosc wyrazenia = %lf\n", ONP() );
	return 0;
}
double ONP()
{
	StackItem* pStack = CreateStack();                                // operator
	dStackItem* pdStack = 	dCreateStack();                           // operand
	char c;				                                                    // obecnie przetwarzany znak
	dPush( (&pdStack), GetNum());	                                    // pobierz operand	                                      
	while( IsOper( c = GetOper() ) )		                              // wczytanie potencjalnego operatora i sprzawdzenie czy operator
	{
		while( Prior( c )<=Prior( Top(pStack) ) )                       // sprawdzanie priorytetu (przetwarzanego znaku priorytet jest <= od tego na szczycie)
		{
			double x = dPop(&pdStack);                                    // zdejmuje szczytowy i podstawia za x
			dPush( (&pdStack), Eval( dPop(&pdStack), x, Pop(&pStack) ) ); // w³ó¿ na stos wynik dzia³ania
		}
		Push( &pStack, c );							             
		dPush( (&pdStack), GetNum() );                                  // wstawic na stos liczbowy
	}
	while( !IsEmpty(pStack) )					                                // gdy stos nie jest pusty 
	{
		double x = dPop(&pdStack);                                      // zdejmuje szczytowy i podstawia za x
		dPush( &pdStack, Eval( dPop(&pdStack), x, Pop(&pStack) ) );     // w³ó¿ na stos wynik dzia³ania
	}
	return dPop(&pdStack);                                            // zdejmij i zwróæ wynik
}