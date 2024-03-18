#pragma once

#include "global.h"

typedef struct tagListItem
{
  LISTINFO* pInfo;
  tagListItem* pNext;
} ListItem;

ListItem* CreateList();
int Insert( ListItem* pAfter, LISTINFO* pInfo );
LISTINFO* Remove( ListItem* pAfter );
LISTINFO* Front( ListItem* pList );
int IsEmpty( ListItem* pList );
void ClearList( ListItem* pList, void ( __cdecl* freeMem )(const void*) );
void RemoveList( ListItem** adrpList, void ( __cdecl* freeMem )(const void*) );
void SortList( ListItem* pList, int ( __cdecl* comp )(const void*, const void*) );
ListItem* Find( ListItem* pList, const void* pInfo, ListItem** pPrev, int ( __cdecl* comp )(const void*, const void*) );