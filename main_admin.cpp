#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuAdmin() {
    int pilihan;
    pilihan = 0;
    ListBis L;
    system("cls");
    while (pilihan != 17) {

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

        switch (pilihan) {
            case 1:
                adminInsertFirstBis(L);
                break;
            case 2:
                adminInsertLastBis(L);
                break;
            case 3:
                adminInsertAfterBis(L);
                break;
            case 4:
                adminDeleteFirstBis(L);
                break;
            case 5:
                adminDeleteLastBis(L);
                break;
            case 6:
                adminDeleteAfterBis(L);
                break;
            case 7:
                adminInsertFirstPenumpang(L);
                break;
            case 8:
                adminInsertLastPenumpang(L);
                break;
            case 9:
                adminInsertAfterPenumpang(L);
                break;
            case 10:
                adminDeleteFirstPenumpang(L);
                break;
            case 11:
                adminDeleteLastPenumpang(L);
                break;
            case 12:
                adminDeleteAfterPenumpang(L);
                break;
            case 13:
                displayBis(L);
                break;
            case 14: {
                string idBis;
                    displayBis(L);
                cout << "Masukkan ID Bis: ";
                cin >> idBis;
                adrBis bis = findBisById(L, idBis);
                if (bis != nullptr) {
                    displayPenumpang(bis->firstPenumpang);
                }
                break;
            }
            case 15: {
                string idBis;
                cout << "Masukkan ID Bis: ";
                cin >> idBis;
                adrBis hasil = findBisById(L, idBis);
                if (hasil != nullptr) {
                    cout << "Bis ditemukan: " << hasil->info.idBis << endl;
                }
                break;
            }
            case 16: {
                string idBis, idTiket;
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
                break;
            }
            case 17:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }

    }
}
