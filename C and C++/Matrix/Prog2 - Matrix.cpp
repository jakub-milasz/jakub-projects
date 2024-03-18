#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <malloc.h>
#include "matrix.h"
#include <math.h>

#define _DEBUG_
#define ZERO 1e-300


void ReadData( FILE* fin, double** pMatrix, double* b, int nDim );
int CreateVector( double** pTab, int nDim );
void PrintVector( double* pTab, int nDim );

int main( int argc, char* argv[] )
{
  if( argc!=2 ) // sprawdzic argumenty main
  {
    printf( "Usage: %s <input_file>\n", argv[0] );
    return 1;
  }
  int nDim = 0;
  FILE* fin = NULL;
  if( ( fin = fopen( argv[1], "r" ) ) == NULL ) // odtworzyc plik do odczytu (tekstowy)
  {
    printf( "ERROR - open file %s!\n", argv[1]);
    return 2;
  }
  fscanf( fin, "%d", &nDim ); //odczytac rozmiar nDim   fscanf( fin, "%d", &nDim ), nDim param WY fin plik po otwarciu do odczytu
  double** pMatrix = NULL;              // wykreowac macierz pMatrix ukladu nDim x nDim
  if( !CreateMatrix( &pMatrix, nDim ) )
  {
    perror( "Allocation ERROR - pMatrix!\n" );
    return 3;
  }
  double* pB = NULL;                // wykreowac wektor wyrazow wolnych b
  if( !CreateVector( &pB, nDim ) )   
  {
    perror( "Allocation ERROR - pB!\n" );
    return 4;
  }
  ReadData( fin, pMatrix, pB, nDim ); // wczytac dane ( ReadData() )
#ifdef _DEBUG_
  printf( "Macierz poczatkowa:\n" );  //wydruk kontrolny (warunkowa kompilacja)
  PrintMatrix( pMatrix, nDim );
  printf( "\nWyrazy wolne:\n" );
  PrintVector( pB, nDim );
#endif
  double det = Det( pMatrix, nDim );
#ifdef _DEBUG_
  printf( "\nWyznacznik wynosi %lf\n", det );
#endif

  if( fabs(det)<ZERO )
  {
    printf( "Macierz osobliwa\n" );
    return 10;
  }
  double** pInverse = NULL;
  if( !CreateMatrix( &pInverse, nDim ) )
  {
    perror( "Allocation ERROR - pInverse!\n" );
    return 5;
  }
  InverseMatrix( pInverse, pMatrix, nDim, Det( pMatrix, nDim ) ); //obl wyznacznik i obrocic macierz
  //TransMatrix( pInverse, nDim );
#ifdef _DEBUG_
  printf( "\nMacierz odwrotna:\n" ); //wydruk kontrolny (warunkowa kompilacja)
  PrintMatrix( pInverse, nDim );
#endif
  double* pRes = NULL;               // wykreowac wektor wynikowy
  if( !CreateVector( &pRes, nDim ) )
  {
    perror( "Allocation ERROR - pRes!\n" );
    return 6;
  }
  printf( "\n" );

  LayoutEqu( pInverse, pB, pRes, nDim );  // rozwiazac uklad

  printf( "Rozwiazanie:\n" );  // wyniki
  PrintVector( pRes, nDim );                        

  DeleteMatrix( &pMatrix, nDim );     // zwolnic pamiec !!!
  DeleteMatrix( &pInverse, nDim );   
  free( pB );
  free( pRes );

  return 0;
}
void ReadData( FILE* fin, double** pMatrix, double* b, int nDim )
{
  for( int i = 0; i<nDim+1; i++ )
  {
    double* v = *pMatrix++;
    for( int j = 0; j<nDim; j++, v++ )
    {
      fscanf( fin, "%lf ", v );
    }
    fscanf( fin, "%lf ", b++ );
  }
  fclose( fin );
}
void PrintMatrix( double** pTab, int nDim )
{
  for( int i = 0; i<nDim; i++ )
  {
    double* v = *pTab++; 
    for( int j = 0; j<nDim; j++ )
    {
      printf( "%2.3lf ", *v++ );
    }
    printf( "\n" );
  }
}
int CreateVector( double** pTab, int nDim )
{
  *pTab = (double*)malloc( nDim*sizeof( double ) );
  if( !*pTab ) {
    return 0;
  }

  memset( *pTab, 0, nDim*sizeof( double ) );

  return 1;
}
void PrintVector( double* pTab, int nDim )
{
  for( int i = 0; i<nDim; i++ )
  {
    printf( "%.3lf\n", *pTab++ );
  }
}
/*
mamy macierz
liczymy wyznacznik
jak ró¿ny od 0, to mozna odwracac macierz
zeby odwrocic, to trzeba:
1) stworzyc macierz dopelnien
2) za pomoca dopelnien odwrocic macierz ze wzoru 1/det*D^T
*/