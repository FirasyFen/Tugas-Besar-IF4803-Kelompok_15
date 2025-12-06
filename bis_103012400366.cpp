#include "Bis.h"
#include "Penumpang.h"
#include <iostream>
using namespace std;

void createListBis(ListBis &L) {
    L.first = nullptr;
}

adrBis createElmBis(string idBis, int kapasitas, string rute) {
    adrBis P = new elmBis;
    P->info.idBis = idBis;
    P->info.kapasitas = kapasitas;
    P->info.rute = rute;
    P->next = nullptr;
    P->firstPenumpang = nullptr;
    return P;
}

void insertLastBis(ListBis &L, adrBis P){
   adrBis Q;
    if (L.first == nullptr) {
        L.first = P;
    } else {
        Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
};

void deleteFirstBis(ListBis &L, adrBis &P){
    if (isEmpty(L)) {
        P = nullptr;
        cout << "List kosong" << endl;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
};
void deleteLastBis(ListBis &L, adrBis &P){
    adrBis Q;
    if (isEmpty(L)) {
        P = nullptr;
        cout << "List kosong" << endl;
    }  else if (L.first->next == nullptr) { // hanya 1 elemen
        P = L.first;
        L.first = nullptr;
    } else {
        Q = L.first;
        while (Q->next->next != nullptr){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
};

adrBis findBis(ListBis L, string idBis) {
    adrBis P = L.first;
    while (P != nullptr) {
        if (P->info.idBis == idBis) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}