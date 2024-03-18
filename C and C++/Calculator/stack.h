#include <cstddef>
#ifndef _STACK_H_
#define _STACK_H_

typedef struct tagStackItem
{
    char cKey;
    tagStackItem* pNext;
}StackItem;

// naglowki funkcji publicznych modulu

void Push( StackItem** pStack, char c ); // w�� na stos
char Pop( StackItem** pStack );          // zdejmij i zwr�� szczytowy element stosu
char Top( StackItem* pStack );           // zwr�� szczytowy element stosu, ale nie zdejmuj        
void Del( StackItem** pStack );          // usu� szczytowy (zdejmij)      
int IsEmpty( StackItem* pStack );        // zwraca true(1) je�li stos pusty. Je�li nie jest pusty - false(0)   
StackItem* CreateStack();

#endif 



        
