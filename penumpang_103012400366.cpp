#include <iostream>
#include "main.h"
using namespace std;

adrPenumpang createElemenPenumpang(string nama, string idtiket) {
    adrPenumpang q = new elemenPenumpang;
    q->info.nama = nama;
    q->info.idtiket = idtiket;
    q->next = nullptr;
    q->prev = nullptr;
    return q;
}

bool isEmptyPenumpang(adrPenumpang L) {
    return (L == nullptr);
}

void insertPenumpangLast(adrBis &bis, adrPenumpang p) {
    if (bis == nullptr) {
        cout << "List Bis tidak ada" << endl;
    }
    if (p == nullptr) {
        cout << "Penumpang tidak ada" << endl;
    }

    if (bis->firstPenumpang == nullptr) {
        bis->firstPenumpang = p;
        p->prev = nullptr;
        p->next = nullptr;
    } else {
        adrPenumpang last = bis->firstPenumpang;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = p;
        p->prev = last;
        p->next = nullptr;
    }
}

void deletePenumpangFirst(adrBis &bis, adrPenumpang &p) {
    if (bis == nullptr) {
        p = nullptr;
        cout << "Bis tidak valid" << endl;
    }
    if (isEmptyPenumpang(bis->firstPenumpang)) {
        p = nullptr;
        cout << "Tidak ada penumpang di bis " << bis->info.idBis << endl;
    }
    p = bis->firstPenumpang;

    if (p->next == nullptr) {
        bis->firstPenumpang = nullptr;
    } else {
        bis->firstPenumpang = p->next;
        bis->firstPenumpang->prev = nullptr;
    }

    p->next = nullptr;
    p->prev = nullptr;
}
void deletePenumpangAfter(adrBis &bis, adrPenumpang prec, adrPenumpang &p) {

    if (bis == nullptr) {
        p = nullptr;
        cout << "Bis tidak ditemukan" << endl;
    } else if (prec->next == nullptr) {
        p = nullptr;
        cout << "Tidak ada elemen setelah elemen tersebut" << endl;
    } else {
        p = prec->next;
        prec->next = p->next;
            if (p->next != nullptr) {
                p->next->prev = prec;
            }
        p->next = nullptr;
        p->prev = nullptr;
    }
}

adrPenumpang searchPenumpang(adrPenumpang p, string idtiket) {
    adrPenumpang q;
    q = p;
    while (q != nullptr) {
        if (q->info.idtiket == idtiket) {
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void deleteAllPenumpang(ListBis &L, string idBis){
    adrPenumpang temp;
    adrBis p;
    p = findBisById(L, idBis);
    if (p == nullptr) {
        cout << "Bis tidak ditemukan" << endl;
    }
    if (p->firstPenumpang == nullptr) {
        cout << "Tidak ada penumpang" << endl;
    }
   while (p->firstPenumpang != nullptr) {
        deletePenumpangFirst(p, temp);
   }
}

int countPenumpang(adrPenumpang L) {
    int count = 0;
    adrPenumpang P = L;

    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}


void adminInsertLastPenumpang(ListBis &L) {
    cout << "\n=== INSERT LAST PENUMPANG ===\n";

    string idBis;
    cout << "Masukkan ID Bis: ";
    cin >> idBis;
    adrBis bis = findBisById(L, idBis);
    if (bis == nullptr) {
        cout << "Bis " << idBis << " tidak ditemukan!\n";
        return;
    }
    adrPenumpang P = inputDataPenumpang();
    insertPenumpangLast(bis, P);
    cout << "\nPenumpang " << P->info.nama << " berhasil ditambahkan di bis " << idBis << "!\n";
}

void adminDeleteFirstPenumpang(ListBis &L) {
    cout << "\n=== DELETE FIRST PENUMPANG ===\n";
    string namaPenumpang;
    string idBis;
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    adrBis bis = findBisById(L, idBis);
    if (bis == nullptr) {
        cout << "Bis " << idBis << " tidak ditemukan!\n";
        return;
    }
    if (bis->firstPenumpang == nullptr) {
        cout << "Tidak ada penumpang di bis " << idBis << "!\n";
        return;
    }
    namaPenumpang = bis->firstPenumpang->info.nama;
    adrPenumpang P;
    deletePenumpangFirst(bis, P);

    cout << "\nPenumpang " << namaPenumpang << "  berhasil dihapus dari bis " << idBis << "!\n";
}

void adminDeleteAfterPenumpang(ListBis &L) {
    cout << "\n=== DELETE AFTER PENUMPANG ===\n";

    string idBis;
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    adrBis bis = findBisById(L, idBis);
    if (bis == nullptr) {
        cout << "Bis " << idBis << " tidak ditemukan!\n";
        return;
    }
    if (bis->firstPenumpang == nullptr) {
        cout << "Tidak ada penumpang di bis " << idBis << "!\n";
        return;
    }

    string idSebelum;
    cout << "ID Tiket Penumpang Sebelumnya: ";
    cin >> idSebelum;

    adrPenumpang Prec = bis->firstPenumpang;
    while (Prec != nullptr && Prec->info.idtiket != idSebelum) {
        Prec = Prec->next;
    }
    if (Prec == nullptr) {
        cout << "Penumpang dengan ID Tiket " << idSebelum << " tidak ditemukan!\n";
    }

    if (Prec->next == nullptr) {
        cout << "Tidak ada penumpang setelah " << idSebelum << "!\n";
    }
    string namaPenumpang = Prec->next->info.nama;
    string idTiket = Prec->next->info.idtiket;
    adrPenumpang P;
    deletePenumpangAfter(bis, Prec, P);
    cout << "\nPenumpang " << namaPenumpang << " (ID: " << idTiket << ") berhasil dihapus dari bis " << idBis << "!\n";
}

void hitungRataRataPenumpang(ListBis L) {
    int hasil;
   adrBis bis;
   int jumlahPenumpang, totalPenumpang, totalBis;
    if (isEmptyBis(L)) {
        cout << "List kosong" <<endl;
    }

    totalPenumpang = 0;
    totalBis = 0;

    bis = L.first;
    while (bis != nullptr) {
        jumlahPenumpang = countPenumpang(bis->firstPenumpang);
        totalPenumpang += jumlahPenumpang;
        totalBis++;
        bis = bis->next;
    }
    hasil = (float)totalPenumpang / totalBis;
    cout << "Rata-rata penumpang setiap bis: " << hasil <<endl;
}
