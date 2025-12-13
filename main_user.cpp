#include <iostream>
#include <string>
#include "main.h"
using namespace std;

void menuUser() {  // Terima parameter ListBis
    int pilihan = 0;
    string id, rute;
    ListBis L;
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
        cout << "6.  Insert Last Penumpang ke Bis\n";
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
                adminInsertLastPenumpang(L);
                break;
            case 7:
                cout << "Kembali ke menu utama...\n";
                return;  // KELUAR DARI FUNGSI, KEMBALI KE MAIN MENU
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }
}
