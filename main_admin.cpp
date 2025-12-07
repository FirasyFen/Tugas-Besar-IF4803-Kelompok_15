#include <iostream>
#include <string>
#include "Bis.h"
#include "Penumpang.h"
using namespace std;

void menuAdmin(ListBis &L) {
    int pilihan = 0;
    adrBis P = nullptr;
    string id;
    while (pilihan != 18) {
        cout << "\n========================================\n";
        cout << "          MENU ADMIN - BIS            \n";
        cout << "========================================\n";
        cout << "1.  Insert First Bis\n";
        cout << "2.  Insert Last Bis\n";
        cout << "3.  Insert After Bis\n";
        cout << "4.  Delete First Bis\n";
        cout << "5.  Delete Last Bis\n";
        cout << "6.  Delete After Bis\n";
        cout << "----------------------------------------\n";
        cout << "7.  Insert First Penumpang ke Bis\n";
        cout << "8.  Insert Last Penumpang ke Bis\n";
        cout << "9.  Insert After Penumpang ke Bis\n";
        cout << "10. Delete First Penumpang dari Bis\n";
        cout << "11. Delete Last Penumpang dari Bis\n";
        cout << "12. Delete After Penumpang dari Bis\n";
        cout << "----------------------------------------\n";
        cout << "13. Tampilkan Bis\n";
        cout << "14. Tampilkan Penumpang\n";
        cout << "----------------------------------------\n";
        cout << "15. Find Bis\n";
        cout << "16. Find Penumpang\n";
        cout << "17. Ubah Data Penumpang\n";
        cout << "----------------------------------------\n";
        cout << "18. Kembali\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

    switch (pilihan) {
        case 1:
            adminInsertFirstBis(L);
        case 2:
            adminInsertLastBis(L);        
        case 3:
            adminInsertAfterBis(L);
        case 4:
            adminDeleteFirstBis(L);
        case 5:
            adminDeleteLastBis(L);
        case 6:
            adminDeleteAfterBis(L);
        case 7:
            adminInsertFirstPenumpang(L);
        case 8:
            adminInsertLastPenumpang(L);
        case 9:
            adminInsertAfterPenumpang(L);
        case 10:
            adminDeleteFirstPenumpang(L);
        case 11:
            adminDeleteLastPenumpang(L);
        case 12:
            adminDeleteAfterPenumpang(L);
        case 13:
            displayBis(L);
        case 14:
            displayPenumpang(L.first->firstPenumpang);
        case 15:
            cout << "\nMasukkan idbis yang ingin di cari\n";
            cin >> id;
            findBis(L, id);
        case 16:
            searchPenumpang(P->firstPenumpang, id, P->firstPenumpang);
        case 17:
            ubahPenumpang(P->firstPenumpang,id, id);
        case 18:
            cout << "Kembali...\n";
        default:
            cout << "Pilihan tidak valid!\n";
            }   
        }
}