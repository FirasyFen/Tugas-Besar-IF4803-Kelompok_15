#include "main.h"
#include <iostream>
using namespace std;

void createListBis(ListBis &L) {
    L.first = nullptr;
}

adrBis createElmBis(string idBis, int kapasitas, string tujuan) {
    adrBis P = new elmBis;
    P->info.idBis = idBis;
    P->info.kapasitas = kapasitas;
    P->info.tujuan = tujuan;
    P->next = nullptr;
    P->firstPenumpang = nullptr;
    return P;
}

void insertLastBis(ListBis &L, adrBis P){
   adrBis Q;
    if (isEmptyBis(L)) {
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
    if (isEmptyBis(L)) {
        P = nullptr;
        cout << "List kosong" << endl;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
};
void deleteAfterBis(ListBis &L, adrBis Prec, adrBis &P) {
    if (isEmptyBis(L)) {
        P = nullptr;
        cout << "List kosong" << endl;
    }

    if (Prec == nullptr) {
        P = nullptr;
        cout << "Prec tidak valid" << endl;
    }

    if (Prec->next == nullptr) {
        P = nullptr;
        cout << "Tidak ada elemen setelah Prec" << endl;
    }

    P = Prec->next;
    Prec->next = P->next;
    P->next = nullptr;
    cout << "Bis " << P->info.idBis << " berhasil dihapus" << endl;
}

adrBis findBisById(ListBis L, string idBis) {
    adrBis P = L.first;
    while (P != nullptr) {
        if (P->info.idBis == idBis) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

adrBis findBisByTujuan(ListBis L, string tujuan) {
    adrBis P = L.first;
    while (P != nullptr) {
        if (P->info.tujuan == tujuan) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void adminInsertLastBis(ListBis &L) {
    adrBis P;
    cout << "\n=== INSERT LAST BIS ===\n";
    P = inputBisData(L);
    insertLastBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil ditambahkan di akhir!\n";
}

void adminDeleteFirstBis(ListBis &L) {
    adrBis P;
    cout << "\n=== DELETE FIRST BIS ===\n";

    if (isEmptyBis(L)) {
        cout << "Tidak ada bis yang bisa dihapus. List kosong!\n";
    }
    deleteFirstBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil dihapus!\n";
}

void adminDeleteAfterBis(ListBis &L) {
    cout << "\n=== DELETE AFTER BIS ===\n";

    if (isEmptyBis(L)) {
        cout << "Tidak ada bis yang bisa dihapus. List kosong!\n";
    }

    string idSebelum;
    cout << "ID Bis Sebelumnya : ";
    cin >> idSebelum;

    adrBis Prec = findBisById(L, idSebelum);
    if (Prec == nullptr) {
        cout << "Bis " << idSebelum << " tidak ditemukan!\n";
    }

    if (Prec->next == nullptr) {
        cout << "Tidak ada bis setelah " << idSebelum << "!\n";
    }

    adrBis P;
    deleteAfterBis(L, Prec, P);
    cout << "\nBis " << P->info.idBis << " berhasil dihapus!\n";
}

adrBis inputBisData(ListBis L) {
    string id, tujuan;
    bool idb = false;
    adrBis P;
    int kapasitas;
    while(idb == false){
        cout << "ID Bis     : ";
        cin >> id;
        if (findBisById(L, id) != nullptr){
            cout << "======Id bis sudah terambil Masukkan id yang berbeda========\n";
        }else{
            cout << "Kapasitas  : ";
            cin >> kapasitas;
            cout << "Tujuan     : ";
            cin >> tujuan;
            P = createElmBis(id, kapasitas, tujuan);
            idb = true;
        }
    }
    return P;
}

bool isFullBis(adrBis bis) {
    if (bis == nullptr){
         return true;
    }

    int count = 0;
    adrPenumpang temp = bis->firstPenumpang;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return (count == bis->info.kapasitas);
}
