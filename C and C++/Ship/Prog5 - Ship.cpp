#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ship.h"

#define DEPTH_MIN 5
#define ROWS 10
#define COLS 10

int** CreateTab2D( int nRow, int nCol );
void PrintTab2D( int** pTab, int nRow, int nCol );
void DeleteTab2D( int*** pTab );



int main( int argc, char* argv[] )
{
  if( argc!=2 ) //!!argc
  {
    printf( "Usage: %s <input_file>\n", argv[0] );
    return 1;
  }
  int** pTab = CreateTab2D( ROWS, COLS );
  if( !pTab )
  {
    perror( "ERROR - create pTab\n" );
    return 2;
  }
  int** pRoot = CreateTab2D( ROWS, COLS );
  if( !pRoot )
  {
    perror( "ERROR - create pRoot\n" );
    return 3;
  }
  //wyzerowac obie tablice 
  clearRoot( pTab, ROWS, COLS );
  clearRoot( pRoot, ROWS, COLS );
  //wczytac dane (sprawdzic argc)  glebokosci
  if( !setTab( argv[1], pTab, ROWS, COLS ) )
  {
    printf( "Error - open file %s!\n", argv[1] );
    return 4;
  }
  printf( "Morze\n" );
  PrintTab2D( pTab, ROWS, COLS );
  //Jezeli nie znaleziono drogi od (0,0) do (N,M)- funkcja rekur root - wypisac
  if( root( pTab, ROWS, COLS, DEPTH_MIN, 0, 0, pRoot, ROWS-1, COLS-1 ) == 0 )
  {
    printf( "\nNie ma mozliwosci doplyniecia do portu!!\n\n" );
  }
  else
  {
    printf( "\n\nTrasa statku\n" );
    PrintTab2D( pRoot, ROWS, COLS );    // jesli ok to wypisac trase
  }
                            
  DeleteTab2D( &pTab );            //zwolnic pamiec!!
  DeleteTab2D( &pRoot );
  return 0;
}
int** CreateTab2D( int nRow, int nCol )
{
  int** pTab = (int**)malloc( nRow * sizeof( int* ) );
  if( !pTab ) return NULL;
  memset( pTab, 0, sizeof( int* )*nRow );


  *pTab = (int*)malloc( nRow * nCol * sizeof( int ) ); 
  if( !*pTab ) return NULL;
  memset( *pTab, 0, sizeof( int )*nRow*nCol );

  int** v = pTab+1;
  int* p = *pTab+nCol;

  for( int i = 1; i<nRow; i++, p += nCol ) *v++ = p;
  return pTab;
}
void PrintTab2D( int** pTab, int nRow, int nCol ) 
{
  for( int i = 0; i<nRow; i++ ) 
  {
    int* v = *pTab++;
    for( int j = 0; j<nCol; j++ ) 
    {
      printf( "%2d ", *v++ );
    }
    printf( "\n" );
  }
}
void DeleteTab2D( int*** pTab ) 
{
  free( **pTab );
  free( *pTab );
  *pTab = NULL;
}