#include <iostream>
#include "main.h"
using namespace std;

int main()
{
    ListBis ListUser;
    ListBis ListAdmin;
    createListBis(ListUser);
    createListBis(ListAdmin);
    string pilihan;
    while (pilihan != "3") {
        cout << "\n========================================\n";
        cout << "          MENU UTAMA                   \n";
        cout << "========================================\n";
        cout << "1. Menu Admin\n";
        cout << "2. Menu User\n";
        cout << "3. Keluar Program\n";
        cout << "========================================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

       if (pilihan == "1"){
              menuAdmin(ListAdmin);
       }else if(pilihan == "2"){
              menuUser(ListUser);
       }else if(pilihan == "3"){
              cout << "Terima kasih! Program selesai.\n";
       }else
           cout << "Pilihan tidak valid!\n";
       }
    return 0;
}
