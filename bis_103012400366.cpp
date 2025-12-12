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
void deleteAfterBis(ListBis &L, adrBis Prec, adrBis &P) {
    if (isEmpty(L)) {
        P = nullptr;
        cout << "List kosong" << endl;
        return;
    }

    if (Prec == nullptr) {
        P = nullptr;
        cout << "Prec tidak valid" << endl;
        return;
    }

    if (Prec->next == nullptr) {
        P = nullptr;
        cout << "Tidak ada elemen setelah Prec" << endl;
        return;
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

void adminInsertFirstBis(ListBis &L) {
    adrBis P;
    cout << "\n=== INSERT FIRST BIS ===\n";
    P = inputBisData();
    insertFirstBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil ditambahkan di awal!\n";
}

void adminInsertLastBis(ListBis &L) {
    adrBis P;
    cout << "\n=== INSERT LAST BIS ===\n";
    P = inputBisData();
    insertLastBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil ditambahkan di akhir!\n";
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

void adminDeleteFirstBis(ListBis &L) {
    adrBis P;
    cout << "\n=== DELETE FIRST BIS ===\n";

    if (isEmpty(L)) {
        cout << "Tidak ada bis yang bisa dihapus. List kosong!\n";
        return;
    }
    deleteFirstBis(L, P);
    cout << "\nBis " << P->info.idBis << " berhasil dihapus!\n";
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

void adminDeleteAfterBis(ListBis &L) {
    cout << "\n=== DELETE AFTER BIS ===\n";

    if (isEmpty(L)) {
        cout << "Tidak ada bis yang bisa dihapus. List kosong!\n";
        return;
    }

    string idSebelum;
    cout << "ID Bis Sebelumnya : ";
    cin >> idSebelum;

    adrBis Prec = findBisById(L, idSebelum);
    if (Prec == nullptr) {
        cout << "Bis " << idSebelum << " tidak ditemukan!\n";
        return;
    }

    if (Prec->next == nullptr) {
        cout << "Tidak ada bis setelah " << idSebelum << "!\n";
        return;
    }

    adrBis P;
    deleteAfterBis(L, Prec, P);
    cout << "\nBis " << P->info.idBis << " berhasil dihapus!\n";
}

adrBis inputBisData() {
    string id, tujuan;
    adrBis P;
    int kapasitas;
    cout << "ID Bis     : ";
    cin >> id;
    cout << "Kapasitas  : ";
    cin >> kapasitas;
    cout << "Tujuan     : ";
    cin >> tujuan;
    P = createElmBis(id, kapasitas, tujuan);
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
