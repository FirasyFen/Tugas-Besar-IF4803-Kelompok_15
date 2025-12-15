#include <iostream>
#include "main.h"
using namespace std;

int main()
{
    ListBis L;
    createListBis(L);
    loadDummyData(L);

    int pilihan = 0;
    while (pilihan != 3) {
        system("cls");
        cout << "\n========================================\n";
        cout << "          MENU UTAMA                   \n";
        cout << "========================================\n";
        cout << "1. Menu Admin\n";
        cout << "2. Menu User\n";
        cout << "3. Keluar Program\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuAdmin(L);
                break;
            case 2:
                menuUser(L);
                break;
            case 3:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }
    return 0;
}
