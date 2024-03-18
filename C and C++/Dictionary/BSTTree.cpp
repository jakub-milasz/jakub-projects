#include "BSTTree.h"
#include <stdlib.h>
#include <string.h>



tagTreeItem* CreateTree()
{
  return (tagTreeItem*)calloc( 1, sizeof( tagTreeItem ) );
}

void FindAndInsert( tagTreeItem** pRoot, char* word, int line )
{
  //spr, ze wskaznik jest pusty
  if( !*pRoot )
  {
    //zaalokowac pamiec na pRoot
    *pRoot = CreateTree();
    if( !*pRoot )
    {
      perror( "Allocation error: pRoot\n" );
      return;
    }
    //wstawic info x i wyzerowac prawe i lewe poddrzewo
    (*pRoot)->pWord = word;
    (*pRoot)->repetition = 1;
    (*pRoot)->pLines = CreateList();
    if( !(*pRoot)->pLines )
    {
      perror( "Allocation error: pLines!\n" );
      return;
    }
    if( !Insert( (*pRoot)->pLines, line ) ) //wstawienie linii do listy
    {
      printf( "Insert error!\n" );
      return;
    }
    //(*pRoot)->pLeft = (*pRoot)->pRight = NULL;  //calloc
  }
  //jesli jest mniejszy to rekurencyjnie wstawiamy do lewego
  else if( StrCmp( word, (*pRoot)->pWord ) < 0 ) FindAndInsert( &((*pRoot)->pLeft), word, line );
  //jesli jest wiekszy to rekurencyjnie wstawiamy do prawego
  else if( StrCmp( word, (*pRoot)->pWord ) > 0 ) FindAndInsert( &((*pRoot)->pRight), word, line );
  //w przeciwnym wypadku wywolac Visit
  else Visit( *pRoot, line );
}

void Visit( tagTreeItem* pRoot, int line )
{
  ++(pRoot->repetition); //inkrementacja powtorzen
  if( pRoot->pLines->pLast->nLine != line ) //wstawienie linii wystepowania powtorzenia i sprawdzenie, czy nie sa w tej samej linii
  {
    if( !Insert( pRoot->pLines, line ) ) 
    {
      printf( "Insert error!\n" );
      return;
    }
  }
}

ListHead* CreateList()
{
  return (ListHead*)calloc( 1, sizeof( ListHead ) );
}

int Insert( ListHead* pAfter, int nLine )
{
  if( !pAfter ) return 0;
  ListItem* pNew = (ListItem*)calloc( 1, sizeof( ListItem ) ); //alokacja
  if( !pNew ) return 0;
  pNew->nLine = nLine;
  if( !pAfter->pFirst ) pAfter->pFirst = pNew;  //nowy element jest wtedy pierszym i ostatnim
  else pAfter->pLast->pNext = pNew; //nowy element idzie na koniec listy (dlatego ostatni wskazuje na nowy)      
  pAfter->pLast = pNew; //pLast wskazuje teraz na pNew
  return 1;
}

int Remove( ListHead* pAfter )
{
  if( !pAfter ) return 0;
  ListItem* p = pAfter->pFirst;      //pierwszy element listy
  pAfter->pFirst = p->pNext;         //ustawienie jako pierwszy natepnika p
  free( p );                         //usuniecie p
  return 1;
}

int IsEmpty( ListHead* pList ) // 0 - niepusta, 1 - pusta
{
  return !pList || !pList->pFirst;
}

void ClearList( ListHead* pList )
{
  if( !pList )
  {
    printf( "List does not exist!\n" );
    return;
  }
  while( !IsEmpty( pList ) )
  {
    Remove( pList );
  }
}

void RemoveList( ListHead** adrpList )
{
  if( !adrpList || !*adrpList )
  {
    printf( "List does not exist!\n" );
    return;
  }
  free( *adrpList );
  *adrpList = NULL;
}

