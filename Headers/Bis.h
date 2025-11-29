#ifndef BIS_H_INLUDED
#define BIS_H_INLUDED
#include <iostream>
using namespace std;

struct dataBis{
    int kapasitas;
    string rute;
};
typedef struct elmBis *adrBis;
struct elmBis{
    dataBis info;
    adrBis next;
};

struct ListBis{
    adrBis first;
};
void insertElmP(){}
void deleteElmP(){}
void findElmP(){}
void displayP(){}
#endif
