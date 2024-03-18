#pragma once

typedef struct
{
  int nKey;
  int* pTab; //dwuelementowa tablica
} ListInfo;

#define LISTINFO ListInfo

int comp( const void*, const void* );
void freeInfo( const void* );
