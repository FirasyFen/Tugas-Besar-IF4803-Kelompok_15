#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuUser(ListBis &L){
    int pilihan = 0;
    string id, rute;
    system("cls");
    while (pilihan != 7) {
        cout << "\n========================================\n";
        cout << "               MENU USER                  \n";
        cout << "========================================\n";
        cout << "1.  Mencari Bis Berdasarkan Tujuan\n";
        cout << "2.  Mencari Bis Berdasarkan ID\n";
        cout << "3.  Cek Bis Yang Masih Kosong\n";
        cout << "4.  Cek Bis Terpadat ID\n";
        cout << "5.  Cek Bis Tersepi ID\n";
        cout << "6.  Cek rata-rata penumpang bis\n";
        cout << "----------------------------------------\n";
        cout << "7. Kembali ke Menu Utama\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                userFindBisByTujuan(L);
                break;
            case 2:
                userFindBisById(L);
                break;
            case 3:
                bisMasihKosong(L);
                break;
            case 4:
                bisPenumpangTerbanyak(L);
                break;
            case 5:
                bisPenumpangTerkecil(L);
                break;
            case 6:
                hitungRataRataPenumpang(L);
                break;
            case 7:
                cout << "Kembali ke menu utama...\n";
                return;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }
}

void loadDummyData(ListBis &L) {
    /* ====== DUMMY BIS ====== */
    adrBis A = createElmBis("B001", 5, "Jakarta");
    adrBis B = createElmBis("B002", 4, "Bandung");
    adrBis C = createElmBis("B003", 6, "Yogyakarta");
    adrBis D = createElmBis("B004", 8, "Surabaya");
    adrBis E = createElmBis("B005", 10, "Bali");

    insertLastBis(L, A);
    insertLastBis(L, B);
    insertLastBis(L, C);
    insertLastBis(L, D);
    insertLastBis(L, E);

    /* ====== DUMMY PENUMPANG UNTUK BIS A ====== */
    insertPenumpangLast(A, createElemenPenumpang("Andi", "T001"));
    insertPenumpangLast(A, createElemenPenumpang("Budi", "T002"));
    insertPenumpangLast(A, createElemenPenumpang("Citra", "T003"));

    /* ====== DUMMY PENUMPANG UNTUK BIS B ====== */
    insertPenumpangLast(B, createElemenPenumpang("Dewi", "T004"));
    insertPenumpangLast(B, createElemenPenumpang("Andi", "T005"));
    insertPenumpangLast(B, createElemenPenumpang("Fajar", "T006"));
    insertPenumpangLast(B, createElemenPenumpang("Gita", "T007"));

    /* ====== DUMMY PENUMPANG UNTUK BIS C ====== */
    insertPenumpangLast(C, createElemenPenumpang("Hadi", "T008"));
    insertPenumpangLast(C, createElemenPenumpang("Indra", "T009"));
    insertPenumpangLast(C, createElemenPenumpang("Joko", "T010"));

    /* ====== DUMMY PENUMPANG UNTUK BIS D ====== */
    insertPenumpangLast(D, createElemenPenumpang("Kartika", "T011"));
    insertPenumpangLast(D, createElemenPenumpang("Lina", "T012"));

    /* ====== DUMMY PENUMPANG UNTUK BIS E ====== */
    insertPenumpangLast(E, createElemenPenumpang("Mira", "T013"));
}
