#include "getch.h"
#include "Double Link List.h"
#include "menu.h"
#include <unistd.h> //tuk fungsi access
int main(int argc,char *argv[]){
    system("clear");
    List L;
    createList(&L);
    FILE* target;
    if (access(argv[1],F_OK)!=-1){
        target= fopen(argv[1], "r+");
        load(&L,target);
        fclose(target);
        target= fopen(argv[1], "w+");
    }
    else{
        target= fopen(argv[1], "w+");
        printf("creating new file");
    }
    getch();
    fflush(stdin);
    menu(&L);
    system("clear");
    printinfo(L);
    if (access(argv[1],F_OK)!=-1){
        save(target,L);
        fclose(target);
    }
    printf("jumlah kata : %d\n",hitungkata(L));
    getch();
    system("clear");
    return 0;
}
