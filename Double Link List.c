#include "Double Link List.h"
boolean listempty(List L){
    return L.first==NIL;
}
void createList(List *L){
    L->first= NIL;
}
address alokasi(infotype X){
    address P;
    P=malloc(sizeof(elmtlist));
    P->info=X;
    P->next=NIL;
    P->prev=NIL;
    return P;
}
void dealokasi(address P){
    free (P);
}
boolean fsearch(List L, address P){
    address A=L.first;
    boolean found=false;
    while(A!=NIL&&!found){
        if(A==P){
            found = true;
        }
        else{
            A=A->next;
        }
    }
    return found;
}
address Search (List L,infotype X){
    address A=L.first;
    boolean found=false;
    while(A!=NIL&&!found){
        if(A->info==X){
            found = true;
        }
        else{
            A=A->next;
        }
    }
    return A;
}
address SearchPrec (List L,infotype X){
    return Search(L,X)->prev;
}
address GoTo (List L,address P){
    address A=L.first;
    boolean found=false;
    while(A!=NIL&&!found){
        if(A==P){
            found = true;
        }
        else{
            A=A->next;
        }
    }
    return A;
}
address GoToPrec (List L,address P){
    return GoTo(L,P)->prev;
}
void insvfirst(List *L,infotype X){
    address P=alokasi(X);
    if (P!=NIL){
        insertfirst(L,P);
    }
}
void insvlast(List *L,infotype X){
    address P=alokasi(X);
    if(P!=NIL){
        insertlast(L,P);
    }
}
void delvfirst(List *L,infotype *X){
    if(listempty(*L)){
        printf("list kosong\n");
    }
    else{
        if(L->first->next==NIL){
            *X=L->first->info;
            address firs=L->first;
            L->first=NIL;
            dealokasi(firs);
        }
        else{
            *X=L->first->info;
            address firs=L->first;
            L->first=L->first->next;
            dealokasi(firs);
        }
    }
}
void delvlast(List *L,infotype *X){
    if (listempty(*L)){
        delvfirst(L,X);
    }
    else{
        if(L->first->next==NIL){
            delvfirst(L,X);
        }
        else{
            address las=Last(*L);
            *X=las->info;
            las->prev->next=NIL;
            dealokasi(las);
        }
    }
}

void insertfirst(List *L, address P){
    if(P!=NIL){
        if(listempty(*L)){
            L->first=P;
        }
        else{
            L->first->prev=P;
            P->next=L->first;
            L->first=P;
        }
    }
}
void insertafter(List *L,address P,address C){
    if (P!=NIL){
        if(fsearch(*L,C)&&C->next!=NIL){
            P->prev=C;
            P->next=C->next;
            C->next->prev=P;
            C->next=P;
        }
        else if (C->next==NIL){
            insertlast(L,P);
        }
        else if(C==NIL){
            insertlast(L,P);
        }
    }
}
void insertprev(List *L,address P,address C){
    if(fsearch(*L,C)&&C->prev!=NIL){
            P->next=C;
            P->prev=C->prev;
            C->prev->next=P;
            C->prev=P;
        }
        else if (C->prev==NIL){
            insertfirst(L,P);
        }
}
void insertlast(List *L, address P){
    if (P!=NIL){
        if (listempty(*L)){
            L->first=P;
        }
        else{
            address las=Last(*L);
            las->next=P;
            P->prev=las;
            P->next=NIL;
        }
    }
}

void delfirst(List *L,address *P){
    if(listempty(*L)){
        printf("list kosong\n");
    }
    else{
        if(L->first->next==NIL){
            *P=L->first;
            L->first=NIL;
        }
        else{
            *P=L->first;
            L->first=L->first->next;
            L->first->prev=NIL;
            (*P)->next=NIL;
        }
    }
}
void delp(List *L,infotype X){
    if (fsearch(*L,Search(*L, X))){
        address P;
        if(Search(*L,X)==L->first){
            delfirst(L,&P);
        }
        else{
            delafter(L,&P,Search(*L,X)->prev);
        }
        dealokasi(P);
    }
}
void delpe(List *L,infotype X){
    while (fsearch(*L,Search(*L, X))){
        delp(L,X);
    }
}
void dellast(List *L, address *P){
    if (listempty(*L)){
        delfirst(L,P);
    }
    else{
        if(L->first->next==NIL){
            delfirst(L,P);
        }
        else{
            address las=Last(*L);
            *P=las;
            las->prev->next=NIL;
            (*P)->prev=NIL;
        }
    }
}
void delafter(List *L, address *pdel, address prec){
    if (!listempty(*L)&&(fsearch(*L,prec))&&prec->next!=Last(*L)){
        *pdel=prec->next;
        prec->next->next->prev=prec;
        prec->next=prec->next->next;
        (*pdel)->next=NIL;
        (*pdel)->prev=NIL;
    }
    else if(prec->next==Last(*L)){
        dellast(L,pdel);
    }
}
void delprev(List *L, address *pdel, address after){
    if (!listempty(*L)&&(fsearch(*L,after))&&after->prev!=L->first){
        *pdel=after->prev;
        after->prev->prev->next=after;
        after->prev=after->prev->prev;
        (*pdel)->next=NIL;
        (*pdel)->prev=NIL;
    }
    else if(after->prev==L->first){
        delfirst(L,pdel);
    }
    else if(after->prev==NIL){
    }
}
void printinfo (List L){
    address P=L.first;
    while(P!=NIL){
        printf("%c",P->info);
        if(P->next==NIL){
            printf("\n");
        }
        P=P->next;
    }
}
int nbelmt(List L){
    address P=L.first;
    int i=0;
    while (P!=NIL){
        i++;
        P=P->next;
    }
    return i;
}

