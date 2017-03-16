#include "Double Link List.h"
#include "getch.h"
char b;
int x=1;
int y=1;
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1b,y,x);
}

int menu(List *L){
    system("clear");
    address activate = L->first;
    int x=1;
    int y=2;
    address M;
    gotoxy(30,0);
    printf("terminal notepad\n");
    gotoxy(1,23);
    printf("Activate : X");
    gotoxy(1,22);
    printf("X : %d",x);
    gotoxy(1,2);
    printinfo(*L);
    gotoxy(x,2);
    while(b!='~'){
        system("clear");
        gotoxy(30,0);
        printf("terminal notepad\n");
        gotoxy(1,23);
        if(activate!=NIL)printf("Activate : %c",activate->info);
        gotoxy(1,22);
        printf("X : %d",x);
        gotoxy(1,2);
        printinfo(*L);
        gotoxy(x,y);
        b=getch();
        switch(b) {
            case '\033':  // if the first value is esc
                if (!listempty(*L)){
                    getch(); // skip the [
                    switch(getch()) { // the real value
                        case 'A':
                        // code for arrow up
                            break;
                        case 'B':
                        // code for arrow down
                            break;
                        case 'C':
                        // code for arrow right
                            if(activate->next!=NIL&&!listempty(*L)){
                                x++;
                                activate=gotoindex(*L,x+(80*(y-2)));
                            }
                            break;
                        case 'D':
                        // code for arrow left
                            if(activate->prev!=NIL&&!listempty(*L)){
                                x--;
                                activate=gotoindex(*L,x+(80*(y-2)));
                            }
                            break;
                    }
                }
                break;
            case '\n':
                break;

            case '~':
                break;
            case 127:
                if (activate==NIL){

                }
                else if (activate!=L->first){
                    delprev(L,&M,activate);
                    if(y>1)if(x>=1)x--;
                }
                else{
                    delfirst(L,&M);
                    if (!listempty(*L))
                    activate=L->first;
                }
                break;
            case '`':
                if(activate!=Last(*L)){
                    delafter(L,&M,activate);
                }
                else{
                    if (activate!=L->first){
                        activate=activate->prev;
                        delafter(L,&M,activate);
                        x--;
                    }
                    else{
                        delfirst(L,&M);
                    }
                }
                break;
            default:
                if(listempty(*L)){
                    insertfirst(L,alokasi(b));
                    activate=L->first;
                }
                else{
                    insertafter(L,alokasi(b),activate);
                    activate =activate->next;
                    x++;
                }
        }
        if (x>80){
            x=1;
            y++;
        }
        if (x<1&&y>2){
            x=80;
            y--;
        }
        else if (x<1&&y==2){
            x=1;
        }
    }
    return 0;
}
void save(FILE *b,List L){
    address P=L.first;
    while(P!=NIL){
        fprintf(b,"%c",P->info);
        P=P->next;
    }
    printf("document saved\n");
}
void load(List *L,FILE *b){
    char c;
    while(1)
   {
      c = fgetc(b);
      if( feof(b) )
      {
         break ;
      }

      insertlast(L,alokasi(c));
      printf("%c", c);
   }
}
