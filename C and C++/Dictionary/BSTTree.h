#pragma once

#include <stdio.h>

#define SIZE 10

typedef struct ListItem
{
  int nLine;
  ListItem* pNext;
}ListItem;

typedef struct ListHead
{
  ListItem* pFirst;
  ListItem* pLast;
}ListHead;

typedef struct tagTreeItem //potrzebne tylko gdy chcemy napisac wskazniki
{
  char* pWord;
  int repetition;
  ListHead* pLines;
  tagTreeItem* pLeft;
  tagTreeItem* pRight;
}TreeItem;


ListHead* CreateList();
int Insert( ListHead* pAfter, int nLine );
int Remove( ListHead* pAfter );
int IsEmpty( ListHead* pList );
void ClearList( ListHead* pList );
void RemoveList( ListHead** adrpList );
tagTreeItem* CreateTree();
void ReadData( FILE* file, tagTreeItem** pRoot );
void WriteToFile( FILE** fout, char* filename );
void SaveIndex( tagTreeItem* pRoot, FILE* fout );
void PrintIndex( tagTreeItem* pRoot );
void OpenFile( FILE** fin, char* filename );
void SaveLine( FILE* fout, tagTreeItem* pRoot );
void PrintLine( tagTreeItem* pRoot );
int StrCmp( char* s1, char* s2 );
void Visit( tagTreeItem* pRoot, int line );
void FindAndInsert( tagTreeItem** pRoot, char* word, int line );
void FreeTree( tagTreeItem** pRoot );
char* ReallocWord( char* word, int newSize );
char* AllocWord( int size );
bool isLetter( char c );
bool isDigit( char c );
bool isAlpha( char c );

