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
void insertPenumpangFirst(ListPenumpang &p, adrPenumpang q);
void insertPenumpangAfter(ListPenumpang &p, adrPenumpang prec, adrPenumpang q);
void insertPenumpangLast(ListPenumpang &p,  adrPenumpang q);
void deletePenumpangFirst(ListPenumpang &p, adrPenumpang &l);
void deletePenumpangAfter(ListPenumpang &p, adrPenumpang prec, adrPenumpang &l);
void deletePenumpangLast(ListPenumpang &p, adrPenumpang &l);
void ubahPenumpang(ListPenumpang &L, string idtiket, string tujuanBaru);
adrPenumpang searchPenumpang(ListPenumpang &p, string notiket, adrPenumpang idtiket);
void displayPenumpang(ListPenumpang p);
void deleteAllPenumpang(ListPenumpang &L);
int countPenumpang(ListPenumpang L);
bool isEmptyPenumpang(ListPenumpang L);
void displayPenumpangTujuan(ListPenumpang L, string tujuan);
#endif