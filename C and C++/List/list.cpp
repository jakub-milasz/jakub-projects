#include "list.h"
#include <stdlib.h>
#include <stdio.h>

ListItem* CreateList()
{
  return (ListItem*)calloc( 1, sizeof( ListItem ) );
}
int Insert( ListItem* pAfter, LISTINFO* pInfo )
{
  if( !pAfter ) return 0;
  ListItem* pNew = (ListItem*)calloc( 1, sizeof( ListItem ) ); //1 alokacja
  if( !pNew ) return 0;
  pNew->pInfo = pInfo;         //1 wrzucamy do nowego elementu dane
  pNew->pNext = pAfter->pNext; //2 dowiazanie do listy
  pAfter->pNext = pNew;        //3 ustawienie pAfter na nowy element 
  return 1;
}
LISTINFO* Remove( ListItem* pAfter )
{
  if( IsEmpty( pAfter ) ) return NULL;
  ListItem* p = pAfter->pNext; //1 zapisanie do p pudelka, ktore usuwamy 
  LISTINFO* pInfo = p->pInfo;  //2 informacja zawarta w usuwanym elemencie
  pAfter->pNext = p->pNext;    //3 przewiazanie
  free( p );                   //4 usuniecie
  return pInfo;
}
LISTINFO* Front( ListItem* pList )
{
  return IsEmpty( pList ) ? NULL : pList->pNext->pInfo;
}
int IsEmpty( ListItem* pList )
{
  if( !pList )
  {
    printf( "Create a list!\n" );
    return 0;
  }
  return !(pList->pNext);
}
void ClearList( ListItem* pList, void ( __cdecl* freeList )(const void*) )
{
  if( !pList || !freeList )
  {
    printf( "Create a list or function freeList!\n" );
    return;
  }
  while( !IsEmpty( pList ) )
  {
    freeList( Remove( pList ) );
  }
}
void RemoveList( ListItem** adrpList, void ( __cdecl* freeList )(const void*) )
{
  if( !*adrpList || !freeList )
  {
    printf( "Create a list or function freeList!\n" );
    return;
  }
  freeList( *adrpList );
  *adrpList = NULL;
}
void SortList( ListItem* pList, int ( __cdecl* comp )(const void*, const void*) )
{
  if( !pList || !comp ) 
  {
    printf( "Create a list or function comp!\n" );
    return;
  }
  ListItem* pFirst = pList;
  while( !IsEmpty( pFirst ) ) 
  {
    ListItem* pMin = pFirst;
    ListItem* pCurr = pMin->pNext;
    while( !IsEmpty( pCurr ) ) 
    {
      if( comp( pMin->pNext->pInfo, pCurr->pNext->pInfo ) > 0 ) pMin = pCurr;
      pCurr = pCurr->pNext;
    }
    if( pMin!=pFirst ) 
    {
      pCurr = pMin->pNext->pNext;
      pMin->pNext->pNext = pFirst->pNext;
      pFirst->pNext = pMin->pNext;
      pMin->pNext = pCurr;
    }
    pFirst = pFirst->pNext;
  }
}
ListItem* Find( ListItem* pList, const void* pInfo, ListItem** pPrev, int ( __cdecl* comp )(const void*, const void*) )
{
  if( !pList || !comp )
  {
    printf( "Create a list or function comp!\n" );
    return NULL;
  }
  ListItem* p = pList;
  while( !IsEmpty( p ) ) 
  {
    if( !comp( p->pNext->pInfo, pInfo ) ) 
    {
      *pPrev = p;
      return p->pNext;
    }
    p = p->pNext;
  }
  *pPrev = NULL;
  return NULL;
}