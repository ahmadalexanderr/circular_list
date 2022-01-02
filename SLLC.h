/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* Program   : SLLC.h */
/* Deskripsi : file Header modul list */
/* NIM/Nama  : 24010316140048 / Ahmad Alexander*/
/* Tanggal   :05 November 2020 */
/***********************************/

#ifndef SLLNC_H
#define SLLNC_H
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "curses.h"
#include "ncurses.h"
#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) ((L).First)

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
    infotype info;
    address next;
} ElmtList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
typedef struct {
    address First;
} List;

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
/* Mengirim true jika list kosong */
boolean ListEmpty (List L);

/****************** PEMBUATAN LIST KOSONG ******************/
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
void CreateList (List * L);

/****************** Manajemen Memori ******************/
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X);

/******************** PENCARIAN SEBUAH ELEMEN LIST ***********************/
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X);

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P);

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */ /* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
address SearchPrec (List L, infotype X, address *Prec);

/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void Dealokasi (address P);

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List * L, address P);

/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List * L, address P, address Prec);

/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List * L, address P);

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelFirst (List * L, address *P);

/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelP (List * L, infotype X);

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelLast (List * L, address * P);

/* I.S. List tidak kosong. Prec adalah anggota list */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List * L, address * Pdel, address Prec);

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsertVFirst (List * L, infotype X);

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsertVLast (List * L, infotype X);

/*prosedur untuk menambah databaru sebagai elemen list setelah nilai elemen*/
//void InsertVAfter(List * L, infotype X, infotype Y);

/*** PENGHAPUSAN ELEMEN ***/
/* I.S. List L tidak kosong */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/* dan alamat elemen pertama di-dealokasi */
void DelVFirst (List * L, infotype * X);

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/* dan alamat elemen terakhir di-dealokasi */
void DelVLast (List * L, infotype * X);

/*prosedur menghapus satu elemen list setelah elemen masukan */
//void DelVAfter(List * L, infotype * X, infotype Y);

/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, */
/* Semua info yg disimpan pada elemen list diprint */
/* Jika list kosong, hanya menuliskan "list kosong" */
void Printinfo (List L);

/*Mengirimkan banyaknya elemen list;mengirimkan 0 jika list kosong */
/*** Prekondisi untuk Max/Min/rata-rata :List tidak kosong ****/
int NbElmt(List L);

/*** Prekondisi untuk Max/Min/rata-rata :List tidak kosong ****/
/* Mengirimkan nilai info(P) yang maksimum */
infotype Max (List L);

/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */ infotype Min (List L);
/* Mengirimkan nilai info(P) yang minimum */
address AdrMax (List L);

/* Mengirimkan nilai info(P) yang minimum */
infotype Min (List L);

/* Mengirimkan address P, dengan info(P) yang bernilai minimum */ infotype Average (List L);
/* Mengirimkan nilai rata-rata info(P) */
address AdrMin (List L);

/* Mengirimkan nilai rata-rata info(P) */
infotype Average (List L);

/* Delete semua elemen list dan alamat elemen di-dealokasi */
void DelAll (List *L);

/* I.S. sembarang.*/
/* F.S. elemen list dibalik : */
/* elemen terakhir menjadi elemen pertama, dst */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi */
void InverstList (List *L);

/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal */
/* jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FInversList (List L);

/* I.S. L1 sembarang. F.S. L2= L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
void CopyList (List* L1, List * L2 );

/* Mengirimkan list yang merupakan Salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FCopyList (List L );

/* I.S. Lin sembarang. */
/* F.S.Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */ /* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi*/
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal  */
void CpAlokList(List Lin, List * Lout);

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang â€œbaruâ€ */
/* Elemen L3 adalah hasil alokasi elemen yang â€œbaruâ€. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
void Konkat (List L1, List L2, List * L3);

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/*  menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/*  dan L1 serta L2 menjadi list kosong.*/
/*  Tidak ada alokasi/dealokasi pada prosedur ini */
void Konkat1 (List * L1, List * L2, List * L3);

/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
void PecahList (List * L1, List * L2, List * L);
#endif
