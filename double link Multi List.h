#ifndef DOUBLE_LINK_MULTI_LIST_H
#define DOUBLE_LINK_MULTI_LIST_H

#include "Double Link List.h"

boolean textempty(text T);
void createtext(text *T);
void dealoklist(List L);
boolean fsearchtext(text T, List L);
address Searchlist (text T,address P);
address SearchPrecList (text T,address P);
address GoToList (text T,List L);
address GoToPrecList (text T,List L);
void insadrfirst(List *L,infotype X);
void insadrlast(List *L,infotype X);
void deladrfirst(List *L,infotype *X);
void deladrlast(List *L,infotype *X);

void insertlfirst(List *L, address P);
void insertlafter(List *L,address P,address C);
void insertllast(List *L, address P);

void dellfirst(List *L,address *P);
void dellp(List *L,infotype X);
void dellpe(List *L,infotype X);
void delllast(List *L, address *P);
void dellafter(List *L, address *pdel, address prec);
address Lastl(List L);
void dellprev(List *L, address *pdel, address after);
void insertlprev(List *L,address P,address C);
#endif
