#include <iostream>
#include "MLL.h"
#include <cstdlib>
using namespace std;


void createListDsn(listDsn &D){
    D.first = NULL;
    D.last = NULL;
}

adrDsn createElmDsn(string nama,string kode, string matkul){
    adrDsn p = new elmDsn;
    p->info.nama = nama;
    p->info.kodeDosen = kode;
    p->info.Matkul = matkul;
    return p;
}

bool isEmptyDsn(listDsn D){
    return D.first == NULL && D.last == NULL;
}

void insertLastD(listDsn &D, adrDsn P){
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

void deleteFirstDsn(listDsn &D, listRelasi &R) {
    if (!isEmptyDsn(D)) {
        adrDsn p = D.first;
        DeleteRlsDsn(p, R);

        D.first = p->next;
        if (D.first != NULL) {
            D.first->prev = NULL;
        } else {
            D.last = NULL;
        }
        delete p;
        cout << "Dosen Pertama Berhasil Dihapus." << endl;
    } else {
        cout << "Data Dosen Kosong." << endl;
    }
}


void deleteLastDsn(listDsn &D, listRelasi &R) {
    if (!isEmptyDsn(D)) {
        if (D.first == D.last) {
            deleteFirstDsn(D, R);
        } else {
            adrDsn p = D.last;
            DeleteRlsDsn(p, R);

            D.last = p->prev;
            D.last->next = NULL;
            delete p;
            cout << "Dosen Terakhir Berhasil Dihapus." << endl;
        }
    } else {
        cout << "Data Dosen Kosong." << endl;
    }
}


void printOneDataDsn(listDsn D, listRelasi R, listMhs M, string kode) {
    adrDsn d = FindDsn(D, kode);
    if (d != NULL) {
        cout << "Nama        : " << d->info.nama << endl;
        cout << "Kode Dosen  : " << d->info.kodeDosen << endl;
        cout << "Mata Kuliah : " << d->info.Matkul << endl;


        bool adaRelasi = false;
        adrRelasi r = R.first;
        while (r != NULL) {
            if (r->infoD == d) {
                adaRelasi = true;
                adrMhs m = r->infoM;
                if (m != NULL) {
                    cout << "  - Mahasiswa: " << m->info.nama
                         << " (NIM: " << m->info.NIM << ")" << endl;
                }
            }
            r = r->next;
        }

        if (!adaRelasi) {
            cout << "Tidak ada mahasiswa yang terkait dengan dosen ini." << endl;
        }
    } else {
        cout << "Dosen dengan kode " << kode << " tidak ditemukan." << endl;
    }
}


void printAllDataDsn(listDsn D, listRelasi R, bool ascending) {
    sortDosenbyMahasiswa(D,R,ascending);
    adrDsn d = D.first;
    while (d != NULL) {
        cout << "------------------------------------------------------" << endl;
        cout << "Nama Dosen : " << d->info.nama << endl;
        cout << "Kode       : " << d->info.kodeDosen << endl;
        cout << "Mata Kuliah: " << d->info.Matkul << endl;

        int jumlahMahasiswa = 0;
        adrRelasi r = R.first;
        while (r != NULL) {
            if (r->infoD == d) {
                jumlahMahasiswa++;
                adrMhs m = r->infoM;
                if (m != NULL) {
                    cout << "  - Mahasiswa: " << m->info.nama
                         << " (NIM: " << m->info.NIM << ")" << endl;
                }
            }
            r = r->next;
        }

        if (jumlahMahasiswa == 0) {
            cout << "  Tidak ada mahasiswa yang terkait dengan dosen ini." << endl;
        }
        cout << "Total Mahasiswa: " << jumlahMahasiswa << endl;
        d = d->next;
    }
}

void sortDosenbyMahasiswa(listDsn &D, listRelasi R, bool ascending){
     if (isEmptyDsn(D)) {
        cout << "Data Dosen Kosong" << endl;
        return;
    }

    adrDsn prev, current;
    adrDsn end = NULL;

    while (D.first != end) {
        prev = NULL;
        current = D.first;

        while (current->next != end) {
            adrDsn nextNode = current->next;
            int count1 = countMahasiswa(current, R);
            int count2 = countMahasiswa(nextNode, R);

            if ((ascending && count1 > count2) || (!ascending && count1 < count2)) {
                if (prev == NULL) {
                    D.first = nextNode;
                } else {
                    prev->next = nextNode;
                }
                current->next = nextNode->next;
                nextNode->next = current;
                current = nextNode;
            }
            prev = current;
            current = current->next;
        }
        end = current;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void createListMhs(listMhs &M){
    M.First = NULL;
}

adrMhs createElmMhs(string nama, int NIM, string Kelas){
    adrMhs P = new elmMhs;
    P->info.nama = nama;
    P->info.NIM = NIM;
    P->info.Kelas = Kelas;
    return P;
}

bool isEmptyMhs(listMhs M){
    return M.First == NULL;
}

void insertFirstM(listMhs &M, adrMhs P){
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

void deleteFirstMhs(listMhs &M, listRelasi &R) {
    if (!isEmptyMhs(M)) {
        adrMhs p = M.First;
        DeleteRlsMhs(R, p);
        M.First = p->next;
        delete p;

        cout << "Mahasiswa Pertama berhasil dihapus." << endl;
    } else {
        cout << "Data Mahasiswa Kosong." << endl;
    }
}


void deleteLastMhs(listMhs &M, listRelasi &R) {
    if (!isEmptyMhs(M)) {
        if (M.First->next == NULL) {
            deleteFirstMhs(M, R);
        } else {
            adrMhs p = M.First;
            adrMhs prev = NULL;

            while (p->next != NULL) {
                prev = p;
                p = p->next;
            }
            DeleteRlsMhs(R, p);
            prev->next = NULL;
            delete p;

            cout << "Mahasiswa Terakhir Berhasil Dihapus." << endl;
        }
    } else {
        cout << "Data Mahasiswa Kosong." << endl;
    }
}



void printOneDataMhs(listMhs M, listRelasi &R, int NIM) {
    adrMhs m = FindMhs(M, NIM);
    if (m != NULL) {
        cout << "Nama: " << m->info.nama << endl;
        cout << "NIM: " << m->info.NIM << endl;
        cout << "Kelas: " << m->info.Kelas << endl;

        adrRelasi r = findRelasiMhs(R, NIM);
        if (r != NULL) {
            cout << "Dosen Pembimbing: " << endl;
            while (r != NULL) {
                cout << "- " << r->infoD->info.nama<< " (Kode Dosen: " << r->infoD->info.kodeDosen << ", Mata Kuliah: " << r->infoD->info.Matkul << ")" << endl;
                r = r->next;
            }
        } else {
            cout << "Mahasiswa dengan NIM " << NIM << " tidak memiliki dosen pembimbing." << endl;
        }
    } else {
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }
}


void printAllDataMhs(listMhs M, listRelasi &R){
    if (isEmptyMhs(M)){
        cout << "Data Kosong" << endl;
        return;
    }

    adrMhs m = M.First;
    while (m != NULL){
        cout << "----------------------------------------" << endl;
        cout << "Nama: " << m->info.nama << endl;
        cout << "NIM: " << m->info.NIM << endl;
        cout << "Kelas: " << m->info.Kelas << endl;

        adrRelasi r = findRelasiMhs(R, m->info.NIM);
        if (r != NULL) {
            cout << "Dosen Pembimbing: " << endl;
            while (r != NULL) {
                cout << "- " << r->infoD->info.nama
                     << " (Kode Dosen: " << r->infoD->info.kodeDosen
                     << ", Mata Kuliah: " << r->infoD->info.Matkul << ")" << endl;
                r = r->next;
            }
        } else {
            cout << "Mahasiswa dengan NIM " << m->info.NIM << " tidak memiliki dosen pembimbing." << endl;
        }
        m = m->next;
    }
    cout << "----------------------------------------" << endl;
}

int countMahasiswa(adrDsn d, listRelasi R) {
    int count = 0;
    adrRelasi r = R.first;
    while (r != NULL) {
        if (r->infoD == d) {
            count++;
        }
        r = r->next;
    }
    return count;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void createListRls(listRelasi &R){
    R.first = NULL;
}

adrRelasi createElmRls(adrDsn d, adrMhs m){
    adrRelasi r = new elmRelasi;
    r->infoD = d;
    r->infoM = m;
    r->next = NULL;
}

void insertFirstR(listRelasi &R, adrRelasi p){
    if (R.first == NULL){
        R.first = p;
    }else {
        p->next = R.first;
        R.first = p;
    }
}

void connect(listRelasi &R, listDsn D, listMhs M, string KodeDsn, int NIM){
    adrDsn d = FindDsn(D, KodeDsn);
    adrMhs m = FindMhs(M, NIM);
    adrRelasi r;
    if (d != NULL && m != NULL) {
        r = createElmRls(d,m);
        insertFirstR(R,r);
        cout << "Relasi berhasil ditambahkan." << endl;
    } else {
        cout << "Dosen atau Mahasiswa tidak ditemukan!" << endl;
    }
}

adrRelasi findRelasiMhs(listRelasi &R, int NIM) {
    adrRelasi r = R.first;
    while (r != NULL) {
        if (r->infoM->info.NIM == NIM) {
            return r;
        }
        r = r->next;
    }
    return NULL;
}

adrRelasi findRelasiDosen(listRelasi &R, string kodeDosen) {
    adrRelasi r = R.first;
    while (r != NULL) {
        if (r->infoD->info.kodeDosen == kodeDosen) {
            return r;
        }
        r = r->next;
    }
    return NULL;
}


void DeleteRlsMhs(listRelasi &R, adrMhs m) {
    adrRelasi r = R.first;
    adrRelasi prev = NULL;

    while (r != NULL) {
        if (r->infoM == m) {
            if (prev == NULL) {
                R.first = r->next;
            } else {
                prev->next = r->next;
            }
            adrRelasi temp = r;
            r = r->next;
            delete temp;
        } else {
            prev = r;
            r = r->next;
        }
    }
    cout << "Semua Relasi untuk Mahasiswa dengan NIM " << m->info.NIM << " telah dihapus." << endl;
}




void DeleteRlsDsn(adrDsn D, listRelasi &R) {
    if (D != NULL) {
        adrRelasi r = R.first;
        adrRelasi prevR = NULL;
        while (r != NULL) {
            if (r->infoD == D) {
                if (prevR == NULL) {
                    R.first = r->next;
                } else {
                    prevR->next = r->next;
                }
                adrRelasi temp = r;
                r = r->next;
                delete temp;
            } else {
                prevR = r;
                r = r->next;
            }
        }
        cout << "Relasi Dosen dengan Kode " << D->info.kodeDosen << " Telah di Hapus." << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mainMenu(){
    cout << "----------------------------------------" << endl;
    cout << "                  MENU                  " << endl;
    cout << "----------------------------------------\n" << endl;
    cout << "Tabah Data (1)  " << endl;
    cout << "Pilih Dosen Pembimbing (2)  " << endl;
    cout << "Hapus Data (3)  " << endl;
    cout << "Tampilkan Data (4)  " << endl;
    cout << "Cari Data (5)  " << endl;
    cout << "Exit (0)  " << endl;
}

void pilihan1(){
    cout << "Anda ingin menambah data apa? /n" << endl;
    cout << "1. Mahasiswa " << endl;
    cout << "2. Dosen " << endl;
}

void pilihan3(){
    cout << "Anda ingin menghapus data apa? /n" << endl;
    cout << "1. Mahasiswa " << endl;
    cout << "2. Dosen " << endl;
}

void ClearScreen(){
    system("cls");
}
