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

void insertLast(ListBis &L, adrBis P) {
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
}

void deleteElmBis(ListBis &L, adrBis &P) {
    adrPenumpang pen;
    if (L.first == nullptr) {
        cout << "List bis kosong." << endl;
        return;
    }
    
    
    pen = P->firstPenumpang;
    while (pen != nullptr) {
        adrPenumpang delPen = pen;
        pen = pen->next;
        delete delPen;
    }
    P->firstPenumpang = nullptr;
    
    if (L.first == P) {
        L.first = P->next;
    } else {
        adrBis Q = L.first;
        while (Q != nullptr && Q->next != P) {
            Q = Q->next;
        }
        if (Q != nullptr) {
            Q->next = P->next;
        }
    }
    delete P;
    P = nullptr;
}

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

void displayBis(ListBis L) {
    adrBis P = L.first;
    int i = 1;
    if (P == nullptr) {
        cout << "Tidak ada data bis." << endl;
    } else {
        while (P != nullptr) {
            cout << i << ". ID Bis: " << P->info.idBis 
                 << " | Kapasitas: " << P->info.kapasitas 
                 << " | Rute: " << P->info.rute << endl;
            P = P->next;
            i++;
        }
    }
}