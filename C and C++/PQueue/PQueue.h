#pragma once

#include "global.h"

#define PRIOR_ERROR INT_MIN
#define POS_ERROR -1   

typedef struct    // zachowac oryginalne nazwy!!!!!!  
{
  PQINFO* pInfo;       // Ptr to user info  
  int nPrior;      // prior value (int) for the user info  
} PQItem;         // type of the queue item

typedef struct   // zachowac oryginalne nazwy!!!!!!
{
  PQItem* pPQueue;     // kolejka realizowana w postaci stogu  (dynamiczna tablica)
  int nPQSize;      // rozmiar calkowity kolejki priorytetowej
  int nPQCurrSize;  // ilosc elelemntow w kolejce (jednoczensie indeks pierwszego wolnego miejsc w kolejce) 
} PQueue;

PQueue* PQCreate( int nSize );   // kreuje kolejke o zadanym rozmiarze i zwraca wskaznik do niej lub NULL gdy blad

int PQisEmpty( PQueue* pPQueue );  // zwraca 0 -nie pusta lub 1 - kolejka pusta

int PQSize( PQueue* pPQueue );     // zwraca ilosc elementow w kolejce

int PQMaxPrior( PQueue* pPQueue ); // zwraca najwiekszy priorytet w kolejce (z zerowej pozycji) lub PRIOR_ERROR

int PQEnqueue( PQueue* pPQueue, PQINFO* pInfo, int nPrior );  // wstawia do kolejki informacje o zadanym priorytecie, zwraca 0 (niepowodzenie) lub 1 (powodzenie)

PQINFO* PQDequeue( PQueue* pPQueue );  // zwraca informacje o najwyzszym priorytecie lub NULL gdy niepowodzenie

void PQClear( PQueue* pPQueue, void ( __cdecl* freeMem )(const void*) );    // czysci cala kolejke zwalniajac pamiec alokowana przez uzytkownika (na info), nie znana struktura 
// do zwolnienia dlatego przekazac trzeba funkcje uzytkownika do zwolnienia pamieci przez parametr 

void PQRelease( PQueue** adrPQueue, void ( __cdecl* freeMem )(const void*) );  // usuwa cala kolejke, zwraca w parametrze we-wy NULL (kolejka) usuwaj¹c wszyskto 
// wczesniej (czyszczenie kolejki)

void PQPrint( PQueue* pPQueue, void( __cdecl* printQ )(const void*), int i );    // drukuje w porzadku preorder (rekurencyjnie) od zadanej pozycji, aby wydrukowaæ info uzytkownika 
// przekazac trzeba funkcje drukujaca ta informacje. Dodatkowo, drukuje priorytet w okraglych nawiasach 
// oraz pozycje w  kolejce w kwadratowych nawiasach

int PQSetPrior( PQueue* pPQueue, PQINFO* UserInfo, int newPrior, int( __cdecl* compare )(const void*, const void*) ); // ustawia nowy priorytet dla zadanej informacji uzytkownika, nie znana struktura informacji, która trzeba 
// wyszukac dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika. 
// Funkcja zwraca poprzedni priorytet lub PRIOR_ERROR 

int PQsetPrior( PQueue* pPQueue, int pos, int newPrior ); // ustawia nowy priorytet dla informacji uzytkownika bedacej na zadanej pozycji w kolejce 
// (indeks w tablicy). Funkcja zwraca poprzedni priorytet. W przypadku bledu zwraca PRIOR_ERROR 

int PQGetPrior( PQueue* pPQueue, PQINFO* UserInfo, int( __cdecl* compare )(const void*, const void*) ); // zwraca priorytet informacji uzytkownika w kolejce lub PRIOR_ERROR, nie znana struktura informacji, która 
// trzeba wyszukac dlatego nalezy przekazac funkcje porownujaca informacje uzytkownika  

int PQgetPrior( PQueue* pPQueue, int pos ); // zwraca priorytet informacji uzytkownika z zadanej pozycji w kolejce lub PRIOR_ERROR

int PQFind( PQueue* pPQueue, const void* pInfo, int ( __cdecl* compare )(const void*, const void*) );     // zwraca indeks wyszukiwanej informacji uzytkownika, nie znana struktura informacji uzytkownika dlatego
// przekazac trzeba funkjce porownujaca informacje uzytkownika
// Zwaraca POS_ERROR jesli nie ma info w kolejce
void UpdateDown( PQItem* pTab, int l, int p );  // update heap down between index l and p  <--- modified Update() from HeapSort 
void UpdateUp( PQItem* pTab, int l, int p );    // update heap up between index l and p  
