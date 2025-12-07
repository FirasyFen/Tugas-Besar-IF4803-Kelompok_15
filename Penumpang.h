#ifndef PENUMPANG_H_INLUDED
#define PENUMPANG_H_INLUDED
#include "string"
using namespace std;

typedef struct elemenPenumpang *adrPenumpang;

struct penumpang{
    string tujuan;
    string idtiket;
};

struct elemenPenumpang{
    penumpang info;
    adrPenumpang next;
    adrPenumpang prev;
};

adrPenumpang createElemenPenumpang(string tujuan, string idtiket);
void insertPenumpangFirst(adrBis &L, adrPenumpang p);
void insertPenumpangAfter(adrBis &L, adrPenumpang prec, adrPenumpang p);
void insertPenumpangLast(adrBis &L,  adrPenumpang p);
void deletePenumpangFirst(adrBis &L, adrPenumpang &p);
void deletePenumpangAfter(adrBis &L, adrPenumpang prec, adrPenumpang &p);
void deletePenumpangLast(adrBis &L, adrPenumpang &p);
void ubahPenumpang(adrPenumpang &L, string idtiket, string tujuanBaru);
adrPenumpang searchPenumpang(adrPenumpang &p, string notiket, adrPenumpang idtiket);
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
#endif