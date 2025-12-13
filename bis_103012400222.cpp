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
        cout << "Tujuan      : " << P->info.tujuan << endl;
        cout << "-----------------------------" << "\n" << endl;

        P = P->next;
    }
}

bool isEmpty(ListBis L){
    return L.first == nullptr;
}

void bisMasihKosong(ListBis L){
    adrBis p = L.first;
    bool found = false;

    while (p != nullptr) {
        if (countPenumpang(p->firstPenumpang) == 0) {
            cout << "Bis " << p->info.idBis << " Tujuan: " << p->info.tujuan << " masih kosong.\n";
            found = true;
        }
        p = p->next;
    }

    if (!found) {
        cout << "Tidak ada bis yang kosong.\n";
    }
}

void bisPenumpangTerbanyak(ListBis L){
    adrBis p = L.first;
    adrBis maxBis = p;
    int maxCount = countPenumpang(p->firstPenumpang);
    int c = countPenumpang(p->firstPenumpang);

    if (L.first == nullptr) {
        cout << "Tidak ada bis dalam list.\n";
    }else{
        while (p != nullptr) {
            if (c > maxCount) {
                maxCount = c;
                maxBis = p;
            }
            p = p->next;
        }
        cout << "Bis dengan penumpang terbanyak adalah id bis" << maxBis->info.idBis << " dengan penumpang " << maxCount << " penumpang" << endl;
    }
}

void adminInsertFirstBis(ListBis &L) {
    adrBis P;
    cout << "\n=== INSERT FIRST BIS ===\n";
    P = inputBisData();
    insertFirstBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil ditambahkan di awal!\n";
}

void adminInsertAfterBis(ListBis &L) {
    adrBis Prec;
    string idSebelum;
    adrBis P;
    cout << "\n=== INSERT AFTER BIS ===\n";
    displayBis(L);
    cout << "masukkan ID Bis yang ingin ditambahkan setelahnya: ";
    cin >> idSebelum;
    Prec = findBisById(L, idSebelum);
    if (Prec == nullptr) {
        cout << "Bis " << idSebelum << " tidak ditemukan!\n";
        return;
    }
    cout << "\n-- Data Bis Baru --\n";
    P = inputBisData();
    insertAfterBis(L, Prec, P);
    cout << "\nBis " << P->info.idBis << " berhasil ditambahkan!\n";
}

void adminDeleteLastBis(ListBis &L) {
    cout << "\n=== DELETE LAST BIS ===\n";

    if (isEmpty(L)) {
        cout << "Tidak ada bis yang bisa dihapus. List kosong!\n";
        return;
    }

    adrBis P;
    deleteLastBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil dihapus!\n";
}

void bisPenumpangTerkecil(ListBis L){
    adrBis p = L.first;
    adrBis minBis = p;
    int minCount = countPenumpang(p->firstPenumpang);

    int c = countPenumpang(p->firstPenumpang);
      if (L.first == nullptr) {
        cout << "Tidak ada bis dalam list.\n";
        return;
    }else{
        while (p != nullptr) {
            if (c < minCount) {
                minCount = c;
                minBis = p;
            }
            p = p->next;
        }

        cout << "Bis dengan penumpang paling sedikit adalah id bis " << minBis->info.idBis << " dengan penumpang " << minCount << " penumpang" << endl;
    }
}

bool isFullKapasitas(adrBis L){
    if (L == nullptr){
        return false;
    }
    return countPenumpang(L->firstPenumpang) >= L->info.kapasitas;
}

adrBis userFindBisByTujuan(ListBis L) {
    string tujuan;
    cout << "Masukkan Tujuan: ";
    cin >> tujuan;

    adrBis P = findBisByTujuan(L, tujuan);

    if (P != nullptr) {
        cout << "Bis ditemukan!\n";
        cout << "ID Bis     : " << P->info.idBis << endl;
        cout << "Kapasitas  : " << P->info.kapasitas << endl;
        cout << "tujuan       : " << P->info.tujuan << endl;
    } else {
        cout << "Tidak ada Bis dengan tujuan '" << tujuan << "'\n";
    }

    return P;
}

adrBis userFindBisById(ListBis L) {
    string idBis;
    adrBis P = findBisById(L, idBis);
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    if (P != nullptr) {
        cout << "Bis ditemukan!\n";
        cout << "------------------------\n";
        cout << "ID Bis     : " << P->info.idBis << endl;
        cout << "Kapasitas  : " << P->info.kapasitas << endl;
        cout << "Tujuan       : " << P->info.tujuan << endl;
        cout << "------------------------\n";
    } else {
        cout << "Tidak ada Bis dengan ID '" << idBis << "'\n";
    }

    return P;
}




