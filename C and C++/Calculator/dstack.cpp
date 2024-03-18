#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "dstack.h" 

using namespace std;

dStackItem* dCreateStack()
{
  return NULL;
}
void dPush( dStackItem** pdStack, double x )
{
  // alokacja pamiêci na nowy element

  dStackItem* p = (dStackItem*)malloc ( sizeof ( dStackItem ) );

  // spawdzenie czy sie powiod³o
  if( !p )
  {
    perror( "dpush: Stack overflow!\n" );
    return;
  }
  memset( p, 0, sizeof( dStackItem ) );
  // wstawiæ klucz
  p->dKey = x;
  // dowi¹zaæ (dwa podstawienia)
  p->pNext = *pdStack;
  *pdStack = p;
}
double dPop( dStackItem** pdStack )
{
  if( !dIsEmpty(*pdStack) )
  {
    double x = dTop(*pdStack);
    dDel(pdStack);
    return x;
  }
  perror( "dpop: Stack underflow1!\n" );
  return 0;
}
double dTop( dStackItem* pdStack )
{
  if( !dIsEmpty( pdStack ) )
  {

    return pdStack->dKey;
  }
  perror( "dtop: Stack underflow!\n" );
  return 0;
}
void dDel( dStackItem** pdStack )
{
  if( dIsEmpty ( *pdStack ) )
  {
    perror( "ddel: dStack underflow!\n" );
    return;
  }
  dStackItem* p = *pdStack;
  *pdStack = p->pNext;

  free( p );
}
int dIsEmpty( dStackItem* pdStack )
{
  return !pdStack;
}
