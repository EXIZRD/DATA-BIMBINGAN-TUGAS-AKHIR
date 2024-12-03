#include <iostream>
#include "TB.h"
using namespace std;


void createListMhs(listMhs &M){
    M.First = NULL;
}

void createElmMhs(string nama, int NIM, string Kelas){
    adrMhs P = new elmMhs;
    P->info.nama = nama;
    P->info.NIM = NIM;
    P->info.Kelas = Kelas;
}

bool isEmptyMhs(listMhs M){
    return M.First == NULL;
}

void insertfirstMhs(listMhs &M, adrMhs P){
    if (isEmptyMhs(M)){
        M.First = P;
    }else {
        P->next = M.First;
        M.First = P;
    }
}

adrMhs FindMhs(listMhs M, int NIM){
    adrMhs q = M.First;
    while (q->info.NIM != NIM && q != NULL){
        q = q->next;
    }
    if (q != NULL){
        return q;
    }else {
        return NULL;
    }
}

void deleteFirstMhs(listMhs &M){
    if(!isEmptyMhs(M)){
        adrMhs p = M.First;
        DeleteRlsMhs(p);
        M.First = p->next;
        delete p;
        cout << "Mahasiswa Pertama Berhasil Dihapus." << endl;
    }else {
        cout << "Data Kosong." << endl;
    }
}

void deleteLastMhs(listMhs &M){
    if(!isEmptyMhs(M)){
        if(M.First->next == NULL){
            deleteFirstMhs(M);
        }else {
            adrMhs p = M.First;
            adrMhs prev = NULL;
            while (p->next != NULL){
                prev = p;
                p = p->next;
            }
            DeleteRlsMhs(p);
            prev->next = NULL;
            delete p;
            cout << "Mahasiswa Terakhir Berhasil DIhapus." << endl;
        }
    }else {
        cout << "Data Kosong." << endl;
    }
}

void printOneDataMhs(listMhs M, int NIM){
    adrMhs m = FindMhs(M, NIM);
    if (m != NULL){
        cout << "Nama :" << m->info.nama << endl;
        cout << "NIM : " << m->info.NIM << endl;
        cout << "Kelas : " << m->info.Kelas << endl;

        adrRelasi r = m->firstR;
        if(r != NULL){
            cout << "Dosen Pembimbing :" << endl;
            while (r != NULL){
                cout << "- " << r->infoD->info.nama << " (Kode Dosen: " << r->infoD->info.kodeDosen << ", Mata Kuliah: " << r->infoD->info.Matkul << ")" << endl;
                r = r->next;
            }
        }
    }else {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }
}

void printAllDataMhs(listMhs M){
    if (isEmptyMhs(M)){
        cout << "Data Kosong" << endl;
        return;
    }

    adrMhs m = M.First;
    while (m != NULL){
        cout << "----------------------------------------" << endl;
        cout << "Nama : " << m->info.nama << endl;
        cout << "NIM : " << m->info.NIM << endl;
        cout << "Kelas : " << m->info.Kelas << endl;

        adrRelasi r = m->firstR;
        if(r != NULL){
            cout << "Dosen Pembimbing :" << endl;
            while (r != NULL){
                cout << "- " << r->infoD->info.nama << " (Kode Dosen: " << r->infoD->info.kodeDosen << ", Mata Kuliah: " << r->infoD->info.Matkul << ")" << endl;
                r = r->next;
            }
        }
        m = m->next;
    }
    cout << "----------------------------------------" << endl;
}

//////////////////////////////////////////////////////////

void DeleteRlsMhs(adrMhs M){
    if (M != NULL){
        while (M->firstR != NULL){
            adrRelasi r = M->firstR;
            M->firstR = r->next;
            delete r;
        }
        cout << "Relasi Mahasiswa Dengan NIM " << M->info.NIM << " Telah Dihapus." << endl;
    }
}

void DeleteRlsDsn(adrDsn D, listMhs &M){
    if (D != NULL){
        adrMhs m = M.First;
        while (m != NULL){
            adrRelasi prevR = NULL;
            adrRelasi R = m->firstR;

           while (R !=NULL){
            if(R->infoD == D){
                if(prevR == NULL){
                    m->firstR = R->next;
                }else {
                    prevR->next = R->next;
                }
                adrRelasi temp = R;
                R = R->next;
                delete temp;
            }else {
                prevR = R;
                R = R->next;
            }
           }
           m = m->next;

        }
        cout << "Relasi Dosen dengan Kode " << D->info.kodeDosen << " Telah di Hapus." << endl;
    }
}

void Relasi(listMhs &M, listDsn &D, int NIM, string Kode){
   adrMhs m = FindMhs(M, NIM);
    adrDsn d = FindDsn(D, Kode);

    if (m != NULL && d != NULL) {
        int i = 0;
        adrRelasi r = m->firstR;
        while (r != NULL) {
            i++;
            r = r->next;
        }

        if (i < 2) {
            adrRelasi newRelasi = new elmRelasi;
            newRelasi->infoD = d;
            newRelasi->next = m->firstR;
            m->firstR = newRelasi;
            cout << "Relasi Berhasil Ditambahkan.";
        } else {
            cout << "Mahasiswa sudah memiliki dua dosen pembimbing.";
        }
    } else {
        cout << "Mahasiswa atau dosen tidak ditemukan.";
    }
}

////////////////////////////////////////////////////////

void createListDsn(listDsn &D){
    D.first = NULL;
    D.last = NULL;
}

void createElmDsn(string nama,string kode, string matkul){
    adrDsn p = new elmDsn;
    p->info.nama = nama;
    p->info.kodeDosen = kode;
    p->info.Matkul = matkul;
}

bool isEmptyDsn(listDsn D){
    return D.first == NULL && D.last == NULL;
}

void insertlast(listDsn &D, adrDsn P){
    if (isEmptyDsn(D)){
        D.first = P;
        D.last = P;
    }else {
        P->prev = D.last;
        D.last->next = P;
        D.last = P;
    }
}

adrDsn FindDsn(listDsn D, string Kode){
    adrDsn q = D.first;
    while (q->info.kodeDosen != Kode && q != NULL){
        q = q->next;
    }
    if (q != NULL){
        return q;
    }else {
        return NULL;
    }
}

void deleteFirstDsn(listDsn &D, listMhs &M){
    if(!isEmptyDsn(D)){
        adrDsn p = D.first;
        DeleteRlsDsn(p,M);
        D.first = p->next;
        if(D.first != NULL){
            D.first->prev = NULL;
        }else {
            D.last = NULL;
        }
        delete p;
        cout << "Dosen Pertama Berhasil Dihapus." << endl;
    }else {
        cout << "Data Dosen Kosong." << endl;
    }
}

void deleteLastDsn(listDsn &D, listMhs &M){
    if (!isEmptyDsn(D)){
        if(D.first == D.last){
            deleteFirstDsn(D,M);
        }else {
            adrDsn p = D.last;
            DeleteRlsDsn(p,M);
            D.last = p->prev;
            D.last->next = NULL;
            delete p;
            cout << "Dosen Terakhir Berhasil Dihapus." << endl;
        }
    }else {
        cout << "Data Dosen Kosong." << endl;
    }
}

void printOneDataDsn(listDsn D, string kode){

}

void printAllDataDsn(listDsn D, listMhs M){

}
