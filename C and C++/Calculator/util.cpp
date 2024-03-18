#include "util.h"
#include <math.h>

#define MIN_DBL 1e-300

int IsDigit( char c );
void SkipSpaces();


char GetOper()
{
	SkipSpaces();
	return getchar();
}

int IsOper( char c )
{
	switch( c )
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':return 1;
	}
	return 0;
}
double GetNum()
{
	char c;
	double res = 0;
	SkipSpaces();
	while( IsDigit( c=getchar() ) )
	{
		res = res*10+c-'0';
	}
	if( c=='.' )
	{
		double coef = 0.1;
		while( IsDigit( c = getchar() ) )
		{
			res += coef*(c-'0');
			coef *= 0.1;
		}
	}
	ungetc( c, stdin );
	return res;
}

double Eval( double arg1, double arg2, char oper )
{
	switch( oper )
	{
	case '+':	return arg1+arg2;
	case '-':	return arg1-arg2;
	case '*':	return arg1*arg2;
	case '/':	if( fabs( arg2 )>MIN_DBL )
		return arg1/arg2;
		perror( "Division by ZERO!!!\n" );
		break;
	case '^': return pow( arg1, arg2 );
	}
	return 0;
}

int Prior( char oper )
{
	switch( oper )
	{
	case '+': 
	case '-':	return 1;
	case '*': 
	case '/':	return 2;
	case '^':	return 3;
	}
	return 0;
}

void SkipSpaces()
{
	char c;
	while( (c = getchar())==' '|| c=='\t' );
	ungetc( c, stdin );
}

int IsDigit( char c )
{
	return(c>='0')&&(c<='9');
}
