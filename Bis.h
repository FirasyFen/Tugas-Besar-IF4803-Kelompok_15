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
bool isEmpty(ListBis L);
void insertFirstBis(ListBis &L, adrBis P);
void insertLastBis(ListBis &L, adrBis P);
void insertAfterBis(ListBis &L, adrBis Prec, adrBis P);
void deleteFirstBis(ListBis &L, adrBis &P);
void deleteLastBis(ListBis &L, adrBis &P);
void deleteAfterBis(ListBis &L, adrBis Prec, adrBis &P);
adrBis findBis(ListBis L, string idBis);
int countBis(ListBis L);
void displayBis(ListBis L);
adrBis findBisByRute(ListBis L, string rute);
#endif