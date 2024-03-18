#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <cstdlib>
#include <time.h>
#include "Sort.h"


/**** porownanie czasow sortowan ****/

#define MAXTAB 50
#define MAXLINE 10

//#define _DEBUG_

void initTab( int* pTab, int nSize );
void printTab( int* pTab,int nSize );
int createTab( int** pTab, int nSize );

typedef void(*sortFun)(int*, int);

int main( int argc, char* argv[] )
{
  if( argc!=2 )
  {
    printf( "Usage: %s <tabsize>\n", argv[0] );
    return 1;
  }
  int nSize = atoi( argv[1] );

  sortFun pSortTab[] ={BubbleSort, SimpleSelectionSort, SimpleInsertionSort, MixedSort, HalfInsertionSort, QuickSort, HeapSort};
  const char* pNames[] ={"BubbleSort", "SimpleSelectionSort", "SimpleInsertionSort", "MixedSort", "HalfInsertionSort", "QuickSort", "HeapSort"};


  int* pPattern = NULL;                                           // zdefiniowac tablice wzorcowa pattern
  if( !createTab( &pPattern, nSize ) )                            // spr. czy siê powiodlo
  {
    perror( "Allocation ERROR - pPattern!\n" );
    return 2;
  }

  initTab( pPattern, nSize );                                     // zainicjowaæ losowo pattern

  int* pTab = NULL;                                               // zdefiniowac tablice do sortowania tab
  if( !createTab( &pTab, nSize ) )                                // spr. czy siê powiodlo
  {
    perror( "Allocation ERROR - pTab!\n" );
    return 3;
  }

  const int n = sizeof( pSortTab )/sizeof( sortFun );
#ifdef _DEBUG_
  printf( "Tablica z losowymi elemntami:\n" );
  printTab( pPattern, (nSize>MAXTAB) ? MAXTAB : nSize );
#endif
  for( int i = 0; i<n; i++ )
  {
    memcpy( pTab, pPattern, nSize*sizeof( pPattern ) );                                                              // zastepuje copyTab wkopiowanie pattern do tab                                                 
    clock_t start = clock();                                                                                         // wypisac nazwe sortowania i posortowac
    pSortTab[i]( pTab, nSize );                                                                                                
    clock_t end = clock();
    printf( "\nCzas sortowania za pomoca %s wynosi %lf ms\n", pNames[i], (double)(end-start)/CLOCKS_PER_SEC*1000);   // wyliczyc i wypisac czas [ms]                                                                                                                                   
#ifdef _DEBUG_
    printTab( pTab, (nSize<MAXTAB) ? (nSize) : (MAXTAB) ); // wypisac tablice lub jej fragment
#endif
  }
  free( pTab );
  free( pPattern );

  return 0;
}

void initTab(int* pTab,int nSize)
{
  srand( (unsigned int) time(NULL) );
  for(int i = 0; i < nSize; i++)
    *pTab++ = rand() % nSize;
}
void printTab( int* pTab, int nSize )
{
  for( int i = 0; i < nSize; i++ )
  {
    printf( "%d ", *pTab++ );

    if(!((i + 1) % MAXLINE))
      printf("\n");
  }
}
int createTab( int** pTab, int nSize )
{
  *pTab = (int*)malloc( nSize*sizeof( pTab ) );
  if( !*pTab ) // if( *pTab == NULL )
    return 0;
  memset( *pTab, 0, nSize*sizeof( int ) );
  return 1;
}
