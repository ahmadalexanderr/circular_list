/* Program   : mSLLC.c */
/* Deskripsi : file DRIVER modul single linked list circular */
/* NIM/Nama  : 24010316140048/Ahmad Alexander */
/* Tanggal   : 5 November 2020 */
/***********************************/

#include "SLLC.h"

int main(){
    //kamus lokal
    List L1, L2, L3, L4, L5, L6, L7, L8, L9, L10;
    address X, Y, Z, A, B, C, D, E, F, G, H, I;
    int x;

    //algoritma
    //operasi terhadap List A
    CreateList(&L1);
    X = Alokasi(12);
    Y = Alokasi(19);
    Z = Alokasi(23);
    A = Alokasi(7);
    B = Alokasi(4);
    C = Alokasi(75);
    D = Alokasi(68);

    printf("\n\nOperasi Insertion List L1");
    printf("Insert %d at Head List L1\n", A);
    InsertFirst(&L1, A);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d at Head List L1\n", B);
    InsertFirst(&L1, B);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d at Tail List L1\n", B);
    InsertLast(&L1, C);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d after %d at List L1\n", X, A);
    InsertAfter(&L1, X, A);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d after %d at List L1\n", Y, B);
    InsertAfter(&L1, Y, B);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d after %d at List L1\n", Z, X);
    InsertAfter(&L1, Z, X);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d at Head List L1\n", 18);
    InsertVFirst(&L1, 18);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d at Head List L1\n", 100);
    InsertVFirst(&L1, 100);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d at Tail List L1\n", 71);
    InsertVLast(&L1, 71);
    Printinfo(L1);
    printf("\n");
    printf("\nInsert %d at Tail List L1\n", 82);
    InsertVLast(&L1, 82);
    Printinfo(L1);
    printf("\n");
    printf("\nChecking if List is L1 empty\n");
    if(ListEmpty(L1)==1){
        printf("List Is Empty!\n");
    }else{
        printf("List Is NOT Empty!\n");
    }
    printf("\nSearching Element %d on List L1\n", 75);
    Search(L1, 75);
    printf("\nSearching Element %d on List L1\n", 23);
    Search(L1, 23);
    printf("\nIs address %d on List L1?\n", X);
    if (FSearch(L1, X)==1){
        printf("Address %d Found on List L1\n", X);
    }else{
        printf("Address %d Not Found List L1\n", X);
    }
    printf("\nIs address %d on List L1?\n", D);
    if (FSearch(L1, D)==1){
        printf("Address %d Found on List L1\n", D);
    }else{
        printf("Address %d Not Found List L1\n", D);
    }
    printf("\nSearching Predecessor Address of %d on List L1:\n",19);
    SearchPrec(L1, 19, &B);
    printf("\nSearching Predecessor Address of %d on List L1:\n",23);
    SearchPrec(L1, 23, &X);
    printf("\n");
    Printinfo(L1);
    printf("\nAmout of Element List L1 = %d\n", NbElmt(L1));
    printf("\nInsert address %d at List L1 after address %d", D, X);
    InsertAfter(&L1, D, X);
    printf("\nAmout of Element List L1 after insertion %d = %d\n", D,NbElmt(L1));
    printf("Average element value in List L1 equals %d\n\n", Average(L1));
    printf("List L1 before inversion\n");
    Printinfo(L1);
    InverstList(&L1);
    printf("\n\nList L1 after inversion\n");
    Printinfo(L1);

    printf("\n\nOperasi List L2\n");
    CreateList(&L2);
    D = Alokasi(90);
    E = Alokasi(10);
    F = Alokasi(20);
    G = Alokasi(40);
    H = Alokasi(60);
    I = Alokasi(70);
    InsertFirst(&L2, F);
    InsertFirst(&L2,E);
    InsertLast(&L2, I);
    InsertAfter(&L2, G, F);
    InsertAfter(&L2, H, G);
    InsertAfter(&L2, D, I);
    Printinfo(L2);
    printf("\n\nMaximum address in List L2 equals %d\n", AdrMax(L2));
    printf("Maximum element value in List L2 equals %d\n", Max(L2));
    printf("Minimum address in List L2 equals %d\n", AdrMin(L2));
    printf("Minimum element value in List L2 equals %d\n", Min(L2));
    printf("\nInvers List L2 = %d", FInversList(L2));

    printf("\nMengcopy List L2 ke List L3 = ");
    CopyList(&L2, &L3);
    Printinfo(L3);
    printf("\nFcopy List L2 ke L9 = " );
    L9 = FCopyList(L2);
    Printinfo(L9);
    printf("\nFInvers List L2 ke L10 = " );
    L10 = FInversList(L2);
    Printinfo(L10);

    printf("\n\nKonkat L1 dan L2 ke L4 = ");
    Konkat(L1, L2, &L4);

    Printinfo(L4);

    printf("\n\nPecah List L4 menjadi L5 dan L6\n");
    CreateList(&L5);
    CreateList(&L6);
    PecahList(&L5, &L6, &L4);
    printf("List L5 = ");
    Printinfo(L5);
    printf("\nList L6 = ");
    Printinfo(L6);

    printf("\n\nCPalokasi L3 Ke L7 = ");
    CpAlokList(L3, &L7);
    Printinfo(L7);

    printf("\n\nKonkat1 L6 dan L7 lagi ke L8, namun hapus L6 dan L5 = ");
    CreateList(&L8);
    Konkat1(&L6, &L7, &L8);
    Printinfo(L8);

    printf("\n\n Deletion List L1\n");
    Printinfo(L1);
    printf("\nDelete 82\n");
    x = 82;
    DelVFirst(&L1, &x);
    Printinfo(L1);
    printf("\nDelete 71\n");
    x = 71;
    DelVFirst(&L1, &x);
    Printinfo(L1);
    printf("\nDelete 100\n");
    x = 100;
    DelVLast(&L1, &x);
    Printinfo(L1);
    printf("\nDelete 100\n");
    x = 18;
    DelVLast(&L1, &x);
    Printinfo(L1);
    printf("\nDelete 75\n");
    DelFirst(&L1, &C);
    Printinfo(L1);
    printf("\nDelete 4\n");
    DelLast(&L1, &B);
    Printinfo(L1);
    printf("\nDelete 7 AFTER 12\n");
    DelAfter(&L1, &A, X);
    Printinfo(L1);
    printf("\nDelete 68 AFTER 23\n");
    DelAfter(&L1, &D, Z);
    Printinfo(L1);
    printf("\nDelete All\n");
    DelAll(&L1);
    if (ListEmpty(L1)==1){
        printf("List L1 is now empty!");
    }
    return 0;
}