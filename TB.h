#ifndef TB_H_INCLUDED
#define TB_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct dosen infotypeD;

struct dosen {
    string nama;
    string kodeDosen;
    string Matkul;
};

typedef struct elmDsn *adrDsn;

struct elmDsn{
    infotypeD info;
    adrDsn next;
    adrDsn prev;
};


struct listDsn{
    adrDsn first;
    adrDsn last;
};

////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct mahasiswa infotypeM;

struct mahasiswa {
    string nama;
    int NIM;
    string Kelas;
};

typedef struct elmMhs *adrMhs;

struct elmMhs{
    infotypeM info;
    adrMhs next;
};

struct listMhs{
    adrMhs First;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct elmRelasi *adrRelasi;

struct elmRelasi{
    adrDsn infoD;
    adrRelasi next;
    adrMhs infoM;
};

struct listRelasi{
    adrRelasi first;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////


void createListDsn(listDsn &D);
adrDsn createElmDsn(string nama,string kode, string matkul);
bool isEmptyDsn(listDsn D);
void insertLastD(listDsn &D, adrDsn P);
adrDsn FindDsn(listDsn D, string Kode);
void deleteFirstDsn(listDsn &D, listMhs &M);
void deleteLastDsn(listDsn &D, listMhs &M);
void printOneDataDsn(listDsn D, string kode);
void printAllDataDsn(listDsn D, listMhs M);
/////////////////////////////////////////////////////////////////////////////////////////////////////

void createListMhs(listMhs &M);
adrMhs createElmMhs(string nama, int NIM, string Kelas);
bool isEmptyMhs(listMhs M);
void insertFirstM(listMhs &M, adrMhs P);
adrMhs FindMhs(listMhs M, int NIM);
void deleteFirstMhs(listMhs &M);
void deleteLastMhs(listMhs &M);
void printOneDataMhs(listMhs M, listRelasi &R, int NIM);
void printAllDataMhs(listMhs M, listRelasi &R);
/////////////////////////////////////////////////////////////////////////////////////////////////////

void createListRls(listRelasi &R);
adrRelasi createElmRls(adrDsn d, adrMhs m);
void insertFirstR(listRelasi &R, adrRelasi p);
void connect(listRelasi &R, listDsn D, listMhs M, string KodeDsn, int NIM);
adrRelasi findRelasiMhs(listRelasi &R, int NIM);
adrRelasi findRelasiDosen(listRelasi &R, string kodeDosen);
void DeleteRlsMhs(listRelasi &R, adrMhs m);
void DeleteRlsDsn(adrDsn D, listRelasi &R);


#endif // TB_H_INCLUDED
