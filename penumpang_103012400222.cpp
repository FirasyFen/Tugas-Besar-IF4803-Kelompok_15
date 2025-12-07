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
        cout << "Precursor tidak ditemukan!" << endl;
        return;
    }

    p->next = prec->next;
    p->prev = prec;

    if (prec->next != nullptr) {
        prec->next->prev = p;
    }

    prec->next = p;
}

void deletePenumpangLast(adrBis &L, adrPenumpang &p){
    adrPenumpang q = L->firstPenumpang;
    if (isEmptyPenumpang(L)) {
        p = nullptr;
    }else if (q->prev != nullptr) {
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
     while (found != true) {
        if (p->info.idtiket == idtiket) {
            p->info.tujuan = tujuanBaru;
            found = true;
        }
        p = p->next;
    }
    cout << "ID Tiket: " << p->info.idtiket << "\n" << "Tujuan menjadi: " << p->info.tujuan;
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
