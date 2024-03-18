#include "Sort.h" //interfejs publiczny modu³u

void Update( int* pTab, int nSize, int i );
void QuickSortHelp( int* pTab, int l, int p );

void BubbleSort(int* pTab,int nSize)
{
  for( int i=0; i<nSize-1; i++ )
    for( int j=nSize-1; j>i; j-- )
      if( pTab[j] < pTab[j-1] )
      {
        int temp = pTab[j]; pTab[j] = pTab[j-1]; pTab[j-1] = temp;
      }
}
void SimpleInsertionSort( int* pTab, int nSize )
{
  for( int i = 1; i < nSize; i++ )
  {
    int j = i-1;
    int x = pTab[i];
    while( j >= 0 && pTab[j] > x )
      pTab[j+1] = pTab[j--];
    pTab[j+1] = x;
  }
}
void SimpleSelectionSort( int* pTab, int nSize )
{
  for( int i=0; i<nSize-1; i++ )
  {
    int min = pTab[i];
    int ix = i;
    for( int j=i+1; j<nSize; j++ )
      if( pTab[j] < min )
      {
        min = pTab[j]; ix = j;
      }
    pTab[ix] = pTab[i];
    pTab[i] = min;
  }
}
void MixedSort( int* pTab, int nSize )
{
  int l = 0;
  int p = nSize-1;
  int k = nSize-1;
  do
  {
    for( int j = p; j>=l; j-- )
      if( pTab[j-1]>pTab[j] )
      {
        int x = pTab[j-1];
        pTab[j-1] = pTab[j];
        pTab[j] = x;
        k=j;
      }
    l = k+1;
    for( int j = 0; j<=p; j++ )
      if( pTab[j-1]>pTab[j] )
      {
        int x = pTab[j-1];
        pTab[j-1] = pTab[j];
        pTab[j] = x;
        k = j;
      }
    p = k-1;
  } while( l<=p );
}
void HalfInsertionSort( int* pTab, int nSize )
{
  for( int i = 0; i<nSize; i++ )
  {
    int x = pTab[i];
    int l = 0;
    int p = i-1;
    while( l<=p )
    {
      int m = (l+p)/2;
      if( x<pTab[m] )
        p = m-1;
      else
        l = m+1;
    }
     for( int j = i-1; j>=l; j-- )
     {
       pTab[j+1]=pTab[j];
     }
   pTab[l] = x;
  }
}
void HeapSort( int* pTab, int nSize )
{ 
    for( int i = nSize/2; i>=0; i-- ) Update( pTab, i, nSize );

    for( int i = nSize-1; i>0; i-- ) 
    {
      int temp = pTab[0];
      pTab[0] = pTab[i];
      pTab[i] = temp;
      Update( pTab, 0, i-1 );
    }
}
void Update( int* pTab, int l, int p )
{
  if( l>=p ) return;
  int i = l; 
  int j = 2*i+1; 
  int temp = pTab[i]; 
  while( j<=p ) 
  { 
    if( j<p ) 
      if( pTab[j]<pTab[j+1] ) j++;
    if( temp>=pTab[j] ) break; 
    pTab[i] = pTab[j]; 
    i = j; 
    j = 2*i+1; 
  }
  pTab[i] = temp;
}
void QuickSortHelp( int* pTab, int l, int p )
{
  int pivot = pTab[(l+p)/2];
  int i = l;
  int j = p;
  do 
  {
    while( pTab[i]<pivot ) i++;

    while( pTab[j]>pivot ) j--;

    if( i<=j )
    {
      int temp = pTab[i];
      pTab[i] = pTab[j];
      pTab[j] = temp;
      i++; 
      j--;
    }
  } while( i<=j );

    if( j>l ) QuickSortHelp( pTab, l, j );
    if( i<p ) QuickSortHelp( pTab, i, p );
}
void QuickSort( int* pTab, int nSize )
{
  QuickSortHelp( pTab, 0, nSize-1 );
}