#include <cstddef>
#ifndef _STACK_H_
#define _STACK_H_

typedef struct tagStackItem
{
    char cKey;
    tagStackItem* pNext;
}StackItem;

// naglowki funkcji publicznych modulu

void Push( StackItem** pStack, char c ); // w³ó¿ na stos
char Pop( StackItem** pStack );          // zdejmij i zwróæ szczytowy element stosu
char Top( StackItem* pStack );           // zwróæ szczytowy element stosu, ale nie zdejmuj        
void Del( StackItem** pStack );          // usuñ szczytowy (zdejmij)      
int IsEmpty( StackItem* pStack );        // zwraca true(1) jeœli stos pusty. Jeœli nie jest pusty - false(0)   
StackItem* CreateStack();

#endif 



        
