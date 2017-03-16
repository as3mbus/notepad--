#ifndef DOUBLE_LINK_LIST_H_INCLUDED
#define DOUBLE_LINK_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#define NIL NULL

typedef char infotype;
typedef struct elm *address;
typedef struct elm{
    infotype info;
    address next;
    address prev;
} elmtlist;

typedef struct elt *text;
typedef struct elt{
    text next;
    address first;
    text prev;
}List;

boolean listempty(List L);
void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);
boolean fsearch(List L, address P);
address Search (List L,infotype X);
address SearchPrec (List L,infotype X);
address GoTo (List L,address P);
address GoToPrec (List L,address P);
void insvfirst(List *L,infotype X);
void insvlast(List *L,infotype X);
void delvfirst(List *L,infotype *X);
void delvlast(List *L,infotype *X);

void insertfirst(List *L, address P);
void insertafter(List *L,address P,address C);
void insertlast(List *L, address P);

void delfirst(List *L,address *P);
void delp(List *L,infotype X);
void delpe(List *L,infotype X);
void dellast(List *L, address *P);
void delafter(List *L, address *pdel, address prec);

void printinfo (List L);
int nbelmt(List L);

infotype Max(List L);
address adrmax(List L);
infotype Min (List L);
address adrmin(List L);
float average (List L);

void delall(List *L);
void inverselist(List *L);
List finverselist(List L);
void copylist(List*L1,List*L2);
List fcopylist(List L);
void cpaloklist(List Lin,List *Lout);
void konkat (List L1,List L2, List *L3);
void konkat1 (List *L1,List *L2,List *L3);
void pecahlist (List *L1, List *L2,List L);
address sequential_search_terurut(List L,address X);
address sequential_search_terurut_sentinel(List L,infotype X);
void multirember(List *L);
address Last(List L);
void delprev(List *L, address *pdel, address after);
void insertprev(List *L,address P,address C);
int indexaddr(List L,address P);
address gotoindex(List L,int index);
int hitungkata(List L);
#endif // DOUBLE_LINK_LIST_H_INCLUDED
