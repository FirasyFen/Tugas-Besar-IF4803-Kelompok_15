#include <iostream>
#include "main.h"
using namespace std;
void insertPenumpangFirst(adrBis &L, adrPenumpang p){
    if (isEmptyPenumpang(L->firstPenumpang)) {
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
     if (prec == nullptr) {
        cout << "list kosong" << endl;
    } else {
        p->next = prec->next;
        p->prev = prec;

        if (prec->next != nullptr) {
            prec->next->prev = p;
        }

        prec->next = p;
    }
}

void deletePenumpangLast(adrBis &L, adrPenumpang &p){
    adrPenumpang q = L->firstPenumpang;
    if (isEmptyPenumpang(L->firstPenumpang)) {
        cout << "Tidak ada penumpang." << endl;
    } else if (q->prev != nullptr) {
        while (q->next != nullptr) {
            q = q->next;
        }
        p = q;
        q->prev->next = nullptr;
    } else {
        L->firstPenumpang = nullptr;
    }
}

void displayPenumpang(adrPenumpang L){
    adrPenumpang p = L;
    cout << "\n========== DATA PENUMPANG ===========\n";
    while (p != nullptr) {
        cout << "======================================\n";
        cout << "ID Tiket: " << p->info.idtiket << endl;
        cout << " Nama: " << p->info.nama << endl;
        cout << "======================================\n";
        p = p->next;
    }
}

bool isEmptyPenumpang(adrBis L){
    return L->firstPenumpang == nullptr;
}

void adminInsertFirstPenumpang(ListBis &L){
    string idBis;
    cout << "\n=== INSERT FIRST PENUMPANG ===\n";
    cout << "Masukkan ID Bis: ";
    cin >> idBis;
    adrBis B = findBisById(L, idBis);
        if (!isFullKapasitas(B)){
                if (B == nullptr){
                    cout << "Bis tidak ditemukan!\n";
                }else {
                    adrPenumpang P = inputDataPenumpang(B);
                    insertPenumpangFirst(B, P);
                    cout << "\nPenumpang " << P->info.nama << " berhasil ditambahkan di awal!\n";
                }
        }else{
        cout << "Bis penuh" <<endl;
    }
}

void adminInsertAfterPenumpang(ListBis &L){
    string idBis, idTiket;
    cout << "\n=== INSERT AFTER PENUMPANG ===\n";
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    adrBis B = findBisById(L, idBis);
     if (!isFullKapasitas(B)){
                    if (B == nullptr){
                            cout << "Bis tidak ditemukan!\n";
                    }else {
                        cout << "Masukkan ID Tiket Penumpang Sebelumnya: ";
                        cin >> idTiket;

                            adrPenumpang prec = B->firstPenumpang;
                            while (prec != nullptr && prec->info.idtiket != idTiket){
                            prec = prec->next;
                            }
                            if (prec == nullptr){
                                cout << "Penumpang sebelumnya tidak ditemukan!\n";
                            }else {
                                adrPenumpang P = inputDataPenumpang(L.first);
                                insertPenumpangAfter(B, prec, P);
                                cout << "\nPenumpang " << P->info.nama << " berhasil ditambahkan di tengah!\n";
                                }
                    }
        }else{
        cout << "Bis penuh" <<endl;
    }

}

void adminDeleteLastPenumpang(ListBis &L){
    string idBis;
    cout << "\n=== DELETE LAST PENUMPANG ===\n";
    cout << "Masukkan ID Bis: ";
    cin >> idBis;

    adrBis B = findBisById(L, idBis);

    if (B == nullptr){
        cout << "Bis tidak ditemukan!\n";
    }
    else {
        adrPenumpang P;
        deletePenumpangLast(B, P);

        if (P != nullptr){
            cout << "\nPenumpang " << P->info.nama << " berhasil dihapus dari akhir!\n";
        }
    }
}

adrPenumpang inputDataPenumpang(adrBis L){
    string nama, idtiket;
    adrPenumpang p,temp;
    cout << "Nama: ";
    cin >> nama;
    cout << "ID Tiket: ";
    cin >> idtiket;
    while (searchPenumpang(L->firstPenumpang, idtiket) != nullptr) {
        cout << "======IdTiket sudah ada, masukkan IdTiket berbeda======\n";
        cout << "ID Tiket: ";
        cin >> idtiket;
    }
    p = createElemenPenumpang(nama, idtiket);
    return p;
}
