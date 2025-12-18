#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuAdmin(ListBis &L) {
    string idBis, idTiket, pilihan;
    system("cls");
    while (pilihan != "17") {
        cout << "\n========================================\n";
        cout << "          MENU ADMIN - BIS            \n";
        cout << "========================================\n";
        cout << "1.  Insert First Bis\n";
        cout << "2.  Insert Last Bis\n";
        cout << "3.  Insert After Bis\n";
        cout << "4.  Delete First Bis\n";
        cout << "5.  Delete Last Bis\n";
        cout << "6.  Delete After Bis\n";
        cout << "\n========================================\n";
        cout << "          MENU ADMIN - PENUMPANG      \n";
        cout << "========================================\n";
        cout << "7.  Insert First Penumpang ke Bis\n";
        cout << "8.  Insert Last Penumpang ke Bis\n";
        cout << "9.  Insert After Penumpang ke Bis\n";
        cout << "10. Delete First Penumpang dari Bis\n";
        cout << "11. Delete Last Penumpang dari Bis\n";
        cout << "12. Delete After Penumpang dari Bis\n";
        cout << "----------------------------------------\n";
        cout << "13. Tampilkan Bis\n";
        cout << "14. Tampilkan Penumpang di Bis\n";
        cout << "----------------------------------------\n";
        cout << "15. Cari Bis by ID\n";
        cout << "16. Cari Penumpang\n";
        cout << "----------------------------------------\n";
        cout << "17. Kembali ke Menu Utama\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        if (pilihan == "1"){
              adminInsertFirstBis(L);
       }else if(pilihan == "2"){
              adminInsertLastBis(L);
       }else if(pilihan == "3"){
               adminInsertAfterBis(L);
       }else if(pilihan == "4"){
                adminDeleteFirstBis(L);
       }else if(pilihan == "5"){
                adminDeleteLastBis(L);
       }else if(pilihan == "6"){
               adminDeleteAfterBis(L);
       }else if(pilihan == "7"){
              adminInsertFirstPenumpang(L);
       }else if(pilihan == "8"){
               adminInsertLastPenumpang(L);
       }else if(pilihan == "9"){
                adminInsertAfterPenumpang(L);
       }else if(pilihan == "10"){
                adminDeleteFirstPenumpang(L);
       }else if(pilihan == "11"){
                adminDeleteLastPenumpang(L);
       }else if(pilihan == "12"){
                 adminDeleteAfterPenumpang(L);
       }else if(pilihan == "13"){
                 displayBis(L);
       }else if(pilihan == "14"){
                    displayBis(L);
                cout << "Masukkan ID Bis: ";
                cin >> idBis;
                adrBis bis = findBisById(L, idBis);
                if (bis != nullptr) {
                    displayPenumpang(bis->firstPenumpang);
                }
       }else if(pilihan == "15"){
                cout << "Masukkan ID Bis: ";
                cin >> idBis;
                adrBis hasil = findBisById(L, idBis);
                if (hasil != nullptr) {
                    cout << "Bis ditemukan: " << hasil->info.idBis << endl;
                }
       }else if(pilihan == "16"){
                cout << "Masukkan ID Bis: ";
                cin >> idBis;
                cout << "Masukkan ID Tiket: ";
                cin >> idTiket;
                adrBis bis = findBisById(L, idBis);
                if (bis != nullptr) {
                    adrPenumpang hasil = searchPenumpang(bis->firstPenumpang, idTiket);
                    if (hasil != nullptr) {
                        cout << "Penumpang ditemukan: " << hasil->info.nama << endl;
                    }
                }
       }else if(pilihan == "17"){
              cout << "Kembali ke menu utama...\n";
              system("cls");
       }else
              cout << "Pilihan tidak valid!\n";
       }
}
