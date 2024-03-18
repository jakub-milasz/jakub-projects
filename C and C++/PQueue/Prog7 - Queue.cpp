#include <stdio.h>
#include <stdlib.h>
#include "PQueue.h"
#include <time.h>


#define SIZE 20
#define _DEBUG_

int compare( const void*, const void* );
void printQ( const void* );
void freeMem( const void* info );
PQINFO* CreateInfo();

//MAX
//FIFO

int main()
{
  srand( (unsigned)time( NULL ) );

  //wykreowanie kolejki z 20 elementami

  PQueue* MyQueue = PQCreate( SIZE );
  if( !MyQueue )
  {
    perror( "Allocation error - MyQueue!\n" );
    return 100;
  }

  //dodanie 6 elementow

  PQINFO* Item1 = CreateInfo();
  if( !Item1 )
  {
    perror( "Allocation error - Item1\n" );
    return 11;
  }
  Item1->nKey = rand()%30;
  Item1->pTab[0] = rand()%20;
  if( !PQEnqueue( MyQueue, Item1, 7 ) )
  {
    perror( "Element insert error!\n" );
    return 21;
  }

  PQINFO* Item2 = CreateInfo();
  if( !Item2 )
  {
    perror( "Allocation error - Item2\n" );
    return 12;
  }
  Item2->nKey = rand()%30;
  Item2->pTab[0] = rand()%10;
  if( !PQEnqueue( MyQueue, Item2, 18 ) )
  {
    perror( "Element insert error!\n" );
    return 22;
  }
  
  PQINFO* Item3 = CreateInfo();
  if( !Item3 )
  {
    perror( "Allocation error - Item3\n" );
    return 13;
  }
  Item3->nKey = rand()%30;
  Item3->pTab[0] = rand()%10;
  if( !PQEnqueue( MyQueue, Item3, 12 ) )
  {
    perror( "Element insert error!\n" );
    return 23;
  }
  
  PQINFO* Item4 = CreateInfo();
  if( !Item4 )
  {
    perror( "Allocation error - Item4\n" );
    return 14;
  }
  Item4->nKey = rand()%30;
  Item4->pTab[0] = rand()%10;
  if( !PQEnqueue( MyQueue, Item4, 9 ) )
  {
    perror( "Element insert error!\n" );
    return 24;
  }
  
  PQINFO* Item5 = CreateInfo();
  if( !Item5 )
  {
    perror( "Allocation error - Item5\n" );
    return 15;
  }
  Item5->nKey = rand()%30;
  Item5->pTab[0] = rand()%10;
  if( !PQEnqueue( MyQueue, Item5, 14 ) )
  {
    perror( "Element insert error!\n" );
    return 25;
  }
  
  PQINFO* Item6 = CreateInfo();
  if( !Item6 )
  {
    perror( "Allocation error - Item6\n" );
    return 16;
  }
  Item6->nKey = rand()%30;
  Item6->pTab[0] = rand()%10;
  if( !PQEnqueue( MyQueue, Item6, 2 ) )
  {
    perror( "Element insert error!\n" );
    return 26;
  }

  printf( "Kolejka po dodaniu 6 elementow:\n" );
  PQPrint( MyQueue, printQ, 0 );


  //usuniecie jednego elementu

  PQINFO* p = PQDequeue( MyQueue );
  printf( "\nKolejka po usunieciu 1 elementu:\n" );
  PQPrint( MyQueue, printQ, 0 );
  printf( "\nKlucz usunietego elementu: %d\n", p->nKey );
  freeMem( p );

  //dodanie nastepnych 2 elementow

  PQINFO* newItem1 = CreateInfo(); //!!!!!!
  if( !newItem1 )
  {
    perror( "Allocation error - newItem1!\n" );
    return 101;
  }
  newItem1->nKey = 32;
  newItem1->pTab[0] = 77;
  PQEnqueue( MyQueue, newItem1, 134 );

  PQINFO* newItem2 = CreateInfo(); //!!!!!
  if( !newItem2 )
  {
    perror( "Allocation error - newItem2!\n" );
    return 102;
  }
  newItem2->nKey = 234;
  newItem2->pTab[0] = 172;
  PQEnqueue( MyQueue, newItem2, 1 );

#ifdef _DEBUG_
  printf( "\nKolejka po dodaniu 2 kolejnych elementow:\n" );
  PQPrint( MyQueue, printQ, 0 );
#endif

  //wyszukiwanie elementu

  PQINFO* wantedInfo1 = CreateInfo(); //!!!!!!!!
  if( !wantedInfo1 )
  {
    perror( "Allocation error - wantedInfo1\n" );
    return 111;
  }
  wantedInfo1->nKey = 234;
  wantedInfo1->pTab[0] = 172;

  //zwiekszanie priorytetu

  PQsetPrior( MyQueue, PQFind( MyQueue, wantedInfo1, compare ), 100 );
#ifdef _DEBUG_
  printf( "\nKolejka po zwiekszeniu priorytetu jednego elementu:\n" );
  PQPrint( MyQueue, printQ, 0 );
#endif 

  //zmniejszanie priorytetu

  PQINFO* wantedInfo2 = CreateInfo();
  if( !wantedInfo2 )
  {
    perror( "Allocation error - wantedInfo2\n" );
    return 112;
  }
  wantedInfo2->nKey = 32;
  wantedInfo2->pTab[0] = 77;

  PQsetPrior( MyQueue, PQFind( MyQueue, wantedInfo2, compare ), 4 );
#ifdef _DEBUG_
  printf( "\nKolejka po zmniejszeniu priorytetu jednego elementu:\n" );
  PQPrint( MyQueue, printQ, 0 );
#endif

  //dublowanie maksymalnego priorytetu

  PQsetPrior( MyQueue, 6, PQMaxPrior( MyQueue ) );
#ifdef _DEBUG_
  printf( "\nKolejka po zdublowaniu maksymalnego priorytetu:\n" );
  PQPrint( MyQueue, printQ, 0 );
#endif
  p = PQDequeue( MyQueue ); //zapamietac wskaznik z dequeue
  freeMem( p );
#ifdef _DEBUG_
  printf( "\nKolejka po usunieciu 1 elementu:\n" );
  PQPrint( MyQueue, printQ, 0 );
#endif
  p = PQDequeue( MyQueue );
  freeMem( p );
#ifdef _DEBUG_
  printf( "\nKolejka po usunieciu 2 elementu:\n" );
  PQPrint( MyQueue, printQ, 0 );
#endif

  //usuniecie kolejki

  PQRelease( &MyQueue, freeMem );

  return 0;
}



//(%0d)[%d] ()prior []index
//najpierw 2i + 1, potem 2i + 2
//sprawdzać, czy kolejka jest i czy jest niepusta


int compare( const void* i1, const void* i2 )
{
  if( ( (PQINFO*)i1 )->nKey > ( (PQINFO*)i2 )->nKey ) return 1;
  if( ( (PQINFO*)i1 )->nKey < ( (PQINFO*)i2 )->nKey ) return -1;
  return 0;
}
void printQ( const void* pTab )
{
  PQINFO* p = (PQINFO*)pTab;
  printf( "Key: %d, tab elem.: %d", p->nKey, p->pTab[0] );
}
void freeMem( const void* info )
{
  free( ((PQINFO*)info)->pTab );
  free( (PQINFO*)info );
  info = NULL;
}
PQINFO* CreateInfo()
{
  PQINFO* p = (PQINFO*)calloc( 1, sizeof( PQINFO ) );
  if( !p )
  {
    return NULL;
  }
  p->pTab = (int*)calloc( 2, sizeof( int ) );
  if( !(p->pTab) )
  {
    return NULL;
  }
  return p;
}
