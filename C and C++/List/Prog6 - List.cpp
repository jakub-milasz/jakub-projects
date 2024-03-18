#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _PRINT_

#define ELEMENTS 20
#define KEY1 2000
#define KEY2 3000
#define MAXKEY 50
#define INDEX 9

LISTINFO* CreateInfo();
void PrintList( ListItem* pList );

int main()
{
  srand( (unsigned)time( NULL ) );
  ListItem* MyList = CreateList();
  if( !MyList )
  {
    perror( "Allocation error - MyList\n" );
    return 2;
  }
  for( int i = ELEMENTS; i>0; i-- )
  {
    LISTINFO* pInfo = CreateInfo();
    if( !pInfo )
    {
      perror( "Allocation error - pInfo!\n" );
      return 3;
    }
    pInfo->nKey = rand()%MAXKEY;
    pInfo->pTab[0] = i;
    if( i == INDEX ) pInfo->nKey = KEY1;
    if( !Insert( MyList, pInfo ) )
    {
      printf( "Element insert error!\n" );
      return 9;
    }
  }
#ifdef _PRINT_
  printf( "Lista poczatkowa:\n" );
  PrintList( MyList );
#endif

  //sortowanie

  SortList( MyList, comp );
#ifdef _PRINT_
  printf( "Posortowana lista:\n" );
  PrintList( MyList );
#endif

  //szukanie elementu 2000

  LISTINFO* pFindKey = CreateInfo();
  if( !pFindKey )
  {
    perror( "Allocation error - pFindKey!\n" );
    return 4;
  }
  pFindKey->nKey = KEY1;
  ListItem* pPrev = NULL;
  ListItem* pFind = Find( MyList, pFindKey, &pPrev, comp );
#ifdef _PRINT_
  printf( "Klucz znalezionego elementu: %d\n", pFind->pInfo->nKey );
  if( pPrev->pInfo ) printf( "Klucz wczesniejszego elementu: %d\n", pPrev->pInfo->nKey );
#endif
  //dodanie elementu 3000

  LISTINFO* pNewItem = CreateInfo();
  if( !pNewItem )
  {
    perror( "Allocation error - pNewItem\n" );
    return 5;
  }
  pNewItem->nKey = KEY2;
  pNewItem->pTab[0] = 21;
  if( !Insert( pFind, pNewItem ) )
  {
    perror( "Insert error!\n" );
    return 10;
  }
#ifdef _PRINT_
  printf( "Lista po dodaniu nowego elementu:\n" );
  PrintList( MyList );
#endif

  //usuniecie elementu 2000

  if( !Remove( pPrev ) )
  {
    perror( "Remove error!\n" );
    return 20;
  }
#ifdef _PRINT_
  printf( "Lista po usunieciu wybranego elementu:\n" );
  PrintList( MyList );
#endif

  //zwolnienie listy

  ClearList( MyList, freeInfo );
#ifdef _PRINT_
  printf( "Lista po zwolnieniu:\n" );
  PrintList( MyList );
#endif

  //dodanie 2 elementow

  LISTINFO* pItem1 = CreateInfo();
  if( !pItem1 )
  {
    perror( "Allocation error - pItem1!\n" );
    return 6;
  }
  pItem1->nKey = 1993;
  pItem1->pTab[0] = 22;

  LISTINFO* pItem2 = CreateInfo();
  if( !pItem2 )
  {
    perror( "Allocation error - pItem2!\n" );
    return 7;
  }
  pItem2->nKey = 711;
  pItem2->pTab[0] = 23;
  if( !Insert( MyList, pItem1 ) ) //dodane na poczatek
  {
    perror( "Insert error11!\n" );
    return 11;
  } 
  if( !Insert( MyList, pItem2 ) ) //dodane jeszcze przed pItem1
  {
    perror( "Insert error12!\n" );
    return 12;
  }
  printf( "Lista po dodaniu 2 elementow:\n" );
  PrintList( MyList );

  //usuniecie listy

  RemoveList( &MyList, freeInfo );
  PrintList( MyList );

  return 0;
}

int comp( const void* i1, const void* i2 )
{
  if( ( (LISTINFO*)i1 )->nKey < ( (LISTINFO*)i2 )->nKey ) return -1;
  if( ( (LISTINFO*)i1 )->nKey == ( (LISTINFO*)i2 )->nKey ) return 0;
  return 1;
}
void freeInfo( const void* info )
{
  free( ( (LISTINFO*)info )->pTab );
  free( (LISTINFO*)info );
}
LISTINFO* CreateInfo()
{
  LISTINFO* p = (LISTINFO*)calloc( 1, sizeof( LISTINFO ) );
  if( !p ) return NULL;
  p->pTab = (int*)calloc( 2, sizeof( int ) );
  if( !(p->pTab) ) return NULL;
  return p;
}
void PrintList( ListItem* pList )
{
  if( IsEmpty( pList ) )
  {
    printf( "List is empty!\n" );
    return;
  }
  ListItem* pTemp = pList;
  while( !IsEmpty( pTemp ) ) 
  {
    pTemp = pTemp->pNext;
    printf( "Tab number: %d = %d\n", pTemp->pInfo->pTab[0], pTemp->pInfo->nKey);
  }
}