int StrCmp( char* s1, char* s2 )
{
  char* c1 = (char*)calloc( strlen( s1 ) + 1, sizeof( char ) );  //zaalokowac dynamicznie pamiec na kopie pierwszego stringa
  if( !c1 )
  {
    perror( "Allocation error: c1!\n" );
    return 5;
  }
  char* c2 = (char*)calloc( strlen( s2 ) + 1, sizeof( char ) );  //zaalokowac dynamicznie pamiec na kopie drugiego stringa
  if( !c2 )
  {
    perror( "Allocation error: c2!\n" );
    return 6;
  }
  strcpy( c1, s1 ); //wkopiowac pierwszy do kopii-strcpy()
  strcpy( c2, s2 ); //wkopiowac drugi do kopii

  _strlwr( c1 );  //przekonwertowac albo do malych albo do duzych liter obie kopie: _strlwr() albo _strupr()
  _strlwr( c2 );

  int res = strcmp( c1, c2 ); //porownac i zapamietac wynik-strcmp()

  free( c1 );    //zwolnic pamiec na obie kopi
  free( c2 );

  return res; //zwrocic wynik
}

bool isLetter( char c )
{
  return ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ) || c == '_';
}

bool isDigit( char c )
{
  return  c >= '0' && c <= '9';
}

bool isAlpha( char c )
{
  return isLetter( c ) || isDigit( c );
}

void OpenFile( FILE** fin, char* filename )
{
  if( ( *fin = fopen( filename, "r" ) ) == NULL )
  {
    printf( "Error open file %s!\n", filename );
    return;
  }
}

void WriteToFile( FILE** fout, char* filename )
{
  if( ( *fout = fopen( filename, "w" ) ) == NULL )
  {
    printf( "Error open file %s!\n", filename );
    return;
  }
}

void ReadData( FILE* file, tagTreeItem** pRoot )
{
  int size = SIZE;
  char* word = AllocWord( size );
  if( !word )
  {
    perror( "Allocation error - word!\n" );
    return;
  }
  int line = 1;
  int i = 0;
  char c;
  while( ( c = fgetc( file ) ) != EOF )
  {
    if( i == 0 ? isLetter( c ) : isAlpha( c ) )
    {
      if( strlen( word ) % SIZE == 9 )
      {
        size += SIZE;
        word = ReallocWord( word, size );
      }
      word[i++] = c;
    }
    else
    {
      word[i] = '\0';
      i = 0;
      if( word[0] != '\0' )
      {
        FindAndInsert( pRoot, word, line );
        word = AllocWord( SIZE );
      }
      if( c == '\n' ) line++;
    }
  }
}

char* ReallocWord( char* word, int newSize )
{
  char* newWord = (char*)realloc( word, newSize * sizeof( char ) );
  if( !newWord )
  {
    perror( "Reallocation error: newWord!\n" );
    return NULL;
  }
  memset( newWord + newSize - SIZE, 0, SIZE * sizeof( char ) ); //uzupelnienie nowego obszaru zerami
  return newWord;
}

char* AllocWord( int size )
{
  return (char*)calloc( size, sizeof( char ) );
}

void SaveIndex( tagTreeItem* pRoot, FILE* fout ) //analogicznie do Print, ale z fprintf i z fout
{
  if( !pRoot ) return;
  SaveIndex( pRoot->pLeft, fout );
  SaveLine( fout, pRoot );
  SaveIndex( pRoot->pRight, fout );
}

void SaveLine( FILE* fout, tagTreeItem* pRoot )
{
  fprintf( fout, "%s, il. wystapien: %d, linia: ", pRoot->pWord, pRoot->repetition );
  ListItem* pTemp = pRoot->pLines->pFirst;
  fprintf( fout, "( " );
  while( pTemp )
  {
    fprintf( fout, "%d ", pTemp->nLine );
    pTemp = pTemp->pNext;
  }
  fprintf( fout, ")\n" );
}

void PrintIndex( tagTreeItem* pRoot ) //inOrder
{
  if( !pRoot ) return;
  PrintIndex( pRoot->pLeft );
  PrintLine( pRoot );
  PrintIndex( pRoot->pRight );
}

void PrintLine( tagTreeItem* pRoot )
{
  printf( "%s, il. wystapien: %d, linia: ", pRoot->pWord, pRoot->repetition );
  ListItem* pTemp = pRoot->pLines->pFirst;
  printf( "( " );
  while( pTemp )
  {
    printf( "%d ", pTemp->nLine );
    pTemp = pTemp->pNext;
  }
  printf( ")\n" );
}

void FreeTree( tagTreeItem** pRoot )
{
  if( !*pRoot ) return;
  //zwolnic liste
  RemoveList( &(*pRoot)->pLines );
  //zwolnic lewe poddrzewo
  (*pRoot)->pLeft = NULL;
  //zwolnic prawe poddrzewo
  (*pRoot)->pRight = NULL;
  //zwolnic pamiec na root
  *pRoot = NULL;
}
