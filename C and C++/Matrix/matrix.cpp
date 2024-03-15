#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim );
void ComplMatrix( double** pTabD, double** pTab, int nDim );

void TransMatrix( double** pTab, int nDim )
{
  double** v = pTab;
  for( int i = 0; i<nDim-1; i++ )
  {
    double* w = (*v++) + i + 1;
    for( int j = i+1; j<nDim; j++ )
    {
      double temp = *w;
      *w++ = pTab[j][i];
      pTab[j][i] = temp;
    }
  }
}
void InverseMatrix( double** pInv, double** pTab, int nDim, double det )
{
  ComplMatrix( pInv, pTab, nDim );
  TransMatrix( pInv, nDim );
  for( int i = 0; i<nDim; i++ ) 
  {
    double* v = *pInv++;
    for( int j = 0; j<nDim; j++, v++ )
      *v /= det;
  }
}
double Det( double** pTab, int nDim )
{
  if( nDim==1 ) return **pTab;
  if( nDim==2 ) return **pTab*pTab[1][1]-pTab[0][1]*pTab[1][0];
  double det = 0;
  double** pTemp = NULL;
  if( !CreateMatrix( &pTemp, nDim ) )
  {
    perror( "Allocation ERROR - pTemp in Det()\n" );
    return 0;
  }
  double* v = *pTab;
  int sign = 1;
  for( int i = 0; i<nDim; i++, v++ )
  {
    Complement( pTemp, pTab, 0, i, nDim );
    det += sign * *v*Det( pTemp, nDim-1 );
    sign = -sign;
  }
  free( pTemp );
  return det;
}
void LayoutEqu( double** pInv, double* pB, double* pRes, int nDim )
{
  for( int i = 0; i<nDim; i++, pRes++ )
  {
    double* v = *pInv++;
    double* k = pB;
    for( int j = 0; j<nDim; j++ )
    {
      *pRes += (*v++) * (*k++);
    }
  }
}
void Complement( double** pTabO, double** pTabI, int nRow, int nCol, int nDim )
{
  for( int i = 0; i<nDim; i++, pTabI++ )
  {
    if( i==nRow ) continue;
    double* w = *pTabI;
    double* v = *pTabO++;
    for( int j = 0; j<nDim; j++, w++ ) 
    {
      if( j==nCol ) continue;
      *v++ = *w;
    }
  }
}

void ComplMatrix( double** pTabD, double** pTab, int nDim )
{
  double** pTemp = NULL;
  if( !CreateMatrix( &pTemp, nDim ) )
  {
    perror( "Allocation ERROR - pTemp in ComplMatrix()\n" );
    return;
  }
  for( int i = 0; i<nDim; i++ )
  {
    double* v = *pTabD++;
    int sign = (i%2) ? -1 : 1;

    for( int j = 0; j<nDim; j++, v++ )
    {
      Complement( pTemp, pTab, i, j, nDim );
      *v = sign*Det( pTemp, nDim-1 );
      sign = -sign;
    }
  }
  free( pTemp );
}
int CreateMatrix( double*** pTab, int nDim )         // 3 gwiazdki, bo adres tablicy
{
  *pTab = (double**)malloc( nDim*sizeof(double*) );
  if( !*pTab )
    return 0;

  memset( *pTab, 0, nDim*sizeof(double*) );

  double** pTemp = *pTab;

  for( int i = 0; i<nDim; i++, pTemp++ ) 
  {
    *pTemp = (double*)malloc( nDim*sizeof(double) );
    if( !*pTemp ) 
    {
      return 0;
    }
    memset( *pTemp, 0, nDim*sizeof(double) );
  }
  return 1;
}
void DeleteMatrix( double*** pTab, int nDim )
{
  double** v = *pTab;
  for( int i = 0; i<nDim; i++ )
    free( *v++ );
  free( *pTab );
  *pTab = NULL;
}
