#include <iostream>
#include "Penumpang.h"
#include "Bis.h"
using namespace std;

adrPenumpang createElemenPenumpang(string nama, string tujuan, string idtiket) {
    adrPenumpang q = new elemenPenumpang;
    q->info.nama = nama;
    q->info.idtiket = idtiket;
    q->next = nullptr;
    q->prev = nullptr;
    return q;
}

bool isEmptyPenumpang(adrPenumpang p) {
    return (p == nullptr);
}

void insertPenumpangLast(adrPenumpang &p, adrPenumpang q) {
    if (isEmptyPenumpang(p)) {
        p = q;
    } else {
        adrPenumpang last = p;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = q;
        q->prev = last;
    }
}

void deletePenumpangFirst(adrPenumpang &p, adrPenumpang &q) {
    if (isEmptyPenumpang(p)) {
        q = nullptr;
        cout << "List penumpang kosong" << endl;
    } else {
        q = p;
        p = q->next;
        if (p != nullptr) {
            p->prev = nullptr;
        }
        q->next = nullptr;
        q->prev = nullptr;
    }
}

void deletePenumpangAfter(adrPenumpang prec, adrPenumpang &q) {
    if (prec == nullptr || prec->next == nullptr) {
        q = nullptr;
        cout << "Tidak ada elemen" << endl;
        return;
    }
    q = prec->next;
    prec->next = q->next;
    if (q->next != nullptr) {
        q->next->prev = prec;
    }
    q->next = nullptr;
    q->prev = nullptr;
}

adrPenumpang searchPenumpang(adrPenumpang p, string idtiket) {
    adrPenumpang q = p;
    while (q != nullptr) {
        if (q->info.idtiket == idtiket) {
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void deleteAllPenumpang(adrPenumpang &L){

}

int countPenumpang(adrPenumpang L){

}

void adminInsertLastPenumpang(ListBis &L){

};
void adminInsertAfterPenumpang(ListBis &L){

};
void adminDeleteFirstPenumpang(ListBis &L){
    
};
void adminDeleteLastPenumpang(ListBis &L){
    
};
void adminDeleteAfterPenumpang(ListBis &L){
    
};