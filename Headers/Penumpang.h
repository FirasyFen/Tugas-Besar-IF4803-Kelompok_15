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

struct ListPenumpang{
    adrPenumpang first;
    adrPenumpang last;
};

adrPenumpang createElemenPenumpang(string tujuan, string idtiket);
void insertPenumpangFirst(ListPenumpang &L, adrPenumpang p);
void insertPenumpangAfter(ListPenumpang &L, adrPenumpang prec, adrPenumpang p);
void insertPenumpangLast(ListPenumpang &L,  adrPenumpang p);
void deletePenumpangFirst(ListPenumpang &L, adrPenumpang &p);
void deletePenumpangAfter(ListPenumpang &L, adrPenumpang prec, adrPenumpang &p);
void deletePenumpangLast(ListPenumpang &L, adrPenumpang &p);
void ubahPenumpang(ListPenumpang &L, string idtiket, string tujuanBaru);
adrPenumpang searchPenumpang(ListPenumpang &p, string notiket, adrPenumpang idtiket);
void displayPenumpang(ListPenumpang L);
void deleteAllPenumpang(ListPenumpang &L);
int countPenumpang(ListPenumpang L);
bool isEmptyPenumpang(ListPenumpang L);
void displayPenumpangTujuan(ListPenumpang L, string tujuan);
#endif