#ifndef BIS_H_INLUDED
#define BIS_H_INLUDED
#include "string"
using namespace std;

struct dataBis{
    string idBis;
    int kapasitas;
    string rute;
};
typedef struct elmBis *adrBis;
struct elmBis{
    dataBis info;
    adrBis next;
    adrPenumpang firstPenumpang;
};

struct ListBis{
    adrBis first;
};
void createListBis(ListBis &L);
adrBis createElmBis(string idBis, int kapasitas, string rute);
void insertElmBis(ListBis &L, adrBis P);
void deleteElmBis(ListBis &L, adrBis &P);
adrBis findBis(ListBis L, int idBis);
void displayBis(ListBis L);
#endif
