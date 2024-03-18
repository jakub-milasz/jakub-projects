#include "stack.h"  
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


StackItem* CreateStack()
{
  return NULL;
}
void Push( StackItem** pStack, char c )
{
  //alokowac pamiec na nowy element

  StackItem* p = (StackItem*)malloc( sizeof ( StackItem ) );

  //spawdzic czy sie powiodlo
  if( !p )
  {
    perror( "Error: Stack overflow!\n" );
    return;
  }
  memset( p, 0, sizeof( StackItem ) );
  //wstawic klucz
  p->cKey = c;
  //dowiazac (dwa podstawienia)
  p->pNext = *pStack;
  *pStack = p;
}
char Pop( StackItem** pStack )
{
  if( !IsEmpty( *pStack ) )
  {
    char x = Top( *pStack );
    Del( pStack );
    return x;
  }
  perror( "Stack underflow1!\n" );
  return 0;
}
char Top( StackItem* pStack )
{
  if( !IsEmpty ( pStack ) ) return pStack->cKey;
  return 0;
}
void Del( StackItem** pStack )
{
  if( IsEmpty ( *pStack ) )
  {
    perror( "del: stack underflow!\n" );
    return;
  }
  StackItem* p = *pStack;
  *pStack = p->pNext;

  free( p );
}
int IsEmpty( StackItem* pStack )
{
  return !pStack;
}