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
        cout << "Error: Bis tidak valid" << endl;
        return;
    }
    if (p == nullptr) {
        cout << "Error: Penumpang tidak valid" << endl;
        return;
    }

    if (bis->firstPenumpang == nullptr) {
        bis->firstPenumpang = p;
        p->prev = nullptr;
        p->next = nullptr;
        cout << "Penumpang berhasil ditambahkan sebagai penumpang pertama" << endl;
    } else {
        adrPenumpang last = bis->firstPenumpang;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = p;
        p->prev = last;
        p->next = nullptr;

        cout << "Penumpang berhasil ditambahkan di akhir list" << endl;
    }

}

void deletePenumpangFirst(adrBis &bis, adrPenumpang &p) {
    if (bis == nullptr) {
        p = nullptr;
        cout << "Error: Bis tidak valid" << endl;
        return;
    } else if (bis->firstPenumpang == nullptr) {
        p = nullptr;
        cout << "Tidak ada penumpang di bis " << bis->info.idBis << endl;
        return;
    } else {
        p= bis->firstPenumpang;
        bis->firstPenumpang = p->next;
            if (bis->firstPenumpang != nullptr) {
                bis->firstPenumpang->prev = nullptr;
            }
        p->next = nullptr;
        p->prev = nullptr;
    }
    cout << "Penumpang " << p->info.nama
         << " berhasil dihapus dari bis " << bis->info.idBis << endl;
}
void deletePenumpangAfter(adrBis &bis, adrPenumpang prec, adrPenumpang &p) {

    if (bis == nullptr) {
        p = nullptr;
        cout << "Bis tidak ditemukan" << endl;
        return;
    } else if (prec == nullptr) {
        p = nullptr;
        cout << "Elemen sebelumnya tidak valid" << endl;
        return;
    } else if (prec->next == nullptr) {
        p = nullptr;
        cout << "Tidak ada elemen setelah elemen tersebut" << endl;
        return;
    } else {
        p = prec->next;
        prec->next = p->next;
            if (p->next != nullptr) {
                p->next->prev = prec;
            }
        p->next = nullptr;
        p->prev = nullptr;
    }
    cout << "Penumpang setelah elemen berhasil dihapus" << endl;
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

void deleteAllPenumpang(ListBis &L, string idBis){
    adrPenumpang temp, q;
    adrBis p;
    int jumlah;

    p = findBisById(L, idBis);
    if (p == nullptr) {
        cout << "Bis tidak ditemukan" << endl;
        return;
    }

    if (p->firstPenumpang == nullptr) {
        cout << "Tidak ada penumpang" << endl;
        return;
    }

    q = p->firstPenumpang;
    jumlah = 0;

    while (q != nullptr) {
        temp = q;
        q = q->next;
        delete temp;
        jumlah++;
    }

    p->firstPenumpang = nullptr;
    cout << "Berhasil menghapus " << jumlah << " penumpang" << endl;
}

int countPenumpang(ListBis L){
    int count;
    adrPenumpang p;
    adrBis bisTarget;
    string tujuan;

    count = 0;
    cout << "Masukkan Bis dengan tujuan yang ingin dihitung penumpangnya: "; cin >> tujuan;
    bisTarget = findBisByTujuan(L, tujuan);
    if (bisTarget == nullptr) {
        cout << "Bis dengan tujuan " << tujuan << " tidak ditemukan." << endl;
    }
    p = bisTarget->firstPenumpang;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}


void adminInsertLastPenumpang(ListBis &L) {
    cout << "\n=== INSERT LAST PENUMPANG ===\n";
    displayBis(L);
    string idBis;
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    // Cari bis
    adrBis bis = findBisById(L, idBis);
    if (bis == nullptr) {
        cout << "Bis " << idBis << " tidak ditemukan!\n";
        return;
    }

    // Input data penumpang
    adrPenumpang P = inputDataPenumpang();

    // Insert ke akhir list penumpang di bis tersebut
    insertPenumpangLast(bis, P);

    cout << "\nPenumpang " << P->info.nama << " berhasil ditambahkan di bis " << idBis << "!\n";
}

void adminDeleteFirstPenumpang(ListBis &L) {
    cout << "\n=== DELETE FIRST PENUMPANG ===\n";
    string namaPenumpang;
    string idBis;
        displayBis(L);
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
        displayBis(L);
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
    displayPenumpang(bis->firstPenumpang);
    string idSebelum;
    cout << "ID Tiket Penumpang Sebelumnya: ";
    cin >> idSebelum;

    adrPenumpang Prec = bis->firstPenumpang;
    while (Prec != nullptr && Prec->info.idtiket != idSebelum) {
        Prec = Prec->next;
    }

    if (Prec == nullptr) {
        cout << "Penumpang dengan ID Tiket " << idSebelum << " tidak ditemukan!\n";
        return;
    }

    if (Prec->next == nullptr) {
        cout << "Tidak ada penumpang setelah " << idSebelum << "!\n";
        return;
    }
    string namaPenumpang = Prec->next->info.nama;
    string idTiket = Prec->next->info.idtiket;
    adrPenumpang P;
    deletePenumpangAfter(bis, Prec, P);

    cout << "\nPenumpang " << namaPenumpang << " (ID: " << idTiket << ") berhasil dihapus dari bis " << idBis << "!\n";
}
