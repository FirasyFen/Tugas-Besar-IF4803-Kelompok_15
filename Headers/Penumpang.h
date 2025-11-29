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
void deletePenumpang();
adrPenumpang searchPenumpang(ListPenumpang &p, string idtiket);
void displayPenumpang(ListPenumpang p);

#endif