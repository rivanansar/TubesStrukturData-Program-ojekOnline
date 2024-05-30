#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include "stdlib.h"

using namespace std;

#define info(P) (P)->info
#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define pesanan(P) (P)->pesanan
#define penumpang(P) (P)->penumpang
#define Prestasi(P) (P)->Prestasi

typedef struct elmOjol *adrOjol;
typedef struct elmPenumpang *adrPenumpang;
typedef struct elmPesanan *adrPesanan;


// ADT OJOL
struct Ojol {
    string idOjol;
    string nama;
};

struct elmOjol {
    Ojol info;
    adrOjol next;
    adrOjol prev;
    adrPesanan pesanan;
};

struct CDLLOjol{
    adrOjol first;
    adrOjol last;
};
// ADT OJOL


// ADT PENUMPANG
struct Penumpang {
    string idPenumpang;
    string nama;
};

struct elmPenumpang {
    Penumpang info;
    adrPenumpang next;
    adrPenumpang prev;
};

struct DLLPenumpang{
    adrPenumpang first;
    adrPenumpang last;
};
// ADT PENUMPANG


//ADT PESANAN
struct Pesanan{
    string idPesanan;
    string tanggal;
    string idPenumpang;
    string idOjol;
};;

struct elmPesanan {
    Pesanan info;
    adrPenumpang penumpang;
    adrPesanan next;
};
// ADT PESANAN

//Method Ojol
void createList_Ojol(CDLLOjol &ListOjol);
adrOjol new_elmOjol(string idOjol, string nama);
void insertLast_Ojol(CDLLOjol &ListOjol, adrOjol p); //Insert data ojol dari belakang (5)
void deleteFirst_Ojol(CDLLOjol &ListOjol, adrOjol &p);
void deleteLast_Ojol(CDLLOjol &ListOjol, adrOjol &p);
void deleteAfter_Ojol(CDLLOjol &ListOjol, adrOjol prec, adrOjol &p);
void delete_Ojol(CDLLOjol &ListOjol, string idOjol, adrOjol &p); //Menghapus data ojol beserta relasinya (15)
adrOjol search_Ojol(CDLLOjol ListOjol, string idOjol); //Mencari data ojol (5)
void show_Ojol(CDLLOjol ListOjol); //Show all data ojol (5)
//Method Ojol


//Method Penumpang
void createList_Penumpang(DLLPenumpang &ListPenumpang);
adrPenumpang new_elmPenumpang(string idPenumpang, string nama);
void insertLast_Penumpang(DLLPenumpang &ListPenumpang, adrPenumpang p); //Menambahkan data penumpang (5)
adrPenumpang search_Penumpang(DLLPenumpang &ListPenumpang, string idPenumpang); //Mencari data penumpang (5)
//Method Penumpang


//Method Pesanan
void insertPesanan(CDLLOjol &ListOjol, DLLPenumpang ListPenumpang, adrPesanan p); //Menghubungkan data ojol ke data penumpang (5)
adrPesanan new_elmPesanan(string idPesanan, string tanggal, string idOjol, string idPenumpang) ;
void showAllPesanan(CDLLOjol ListOjol); //Menampilkan seluruh data ojol beserta penumpangnya (15)
void showPesanan(CDLLOjol ListOjol, string idOjol); //Mencari data penumpang pada ojol tertentu (10)
void deleteFirst_Pesanan(CDLLOjol &ListOjol, adrOjol ojol, adrPesanan &p);
void deleteLast_Pesanan(CDLLOjol &ListOjol, adrOjol ojol, adrPesanan &p);
void deleteAfter_Pesanan(CDLLOjol &ListOjol, adrPesanan prec, adrPesanan &p);
void deletePesanan(CDLLOjol &ListOjol, string idPesanan, adrPesanan &p); //Menghapus data penumpang pada ojol tertentu beserta relasinya (15)
void showPesananOnDay(CDLLOjol ListOjol, string idPenumpang, string tanggal); //Menampilkan jumlah ojol yang dipesan seorang penumpang dalam satu hari (5)
//Method Pesanan


#endif // HEADER_H_INCLUDED
