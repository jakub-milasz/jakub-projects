#include "PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


PQueue* PQCreate( int nSize )
{
  if( nSize < 1 ) return NULL;
  PQueue* p = (PQueue*)calloc( 1, sizeof( PQueue ) );
  if( !p ) return NULL;
  p->pPQueue = (PQItem*)calloc( nSize, sizeof( PQItem ) );
  if( !p->pPQueue ) return NULL;
  p->nPQSize = nSize;
  return p;
}

int PQisEmpty( PQueue* pPQueue ) //1 - pusta, 0 - niepusta
{
  return !pPQueue || !(pPQueue->nPQCurrSize);
}

int PQSize( PQueue* pPQueue )
{
  return (!pPQueue) ? PRIOR_ERROR : pPQueue->nPQCurrSize;
}

int PQMaxPrior( PQueue* pPQueue )
{
  return ( PQisEmpty( pPQueue ) ) ? PRIOR_ERROR : PQgetPrior( pPQueue, 0 );
}

int PQEnqueue( PQueue* pPQueue, PQINFO* pInfo, int nPrior )
{
  if( !pPQueue ) return 0;
  int pqSize = PQSize( pPQueue );
  if( pqSize >= pPQueue->nPQSize ) return 0;
  pPQueue->pPQueue[pqSize].pInfo = pInfo;
  pPQueue->pPQueue[pqSize].nPrior = nPrior;
  if( pqSize>0 ) UpdateUp( pPQueue->pPQueue, 0, pqSize );
  ++(pPQueue->nPQCurrSize);
  return 1;
}

PQINFO* PQDequeue( PQueue* pPQueue )
{
  if( PQisEmpty( pPQueue ) ) return NULL;
  int t = --pPQueue->nPQCurrSize;
  PQINFO* res = pPQueue->pPQueue[0].pInfo;
  if( t>0 )pPQueue->pPQueue[0] = pPQueue->pPQueue[t];
  memset( pPQueue->pPQueue+t, 0, sizeof( PQItem ) );
  if( PQSize( pPQueue )>1 ) UpdateDown( pPQueue->pPQueue, 0, t-1 );
  return res;
}

void PQClear( PQueue* pPQueue, void ( __cdecl* freeMem )(const void*) )
{
  if( !freeMem || !pPQueue ) 
  {
    printf( "Queue does not exist or invalid function adr!\n" );
    return;
  }
  while( !PQisEmpty( pPQueue ) )
  {
    freeMem( PQDequeue( pPQueue ) );
  }
}

void PQRelease( PQueue** adrPQueue, void ( __cdecl* freeMem )(const void*) )
{
  if( !adrPQueue || !*adrPQueue ) 
  {
    printf( "Queue does not exist or invalid function adr!\n" );
    return;
  }
  PQClear( *adrPQueue, freeMem );
  free( (*adrPQueue)->pPQueue );
  free( *adrPQueue );
  *adrPQueue = NULL;
}

void PQPrint( PQueue* pPQueue, void( __cdecl* printQ )(const void*), int i )
{
  if( !pPQueue || !printQ )
  {
    printf( "Queue does not exist or invalid function adr!\n" );
    return;
  }
  if( i<0 )
  {
    printf( "Invalid position!\n" );
    return;
  }
  if( i >= PQSize( pPQueue ) ) return;
  printQ( pPQueue->pPQueue[i].pInfo );
  printf( " Prior: (%d), Index: [%d]\n", pPQueue->pPQueue[i].nPrior, i );
  PQPrint( pPQueue, printQ, 2*i+1 );
  PQPrint( pPQueue, printQ, 2*i+2 );
}

int PQSetPrior( PQueue* pPQueue, PQINFO* UserInfo, int newPrior, int( __cdecl* compare )(const void*, const void*) )
{
  return PQsetPrior( pPQueue, PQFind( pPQueue, UserInfo, compare ), newPrior );
}

int PQsetPrior( PQueue* pPQueue, int pos, int newPrior )
{
  if( PQisEmpty( pPQueue ) ) return PRIOR_ERROR;
  int prev = PQgetPrior( pPQueue, pos );
  if( prev==POS_ERROR ) return PRIOR_ERROR;
  pPQueue->pPQueue[pos].nPrior = newPrior;
  if( newPrior > prev) UpdateUp( pPQueue->pPQueue, 0, pos );
  else if( newPrior < prev ) UpdateDown( pPQueue->pPQueue, pos, PQSize( pPQueue )-1 );
  return prev;
}

int PQGetPrior( PQueue* pPQueue, PQINFO* UserInfo, int( __cdecl* compare )(const void*, const void*) )
{
  return PQgetPrior( pPQueue, PQFind( pPQueue, UserInfo, compare ) );
}

int PQgetPrior( PQueue* pPQueue, int pos )
{
  if( PQisEmpty( pPQueue ) ) return PRIOR_ERROR;
  if( pos < 0 || pos >= PQSize( pPQueue ) ) return POS_ERROR;
  return pPQueue->pPQueue[pos].nPrior;
}

int PQFind( PQueue* pPQueue, const void* pInfo, int ( __cdecl* compare )(const void*, const void*) )
{
  if( !pPQueue || !compare )
  {
    printf( "Queue does not exist or invalid function adr!\n" );
    return 1;
  }
  for( int i = 0; i<PQSize( pPQueue ); i++ )
    if( compare( (const void*)pInfo, (const void*)pPQueue->pPQueue[i].pInfo) == 0 ) return i;
  return POS_ERROR;
}

void UpdateDown( PQItem* pTab, int l, int p )
{
  if( l>=p ) return;
  int i = l;
  int j = 2*i+1;
  PQItem temp = pTab[i];
  while( j<=p )
  {
    if( j<p )
      if( pTab[j].nPrior < pTab[j+1].nPrior ) j++;
    if( temp.nPrior >= pTab[j].nPrior ) break;
    pTab[i] = pTab[j];
    i = j;
    j = 2*i+1;
  }
  pTab[i] = temp;
}

void UpdateUp( PQItem* pTab, int l, int p )
{
  if( l>=p ) return;
  int i = p;
  int j = (i-1)/2;
  PQItem temp = pTab[i];
  while( j >= l && pTab[j].nPrior < temp.nPrior ) 
  {
    pTab[i] = pTab[j]; 
    i = j;             
    j = (i+1)/2-1; 
    /*
    W tym przypadku wyra¿enie (i-1)/2 bêdzie b³êdne, poniewa¿ gdy bêdziemy ingerowaæ 
    w element o indeksie 0 np. dodamy element, który ma najwiêkszy priorytet ze wszystkich ju¿ 
    bêd¹cych w kolejce (wtedy w pêtli while po kilku wykonaniach i=0) j wynosi dok³adnie -1/2<0. 
    Ale z racji tego, ¿e mamy tutaj do czynienia z dzieleniem ca³kowitym (int), to za j zostanie podstawione 0.
    W pliku .cpp za l podstawiam 0, wiêc wtedy j zawsze bêdzie wiêksze lub równe l i nie opuœcimy pêtli, poniewa¿
    drugi warunek te¿ bêdzie zawsze spe³niony. pTab[j] nigdzie nie jest modyfikowany w pêtli, wiêc
    gdy indeks j bêdzie sta³y (j=0), to wartoœæ bêd¹ca pod nim te¿ bêdzie sta³a.
    Natomiast wyra¿enie (i+1)/2-1 dla i=0 da wynik -1 i wtedy -1<0, wiêc opuœcimy pêtlê while.
    */
  }
  pTab[i] = temp;
}
