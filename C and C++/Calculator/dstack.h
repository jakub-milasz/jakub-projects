#include <cstddef>
#ifndef _DSTACK_H_
#define _DSTACK_H_		

typedef struct dtagStackItem
{
  double dKey;
  dtagStackItem* pNext;
}   dStackItem;

void dPush( dStackItem** pdStack, double n ); // wloz na stos
double dPop( dStackItem** pdStack );          // zdejmij i zwroc szczytowy eleme stosu
double dTop( dStackItem* pdStack );           // zwróæ szczytowy element stosu, ale nie zdejmuj
void dDel( dStackItem** pdStack );            // zwraca true jesli stos pusty - else false
int dIsEmpty( dStackItem* pdStack );          //bylo pHead
dStackItem* dCreateStack();

#endif