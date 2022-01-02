/* Program   : SLLC.c */
/* Deskripsi : file BODY modul single linked list circular*/
/* NIM/Nama  : 24010316140048/Ahmad Alexander */
/* Tanggal   : 5 November 2020 */
/***********************************/
#include "SLLC.h"

/***deklarasi body***/
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
    //kamus lokal
    //algoritma
    return First(L) == Nil;
}
/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List * L){
    //kamus lokal
    //algoritma
    First(*L) = Nil;
}
/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
    //kamus lokal
    address P;

    //algoritma
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil){
        info(P) = X;
        next(P) = Nil;
        return P;
    }else{
        return Nil;
    }
}

/************************* PENCARIAN SEBUAH ELEMEN LIST ***********************/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X){
    //kamus lokal
    address temp;

    //algoritma
    temp = First(L);
    while(next(temp)!=First(L)){
        if(info(temp) == X){
            printf("%d -> %d\n", temp, info(temp));
            break;
        }
        temp = next(temp);
    }
}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P){
    //kamus lokal
    address temp;
    int found = 0;

    //algoritma
    temp = First(L);
    while (next(temp) != First(L)){
        if(temp == P){
            found = 1;
            return found;
        }
        temp = next(temp);
    }
}

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Last */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
address SearchPrec (List L, infotype X, address *Prec){
    //kamus lokal
    address temp;

    //algoritma
    temp = First(L);
    if(info(First(L)) == X){
        do{
            temp = next(temp);
        }while(temp!=First(L));
        *Prec = temp;
        printf("Predecessor Address of %d of List %d = %d\n",X, L, &Prec);
    }else{
        while(next(temp)!=First(L)){
            if(info(temp)==X){
                printf("Predecessor Address of %d of List %d = %d\n",X, L, &Prec);
                break;
            }
            *Prec = temp;
            temp = next(temp);
            next(*Prec) = temp;
        }
    }
}

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P){
    //kamus lokal
    //algoritma
    info(P) = 0;
    next(P) = Nil;
    (P) = Nil;
}


