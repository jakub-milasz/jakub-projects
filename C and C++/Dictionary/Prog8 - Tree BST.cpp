#include "BSTTree.h"



int main( int argc, char* argv[] )
{
  if( argc != 3 )
  {
    printf( "Usage: %s <input_files_names>\n", argv[0] );
    return 1;
  }

  FILE* file = NULL;
  OpenFile( &file, argv[1] );
  tagTreeItem* pRoot = NULL;
  ReadData( file, &pRoot );
  fclose( file );

  PrintIndex( pRoot );

  //file = NULL;
  WriteToFile( &file, argv[2] );
  SaveIndex( pRoot, file );
  fclose( file );

  FreeTree( &pRoot );
  return 0;
}