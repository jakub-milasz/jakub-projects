#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef enum { UP, RIGHT, DOWN, LEFT } Move;

int move( int** pTab, int nRow, int nCol, int nDepth,
  int move, int x, int y, int* px, int* py, int** pRoot )
{
  switch( move )
  {
  case UP:    *px = x-1; *py = y;   break;
  case DOWN:  *px = x+1; *py = y;   break;
  case LEFT:  *px = x;   *py = y-1; break;
  case RIGHT: *px = x;   *py = y+1; break;
  }
  if( *px >= 0 && *px < nRow && *py >= 0 && *py < nCol && pTab[*px][*py] > nDepth && pRoot[*px][*py] == 0 ) return 1;
  return 0;
}
int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot,
  int x_dest, int y_dest )  // return 1 - dotarto do portu lub prawidlowy ruch, return 0 - zly ruch
{
  static int k = 1;
  pRoot[x][y] = k++; // wstawic do tablicy pRoot kolejny numer ruchu

  if( x == x_dest && y == y_dest ) return 1;

  int px = x;  //zdefiniowac nowe wspolrzende
  int py = y;

  for( int i = UP; i<=LEFT; i++ )  // sprwadzic wszystkie mozliwosci ruchu
  {
    //jesli ruch jest mozliwy w zadanym kierunku 
    //jesli wykonanie kolejnego kroku sie powiodlo - rekurencyjnie root()
    if( move ( pTab, nRow, nCol, nDepth, i, x, y, &px, &py, pRoot ) == 1 &&  
      root( pTab, nRow, nCol, nDepth, px, py, pRoot, x_dest, y_dest ) == 1 ) return 1; //ruch jest mozliwy
  }

  pRoot[x][y] = 0; //jesli wracamy to ustawiamy w pRoot ze ruch byl zly
  k--;

  return 0;
}
int setTab( char* sFile, int** pTab, int nRow, int nCol )
{
  FILE* fin = NULL;

  if( ( fin = fopen( sFile, "r" ) ) == NULL ) return 0;
  for( int i = 0; i<nRow; i++ )
  {
    int* v = *pTab++;
    for( int j = 0; j<nCol; j++, v++ )
    {
      fscanf( fin, "%d ", v );
    }
  }
  fclose( fin );
  return 1;
}
void clearRoot( int** pRoot, int nRow, int nCol )
{
  memset( *pRoot, 0, nRow * nCol *  sizeof( int ) );
}
