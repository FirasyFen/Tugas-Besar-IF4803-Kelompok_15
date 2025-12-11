#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuAdmin(ListBis &L) {
    int pilihan = 0;
    adrBis P = nullptr;
    string id;
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
        cout << "5. Find Bis\n";
        cout << "----------------------------------------\n";
        cout << "6. Kembali\n";
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
            cout << "Kembali...\n";
        default:
            cout << "Pilihan tidak valid!\n";
            }
        }
}
