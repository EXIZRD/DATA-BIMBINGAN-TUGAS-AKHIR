#ifndef TB_H_INCLUDED
#define TB_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct mahasiswa infotypeM;

struct mahasiswa {
    string nama;
    int NIM;
    string Kelas;
};

typedef struct dosen infotypeD;

struct dosen {
    string nama;
    string kodeDosen;
    string Matkul;
};

typedef struct elmRelasi *adrRelasi;
typedef struct elmMhs *adrMhs;
typedef struct elmDsn *adrDsn;

struct elmMhs{
    infotypeM info;
    adrRelasi firstR;
    adrMhs next;
};

struct elmDsn{
    infotypeD info;
    adrDsn next;
    adrDsn prev;
};

struct elmRelasi{
    adrDsn infoD;
    adrRelasi next;
    adrMhs infoM;
};

struct listMhs{
    adrMhs First;
};

struct listDsn{
    adrDsn first;
    adrDsn last;
};

struct listRelasi{
    adrRelasi first;
};


void createListMhs(listMhs &M);
void createElmMhs(string nama, int NIM, string Kelas);
bool isEmptyMhs(listMhs M);
void insertfirstM(listMhs &M, adrMhs P);
adrMhs FindMhs(listMhs M, int NIM);
void deleteFirstMhs(listMhs &M);
void deleteLastMhs(listMhs &M);
void printOneDataMhs(listMhs M, int NIM);
void printAllDataMhs(listMhs M);

void DeleteRlsMhs(adrMhs M);
void DeleteRlsDsn(adrDsn D, listMhs &M);
void Relasi(listMhs &M, listDsn &D, int NIM, string Kode);

void createListDsn(listDsn &D);
void createElmDsn(string nama,string kode, string matkul);
bool isEmptyDsn(listDsn D);
void insertlast(listDsn &D, adrDsn P);
adrDsn FindDsn(listDsn D, string Kode);
void deleteFirstDsn(listDsn &D, listMhs &M);
void deleteLastDsn(listDsn &D, listMhs &M);
void printOneDataDsn(listDsn D, string kode);
void printAllDataDsn(listDsn D, listMhs M);


#endif // TB_H_INCLUDED
