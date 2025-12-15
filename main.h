#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include "string"
using namespace std;

struct dataBis{
    string idBis;
    int kapasitas;
    string tujuan;
};

typedef struct elmBis *adrBis;
typedef struct elemenPenumpang *adrPenumpang;
struct elmBis{
    dataBis info;
    adrBis next;
    adrPenumpang firstPenumpang;
};

struct ListBis{
    adrBis first;
};

struct penumpang{
    string idtiket;
    string nama;
};

struct elemenPenumpang{
    penumpang info;
    adrPenumpang next;
    adrPenumpang prev;
};

void createListBis(ListBis &L);
adrBis createElmBis(string idBis, int kapasitas, string tujuan);
bool isEmptyBis(ListBis L);
void insertFirstBis(ListBis &L, adrBis P);
void insertLastBis(ListBis &L, adrBis P);
void insertAfterBis(ListBis &L, adrBis Prec, adrBis P);
void deleteFirstBis(ListBis &L, adrBis &P);
void deleteLastBis(ListBis &L, adrBis &P);
void deleteAfterBis(ListBis &L, adrBis Prec, adrBis &P);
int countBis(ListBis L);
void displayBis(ListBis L);
adrBis findBisById(ListBis L, string idBis);
adrBis findBisByTujuan(ListBis L, string tujuan);
void adminInsertFirstBis(ListBis &L);
void adminInsertLastBis(ListBis &L);
void adminInsertAfterBis(ListBis &L);
void adminDeleteFirstBis(ListBis &L);
void adminDeleteLastBis(ListBis &L);
void adminDeleteAfterBis(ListBis &L);
adrBis inputBisData();


adrPenumpang createElemenPenumpang(string nama, string idtiket);
void insertPenumpangFirst(adrBis &L, adrPenumpang p);
void insertPenumpangAfter(adrBis &L, adrPenumpang prec, adrPenumpang p);
void insertPenumpangLast(adrBis &L,  adrPenumpang p);
void deletePenumpang(ListBis &L, adrBis B, adrPenumpang &P);
void deletePenumpangFirst(adrBis &L, adrPenumpang &p);
void deletePenumpangAfter(adrBis &L, adrPenumpang prec, adrPenumpang &p);
void deletePenumpangLast(adrBis &L, adrPenumpang &p);
void ubahPenumpang(adrPenumpang &L, string idtiket, string tujuanBaru);
adrPenumpang searchPenumpang(adrPenumpang p, string idtiket);
void displayPenumpang(adrPenumpang L);
void deleteAllPenumpang(adrPenumpang &L);
int countPenumpang(adrPenumpang L);
bool isEmptyPenumpang(adrPenumpang L);
void displayPenumpangTujuan(adrPenumpang L, string tujuan);
void adminInsertFirstPenumpang(ListBis &L);
void adminInsertLastPenumpang(ListBis &L);
void adminInsertAfterPenumpang(ListBis &L);
void adminDeleteFirstPenumpang(ListBis &L);
void adminDeleteLastPenumpang(ListBis &L);
void adminDeleteAfterPenumpang(ListBis &L);
adrPenumpang inputDataPenumpang();
adrBis userFindBisByTujuan(ListBis L);
adrBis userFindBisById(ListBis L);
void totalKursiKosong(ListBis L);
void bisMasihKosong(ListBis L);
void bisPenumpangTerbanyak(ListBis L);
void bisPenumpangTerkecil(ListBis L);
void penumpangPindahBis(ListBis &L);
bool isFullKapasitas(adrBis L);
void menuUser();
void menuAdmin();
void hitungRataRataPenumpang(ListBis L);

void loadDummyData(ListBis &L);
#endif