infotype Max(List L){
    address P=L.first;
    infotype m=L.first->info;
    while (P!=NIL){
        if (m<=P->info){
            m=P->info;
        }
        P=P->next;
    }
    return m;
}
address adrmax(List L){
    address P=L.first;
    address m=L.first;
    while (P!=NIL){
        if (m->info<=P->info){
            m=P;
        }
        P=P->next;
    }
    return m;
}
infotype Min (List L){
    address P=L.first;
    infotype m=L.first->info;
    while (P!=NIL){
        if (m>=P->info){
            m=P->info;
        }
        P=P->next;
    }
    return m;
}
address adrmin(List L){
    address P=L.first;
    address m=L.first;
    while (P!=NIL){
        if (m->info>=P->info){
            m=P;
        }
        P=P->next;
    }
    return m;
}
float average (List L){
    address P=L.first;
    float a=0;
    int i=0;
    while (P!=NIL){
        i++;
        a+=P->info;
        P=P->next;
    }
    return a/i;
}
void delall(List *L){
    infotype P;
    while (!listempty(*L)){
        delvlast(L,&P);
    }
}
void inverselist(List *L){
    address las=Last(*L);
    address P;
    int i=1;
    while (i<nbelmt(*L)){
        delfirst(L,&P);
        insertafter(L,P,las);
        i++;
    }
}
List finverselist(List L){
    List I;
    createList(&I);
    address P=L.first;
    while(P!=NIL){
        insvfirst(&I,P->info);
        P=P->next;
    }
    return I;
}
void copylist(List*L1,List*L2){
    L2->first=L1->first;
}
List fcopylist(List L){
    List C;
    createList(&C);
    address P=L.first;
    while(P!=NIL){
        insvlast(&C,P->info);
        P=P->next;
    }
    return C;
}
void cpaloklist(List Lin,List *Lout){
    address P=Lin.first;
    int b=nbelmt(Lin);
    while (P!=NIL){
        insvlast(Lout,P->info);
        P=P->next;
    }
    if(nbelmt(*Lout)!=b)
        delall(Lout);
}
void konkat (List L1,List L2, List *L3){
    address P=L1.first;
    while(P!=NIL){
        insvlast(L3,P->info);
        P=P->next;
    }
    P=L2.first;
    while(P!=NIL){
        insvlast(L3,P->info);
        P=P->next;
    }
    if(nbelmt(*L3)!=(nbelmt(L1)+nbelmt(L2)))
        delall(L3);
}
void konkat1 (List *L1,List *L2,List *L3){
    int i=0;
    address a;
    while (i<(nbelmt(*L1))){
        delfirst(L1,&a);
        insertfirst(L3,a);
    }
    i=0;
    while (i<(nbelmt(*L2))){
        delfirst(L2,&a);
        insertfirst(L3,a);
    }
}
void pecahlist (List *L1, List *L2,List L){
    address P=L.first;
    int i;
    for(i=1;i<=nbelmt(L);i++){
        if (i<=(nbelmt(L)/2)){
            insvlast(L1,P->info);
        }
        else{
            insvlast(L2,P->info);
        }
        P=P->next;
    }
}
address sequential_search_terurut(List L,address X){
    boolean found=false;
    address P= L.first;
    while((P->info<=X->info)&&(!found)){
        if(P->info==X->info){
            found =true;
        }
        else{
        P=P->next;
        }
    }
    if (found){
        return P;
    }
    else{
        return NIL;
    }
}
address sequential_search_terurut_sentinel(List L,infotype X){
    insvlast(&L,X);
    address P= L.first;
    boolean found=false;
    int i=0;
    while((P->info<=X)&&(!found)){
        if(P->info==X){
            found =true;
        }
        else{
            P=P->next;
            i++;
        }
    }
    infotype x;
    delvlast(&L,&x);
    return i<=nbelmt(L)? P:NIL;
}
void multirember(List *L){
    address P=L->first;
    List K;
    while(P!=NIL){
        K.first=P->next;
        if(Search(K,P->info)){
            delpe(&K,P->info);
        }
        P->next=K.first;
        if (P->next!=NIL){
            P->next->prev=P;
        }
        P=P->next;
    }
}
address Last(List L){
    if (listempty(L)){
        return NIL;
    }
    else{
        address A=L.first;
        while (A->next!=NIL){
            A=A->next;
        }
        return A;
    }
}
int indexaddr(List L,address P){
    if(fsearch(L,P)){
        int k=0;
        boolean found=false;
        address T=L.first;
        while(T!=NIL&&!found){
            k++;
            if(T==P){
                found=true;
            }
            T=T->next;

        }
        return k;
    }
    return 0;
}
address gotoindex(List L,int index){
    address P=L.first;
    while (index!=1){
        P=P->next;
        index--;
    }
    return P;
}
int hitungkata(List L){
    address P=L.first;
    int x=0;
    while (P->next!=NIL){
        if((P->info>='a'&&P->info<='z')||(P->info>='A'&&P->info<='Z')){
            if(P->next->info== ' '){
                x++;
            }
        }
        P=P->next;
    }
    if((P->info>='a'&&P->info<='z')||(P->info>='A'&&P->info<='Z'))
        return x+1;
    else return x;
}
