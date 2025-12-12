#include <iostream>
<<<<<<< HEAD
#incluide "main.h"

int main(){

=======
#include"main.h"
using namespace std;

int main()
{


    int pilihan = 0;

    while (pilihan != 3) {
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
                menuAdmin();
                break;
            case 2:
                menuUser();
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
>>>>>>> 37794cc7c9bb46da32fd0094989a9e88aad7ac00
}
