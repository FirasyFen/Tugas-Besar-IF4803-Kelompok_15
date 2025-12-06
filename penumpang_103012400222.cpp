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
    
}

void deletePenumpangLast(adrBis &L, adrPenumpang &p){

}

void ubahPenumpang(adrPenumpang &L, string idtiket, string tujuanBaru){
     adrPenumpang p = L;

    while (p != nullptr) {
        if (p->info.idtiket == idtiket) {
            p->info.tujuan = tujuanBaru;
            return;
        }
        p = p->next;
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
