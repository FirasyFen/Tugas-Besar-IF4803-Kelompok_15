#include "main.h"
#include <iostream>
using namespace std;

void insertFirstBis(ListBis &L, adrBis P){
    if (isEmpty(L)){
        L.first = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}

void insertAfterBis(ListBis &L, adrBis Prec, adrBis P){
    if (isEmpty(L)){
        L.first = P;
    }else if(L.first->next == nullptr){
        L.first->next = P;
    }else{
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteLastBis(ListBis &L, adrBis &P){
    adrBis Q = L.first;
    if(isEmpty(L)){
        P = nullptr;
    }else if(L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
    }else{
        while (Q->next->next != nullptr){
            Q->next = Q;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void displayBis(ListBis L){
    adrBis P = L.first;
    while (P != nullptr){
        cout << "ID Bis      : " << P->info.idBis << endl;
        cout << "Kapasitas   : " << P->info.kapasitas << endl;
        cout << "Rute      : " << P->info.rute << endl;
        cout << "-----------------------------" << "\n" << endl;

        P = P->next;
    }
}

bool isEmpty(ListBis L){
    return L.first == nullptr;
}

adrBis findBisByRute(ListBis L, string rute) {
    adrBis P = L.first;
    while (P != nullptr) {
        if (P->info.rute == rute) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

adrBis userFindBisByRute(ListBis L) {
    string rute;
    cout << "Masukkan rute: ";
    cin >> rute;

    adrBis P = findBisByRute(L, rute);

    if (P != nullptr) {
        cout << "Bis ditemukan!\n";
        cout << "ID Bis     : " << P->info.idBis << endl;
        cout << "Kapasitas  : " << P->info.kapasitas << endl;
        cout << "Rute       : " << P->info.rute << endl;
    } else {
        cout << "Tidak ada Bis dengan rute '" << rute << "'\n";
    }

    return P;
}

adrBis userFindBisById(ListBis L) {
    string idBis;
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    adrBis P = findBisById(L, idBis);

    if (P != nullptr) {
        cout << "Bis ditemukan!\n";
        cout << "------------------------\n";
        cout << "ID Bis     : " << P->info.idBis << endl;
        cout << "Kapasitas  : " << P->info.kapasitas << endl;
        cout << "Rute       : " << P->info.rute << endl;
        cout << "------------------------\n";
    } else {
        cout << "Tidak ada Bis dengan ID '" << idBis << "'\n";
    }

    return P;
}


