#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuUser(ListBis &L){
    string id, rute, pilihan;
    system("cls");
    while (pilihan != "10") {
        cout << "\n========================================\n";
        cout << "               MENU USER                  \n";
        cout << "========================================\n";
        cout << "1.  Mencari Bis Berdasarkan Tujuan\n";
        cout << "2.  Mencari Bis Berdasarkan ID\n";
        cout << "3.  Cek Bis Yang Masih Kosong\n";
        cout << "4.  Cek Bis Terpadat ID\n";
        cout << "5.  Cek Bis Tersepi ID\n";
        cout << "6.  Cek rata-rata penumpang bis\n";
        cout << "7.  Insert Bis dengan kondisi\n";
        cout << "8.  Tampilkan data bis\n";
        cout << "9.  Add data dummy\n";
        cout << "----------------------------------------\n";
        cout << "10. Kembali ke Menu Utama\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

       if (pilihan == "1"){
            userFindBisByTujuan(L);
       }else if(pilihan == "2"){
            userFindBisById(L);
       }else if(pilihan == "3"){
            bisMasihKosong(L);
       }else if(pilihan == "4"){
            bisPenumpangTerbanyak(L);
       }else if(pilihan == "5"){
            bisPenumpangTerkecil(L);
       }else if(pilihan == "6"){
            hitungRataRataPenumpang(L);
       }else if(pilihan == "7"){
            string id, tujuan;
            bool idb = false;
            int kapasitas;
            adrBis P;
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
            if(P->info.kapasitas > 15){
                insertLastBis(L, P);
            }else{
                insertFirstBis(L,P);
            }
       }else if(pilihan == "8"){
            displayBis(L);
       }else if(pilihan == "9"){
            loadDummyData(L);
            cout << "Data dummy sudah terinput\n";
       }else if(pilihan == "10"){
            cout << "Kembali ke menu utama...\n";
            system("cls");
       }else
           cout << "Pilihan tidak valid!\n";
       }
    }

void loadDummyData(ListBis &L) {
    /* ====== DUMMY BIS ====== */
    adrBis A = createElmBis("B001", 25, "Jakarta");
    adrBis B = createElmBis("B002", 6, "Bandung");
    adrBis C = createElmBis("B003", 8, "Yogyakarta");
    adrBis D = createElmBis("B004", 9, "Surabaya");
    adrBis E = createElmBis("B005", 30, "Bali");

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
