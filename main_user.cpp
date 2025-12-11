#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuUser(ListBis &L) {
    int pilihan = 0;
    adrBis P = nullptr;
    string id, rute;
    while (pilihan != 18) {
        cout << "\n========================================\n";
        cout << "          MENU USER - BIS            \n";
        cout << "========================================\n";
        cout << "1.  Mencari Bis Berdasarkan Rute\n";
        cout << "2.  Mencari Bis Berdasarkan ID\n";
        cout << "\n========================================\n";
        cout << "          MENU USER - PENUMPANG            \n";
        cout << "========================================\n";
        cout << "3.  Insert Last Penumpang ke Bis\n";
        cout << "----------------------------------------\n";
        cout << "4. Tampilkan Bis\n";
        cout << "----------------------------------------\n";
        cout << "5. Kembali\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

    switch (pilihan) {
        case 1:
            userFindBisByRute(L);
        case 2:
            userFindBisById(L);
        case 3:
            adminInsertLastPenumpang(L);
        case 4:
            displayBis(L);
        case 5:
            cout << "Kembali...\n";
        default:
            cout << "Pilihan tidak valid!\n";
            }
        }
}
