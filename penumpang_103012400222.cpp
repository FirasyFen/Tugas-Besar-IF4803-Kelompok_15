#include <iostream>
#include "Penumpang.h"
#include "Bis.h"
using namespace std;
void insertPenumpangFirst(adrBis &L, adrPenumpang p){
    if (isEmptyPenumpang(L)) {
        L->firstPenumpang = p;
        p->next = nullptr;
        p->prev = nullptr;
    } else {
        p->next = L->firstPenumpang;
        p->prev = nullptr;
        L->firstPenumpang->prev = p;
        L->firstPenumpang = p;
    }
}

void insertPenumpangAfter(adrBis &L, adrPenumpang prec, adrPenumpang p){
     if (prec == nullptr) {
        cout << "list kosong" << endl;
    } else {
        p->next = prec->next;
        p->prev = prec;

        if (prec->next != nullptr) {
            prec->next->prev = p;
        }

        prec->next = p;
    }
}

void deletePenumpangLast(adrBis &L, adrPenumpang &p){
    adrPenumpang q = L->firstPenumpang;
    if (isEmptyPenumpang(L)) {
        cout << "Tidak ada penumpang." << endl;
    } else if (q->prev != nullptr) {
        while (q->next != nullptr) {
            q = q->next;
        }
        p = q;
        q->prev->next = nullptr;
    } else {
        L->firstPenumpang = nullptr;
    }
}

void ubahPenumpang(adrPenumpang &L, string idtiket, string tujuanBaru){
    adrPenumpang p = L;
    bool found = false;

    while (p != nullptr && found == false) {
        if (p->info.idtiket == idtiket) {
            p->info.tujuan = tujuanBaru;
            found = true;
        }
        else {
            p = p->next;
        }
    }
    if (found == true) {
        cout << "ID Tiket: " << idtiket 
             << "\nTujuan berhasil diubah menjadi: " 
             << tujuanBaru << endl;
    } else {
        cout << "Penumpang dengan ID tiket " << idtiket 
             << " tidak ditemukan!" << endl;
    }
}

void displayPenumpang(adrPenumpang L){
    adrPenumpang p = L;

    while (p != nullptr) {
        cout << "ID Tiket: " << p->info.idtiket << endl;
        cout << " Tujuan " << p->info.tujuan << endl;
        p = p->next;
    }
}

bool isEmptyPenumpang(adrBis L){
    return L->firstPenumpang == nullptr;
}

void displayPenumpangTujuan(adrPenumpang L, string tujuan){
    adrPenumpang p = L;

    while (p != nullptr) {
        if (p->info.tujuan == tujuan) {
            cout << p->info.idtiket << " - " << p->info.tujuan << endl;
        }
        p = p->next;
    }
}