/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List * L, address P){
    //kamus lokal
    address last;

    //algoritma
    if (!ListEmpty(*L)){
        last = First(*L);
        while(next(last)!=First(*L)){
            last = next(last);
        }
        next(P) = First(*L);
        First(*L) = P;
        next(last) = First(*L);
    }else{
        First(*L) = P;
        next(First(*L)) = P;
    }
}

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List * L, address P, address Prec) {
    //kamus lokal
    address temp;

    //algoritma
    if(!ListEmpty(*L)){
        if(next(Prec)!=First(*L)){
            next(P) = next(Prec);
            next(Prec) = P;
        }else{
            InsertLast(L,P);
        }
    }else{
        //do nothing
    }
}

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List * L, address P){
    //kamus lokal
    address last;

    //algoritma
    if(!ListEmpty(*L)){
        last = First(*L);
        while(next(last)!=First(*L)){
            last = next(last);
        }
        next(last) = P;
        last = P;
        next(last) = First(*L);
    }else{
        InsertFirst(L,P);
    }

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst (List * L, address *P){
    //kamus lokal
    address last;

    //algoritma
    (*P) = First(*L);
    if (next(*P) != First(*L)){
        last = First(*L);
        do{
            last = next(last);
        }while(next(last)!=First(*L));
        First(*L) = next(First(*L));
        next(last) = First(*L);
    }else{
        First(*L) = Nil;
    }
}

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP (List * L, infotype X){
    //kamus lokal
    address P, prec;

    //algoritma
    if(!ListEmpty(*L)){
        P = First(*L);
        prec = Nil;
        if (info(P) == X){
            DelFirst(L, &P);
        }else{
            while(next(P)!=First(*L) && info(P) != X){
                prec = P;
                P = next(P);
            }
            if (info(P) == X){
                DelAfter(L, &P, prec);
            }
        }
    }
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast (List * L, address * P){
    //kamus lokal
    address last, prec;

    //algoritma
    last = First(*L);
    if (next(last) == First(*L)){
        DelFirst(L,P);
    }else{
        do{
            prec = last;
            last = next(last);
        }while(next(last)!=First(*L));
        (*P) = last;
        (*P) = Nil;
        last = prec;
        next(last) = First(*L);
    }
}

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List * L, address * Pdel, address Prec){
    //kamus lokal
    //algoritma
    *Pdel = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsertVFirst (List * L, infotype X){
    //kamus lokal
    address P;

    //algoritma
    P = Alokasi(X);
    if(P!= First(*L)){
        InsertFirst(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsertVLast (List * L, infotype X){
    //kamus lokal
    address P;

    //algoritma
    P = Alokasi(X);
    InsertLast(L, P);
}

///*prosedur untuk menambah databaru sebagai elemen list setelah nilai elemen*/
/* Tidak disuruh dikerjakan pada file cekList dari Pak Aris */
//void InsertVAfter(List * L, infotype X, infotype Y){
//    //kamus lokal
//    address P, prev, temp;
//    int counter = 1;
//
//    //algoritma;
//    if(!ListEmpty(*L)){
//        P = Alokasi(X);
//        temp = First(*L);
//        while (temp != Nil) {
//            if (info(prev) == Y) {
//                next(P) = next(prev);
//                next(prev) = P;
//                printf("value %d inserted at List %d after value %d\n", X, &L, Y);
//                break;
//            }
//            prev = temp;
//            temp = next(temp);
//            counter++;
//        }
//    }else{
//        printf("List cannot be empty!\n");
//    }
//}

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst (List * L, infotype * X){
    //kamus lokal
    address temp;

    //algoritma
    if (!ListEmpty(*L)) {
        info(temp) = *X;
        DelFirst(L, temp);
    }else{
        //do nothing
    }
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast (List * L, infotype * X){
    //kamus Lokal
    address del;

    //algoritma
    if (!ListEmpty(*L)) {
        info(del) = *X;
        DelLast(L, del);
    }else{
        //do nothing
    }
}

/*prosedur menghapus satu elemen X list setelah elemen Y */
/* Tidak disuruh dikerjakan pada file cekList dari Pak Aris */
//void DelVAfter(List * L, infotype *X, infotype Y){
//    //kamus lokal
//    address del, prev;
//    int counter = 1;
//
//    //algoritma
//    if(!ListEmpty(*L)){
//        prev = First(*L);
//        del = next(First(*L));
//        while(next(prev)!= Nil){
//            if (info(prev) == Y){
//                next(prev) = next(next(prev));
//                info(del) = *X;
//                del = Nil;
//                printf("Value %d deleted from List %d after value %d\n", *X, &L, Y);
//                break;
//            }
//            prev = del;
//            del = next(del);
//            counter ++;
//        }
//    }else{
//        printf("List %d has already been empty!\n", &L);
//    }
//}

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo (List L){
    //kamus lokal
    address P;

    //algoritma
    if (!ListEmpty(L)){
        P = First(L);
        do{
            printf("[%d | %d] -> ", P, info(P));
            P = next(P);
        }while(P != First(L));
    }
}

/*Mengirimkan banyaknya elemen list;mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata :List tidak kosong ****/
int NbElmt(List L){
    //kamus lokal
    address temp;
    int counter = 1;

    //algoritma
    temp = First(L);
    while (next(temp) != First(L)){
        counter++;
        temp = next(temp);
    }
    return counter;
}

/* Mengirimkan info(P) yang bernilai maksimum */
infotype Max (List L){
    //kamus lokal
    address P;
    infotype max;

    //algoritma
    max = info(P);
   do{
       if (info(First(L))>max){
           max = info(First(L));
       }else if(info(P)>max){
           max = info(P);
       }
       P = next(P);
   } while(P!=First(L));
    return max;
}

/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
address AdrMax (List L){
    //kamus lokal
    address P, temp;
    infotype max;

    //algoritma
    max = info(P);
    do{
        if (info(First(L))>max){
            temp = First(L);
        }else if(info(P)>max){
            temp = P;
        }
        P = next(P);
    } while(P!=First(L));
    return temp;
}

/* Mengirimkan nilai info(P) yang minimum */
infotype Min (List L){
    //kamus lokal
    //Kamus Lokal
    address P;      //Address traversal
    infotype min;   //Nilai minimum

    //Algoritma
    P = First(L);
    min = info(P);
    while(next(P) != First(L)){
        P = next(P);
        if(info(P) < min){
            min = info(P);
        }
    }
    return min;
}

/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
address AdrMin (List L){
    address P;      //Address traversal
    address min;    //Address berinfo nilai minimum

    //Algoritma
    P = First(L);
    min = P;
    while(next(P) != First(L)){
        P = next(P);
        if(info(P) < info(min)){
            min = P;
        }
    }
    return min;
}

/* Mengirimkan nilai rata-rata info(P) */
infotype Average (List L){
    //kamus lokal
    address temp;
    int sum;

    //algoritma
    temp = First(L);
    if(!ListEmpty(L)){
        sum = info(temp);
        while(next(temp)!=First(L)){
            temp = next(temp);
            sum = sum + info(temp);
        }
    }else{
        sum = 0;
    }
    return (sum/NbElmt(L));
}

/* Delete semua elemen list dan alamat elemen di-dealokasi */
void DelAll (List *L){
    //kamus lokal
    address del, temp;

    //algoritma
    if(!ListEmpty(*L)){
        del = First(*L);
        temp = next(del);
        while(temp != First(*L)){
            DelFirst(L,del);
            del = temp;
            temp = next(temp);
        }
        DelLast(L, del);
    }else{
        //do nothing
    }
}

/* I.S. sembarang.*/
/* F.S. elemen list dibalik : */
/* elemen terakhir menjadi elemen pertama, dst */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi */
void InverstList (List *L){
    //kamus lokal
    address P,prev,temp;

    //algoritma
    P = First(*L);
    prev = Nil;
    do{
        temp = next(P);
        next(P) = prev;
        prev = P;
        P = temp;
    }while (P!=First(*L));
    next(First(*L)) = prev;
    First(*L) = prev;
}

/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal */
/* jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FInversList (List L){
    //kamus lokal
    List temp;
    address P, Q;

    //algoritma
    CreateList(&temp);
    P = First(L);
    do{
        Q = Alokasi(info(P));
        if(Q != First(L)){
            InsertFirst(&temp, Q);
            P = next(P);
        }else{
            DelAll(&temp);
        }
    }
    while (P != First(L));
    return temp;
}

/* I.S. L1 sembarang. F.S. L2= L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
void CopyList (List* L1, List * L2 ){
    //kamus lokal
    //algoritma
    CreateList(L2);
    First(*L2) = First(*L1);
}

/* Mengirimkan list yang merupakan Salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FCopyList (List L){
    //kamus lokal
    List temp;
    address P, Q;

    //algoritma
    CreateList(&temp);
    P = First(L);
    do{
        Q = Alokasi(info(P));
        if (Q != First(L)) {
            InsertLast(&temp,Q);
            P = next(P);
        }
        else{
            DelAll(&temp);
        }
    }
    while (P != First(L));
    return temp;
}

/* I.S. Lin sembarang. */
/* F.S.Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi*/
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal  */
void CpAlokList(List Lin, List * Lout){
    //kamus lokal
    address P, Q;

    //algoritma
    CreateList(Lout);
    P = First(Lin);
    do{
        Q = Alokasi(info(P));
        if (Q != First(Lin)) {
            InsertLast(Lout,Q);
            P = next(P);
        }
        else{
            DelAll(Lout);
        }
    }
    while (P != First(Lin));
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang baru */
/* Elemen L3 adalah hasil alokasi elemen yang â€œbaruâ€. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
void Konkat (List L1, List L2, List * L3){
    //kamus Lokal
    address P, Q;

    //algoritma
    CreateList(L3);
    if (ListEmpty(L1)) {
        First(*L3) = First(L2);
    }else{
        First(*L3) = First(L1);
        P = First(*L3);
        while (next(P) != First(L1)) {
            P = next(P);
            if (next(P)==Nil){
                Q = First(L2);
                next(P) = Q;
                break;
            }
        }
    }
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/*  menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/*  dan L1 serta L2 menjadi list kosong.*/
/*  Tidak ada alokasi/dealokasi pada prosedur ini */
void Konkat1 (List * L1, List * L2, List * L3){
    //Kamus Lokal
    address last;   //Address traversal sampai menemukan elemen terakhir L1

    //Algoritma
    CreateList(L3);
    if(ListEmpty(*L1)){
        First(*L3) = First(*L2);
        First(*L2) = Nil;
    }
    else{
        First(*L3) = First(*L1);
        last = First(*L1);
        while(next(last) != First(*L1)){
            last = next(last);
        }
        if(!ListEmpty(*L2)){
            next(last) = First(*L2);
            do{
                last = next(last);
            }while(next(last) != First(*L2));
            next(last) = First(*L3);
        }
        else{
            next(last) = First(*L3);
        }
        First(*L1) = Nil;
        First(*L2) = Nil;
    }
}

/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
void PecahList (List * L1, List * L2, List * L){
    //kamus lokal
    address P, Q;
    int counter = 1;

    //algoritma
    int mid = NbElmt(*L)/2;
    P = First(*L);
    do{
        Q = Alokasi(info(P));
        if(counter<=mid){
            if(Q!= First(*L)){
                InsertLast(L1,Q);
                P = next(P);
                counter++;
            }else{
                DelAll(L1);
            }
        }
        else{
            if (Q != First(*L)) {
                InsertLast(L2,Q);
                P = next(P);
                counter++;
            }
            else{
                DelAll(L2);
            }
        }
    }
    while(P != First(*L));
}

