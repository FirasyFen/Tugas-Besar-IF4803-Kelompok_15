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
void insertPenumpang(ListPenumpang &p, adrPenumpang q);
void deletePenumpang(ListPenumpang &p, string idtiket);
void ubahPenumpang(ListPenumpang &L, string idtiket, string tujuanBaru);
adrPenumpang searchPenumpang(ListPenumpang &p, string idtiket);
void displayPenumpang(ListPenumpang p);
void deleteAllPenumpang(ListPenumpang &L);
int countPenumpang(ListPenumpang L);
bool isEmptyPenumpang(ListPenumpang L);
void displayPenumpangTujuan(ListPenumpang L, string tujuan);
#endif