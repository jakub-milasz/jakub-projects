#ifndef _SORT_H
#define _SORT_H

void BubbleSort( int* pTab, int nSize );
void SimpleInsertionSort( int* pTab, int nSize );
void SimpleSelectionSort( int* pTab, int nSize );
void MixedSort( int* pTab, int nSize );           //zmodyfikowane b¹belkowe
void HalfInsertionSort( int* pTab, int nSize );   //zmodyfikowane proste wstawianie
void QuickSort( int* pTab, int nSize );
void HeapSort( int* pTab, int nSize );

#endif