#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuUser() {  // Terima parameter ListBis
    int pilihan = 0;
    string id, rute;
    ListBis L;
    while (pilihan != 5) {
        cout << "\n========================================\n";
        cout << "          MENU USER - BIS            \n";
        cout << "========================================\n";
        cout << "1.  Mencari Bis Berdasarkan Tujuan\n";
        cout << "2.  Mencari Bis Berdasarkan ID\n";
        cout << "\n========================================\n";
        cout << "          MENU USER - PENUMPANG            \n";
        cout << "========================================\n";
        cout << "3.  Insert Last Penumpang ke Bis\n";
        cout << "----------------------------------------\n";
        cout << "4. Tampilkan Bis\n";
        cout << "----------------------------------------\n";
        cout << "5. Kembali ke Menu Utama\n";  // UBAH TEXT
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
                adminInsertLastPenumpang(L);
                break;
            case 4:
                displayBis(L);
                break;
            case 5:
                cout << "Kembali ke menu utama...\n";
                return;  // KELUAR DARI FUNGSI, KEMBALI KE MAIN MENU
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }
}
