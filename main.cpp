#include <iostream>
#include "MLL.h"
#include <cstdlib>

using namespace std;

int main(){
    int isi = -1;
    listDsn D;
    listMhs M;
    listRelasi R;

    createListDsn(D);
    createListMhs(M);
    createListRls(R);

    adrDsn d;
    adrMhs m;

    m = createElmMhs("Muhammad Zainul Alif",103012300481,"IF-47-05");
    insertFirstM(M,m);
     m = createElmMhs("Muhammad Raffa",103012300021,"IF-47-06");
    insertFirstM(M,m);
     m = createElmMhs("Rafif Rabhani",103012300890,"IF-47-INT");
    insertFirstM(M,m);
     m = createElmMhs("Billy Steven Naibaho",103012300606,"IF-47-03");
    insertFirstM(M,m);
     m = createElmMhs("Najwa Hakim Tianisa",103012300880,"IF-47-06");
    insertFirstM(M,m);
     m = createElmMhs("Putri Cantika Lestari",103012300009,"IF-47-01");
    insertFirstM(M,m);
     m = createElmMhs("Gunawan Hendra Pradiaksa",103012300789,"IF-47-04");
    insertFirstM(M,m);
     m = createElmMhs("Tabitha Rachelya Marybeth Tenda",103012300010,"IF-47-05");
    insertFirstM(M,m);

    d = createElmDsn("Faisal Susanto","PEY","Matriks dan Ruang Vektor");
    insertLastD(D,d);
    d = createElmDsn("Lastry Gala","LSG","Bahasa Indonesia");
    insertLastD(D,d);
    d = createElmDsn("Nur Hasanah","NRH","Kalkulus");
    insertLastD(D,d);
    d = createElmDsn("Abdullah","ABD","Struktur Data");
    insertLastD(D,d);

    connect(R,D,M,"NRH",103012300481);
    connect(R,D,M,"NRH",103012300010);
    connect(R,D,M,"NRH",103012300009);

    connect(R,D,M,"PEY",103012300021);
    connect(R,D,M,"PEY",103012300789);

    connect(R,D,M,"ABD",103012300890);
    connect(R,D,M,"ABD",103012300880);

    connect(R,D,M,"LSG",103012300606);
    ClearScreen();
    while (isi != 0){
        ClearScreen();
        mainMenu();
        cout << "Masukan Pilihan Anda : ";
        cin >> isi;
        if (isi == 1){
            int a;
            pilihan1();
            cout << "Masukan Pilihan Anda : ";
            cin >> a;
            if(a == 1){
                string nama,kelas,pilihan;
                int NIM;
                cout << "Masukan Nama Anda: ";
                cin.ignore();
                getline(cin,nama);
                cout << "Masukan NIM Anda: ";
                cin >> NIM;
                cout << "Masukan Kelas Anda: ";
                cin >> kelas;
                adrMhs mhs = createElmMhs(nama,NIM,kelas);
                insertFirstM(M,mhs);
                cout << "Data Berhasil Ditambahkan!" << endl;

                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();

            }else if(a == 2){
                string nama, kode, matkul;
                cout << "Masukan Nama Dosen: ";
                cin.ignore();
                getline(cin,nama);
                cout << "Masukan Kode Dosen: ";
                cin >> kode;
                cout << "Masukan Mata Kuliah yang Dosen Ajar: ";
                cin.ignore();
                getline(cin,matkul);
                adrDsn dsn = createElmDsn(nama,kode,matkul);
                insertLastD(D,dsn);
                cout << "Data Dosen Berhasil Ditambahkan! " << endl;

                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();
            }
        }else if(isi == 2){
            string kode1,kode2;
            int pilih, NIM;
            bool as = true;
            printAllDataDsn(D,R,as);
            cout << "\nSilahkan Anda Pilih Dosen Yang Anda inginkan" << endl;
            cout << "(MAX 2 Dosen dan tolong tulis kode dosen sesuai dangan apa yang ditampilkan diatas)" << endl;
            cout << "Anda ingin memilih berapa dosen 1/2 ? ";
            cout << "Masukan pilihan anda: ";
            cin >> pilih;
            if(pilih == 1){
                cout << "Masukan Kode Dosen yang anda pilih: ";
                cin >> kode1;
                cout << "Masukan Juga NIM anda: ";
                cin >> NIM;
                connect(R,D,M,kode1,NIM);

                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();
            }else if(pilih == 2){
                cout << "Masukan Kode Dosen Pertama yang anda pilih: ";
                cin >> kode1;
                cout << "Masukan Kode Dosen Kedua yang anda pilih: ";
                cin >> kode2;
                cout << "Masukan Juga NIM anda: ";
                cin >> NIM;
                connect(R,D,M,kode1,NIM);
                connect(R,D,M,kode2,NIM);
                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();
            }else {
                cout << "Pilihan Tidak Ada " << endl;
                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();
            }

        }else if(isi == 3){
            int pilih;
            pilihan3();
            cout << "Masukan pilihan anda: ";
            cin >> pilih;
            if(pilih == 1){
                int a;
                cout << "Anda ingin menghapus data pertama atau terakhir " << endl;
                cout << "1. pertama" << endl;
                cout << "2. terakhir\n" << endl;
                cout << "Masukan Pilihan Anda: ";
                cin >> a;
                if(a == 1){
                    deleteFirstMhs(M,R);
                }else if(a == 2){
                    deleteLastMhs(M,R);
                }else {
                    cout << "Pilihan Tidak Ada" << endl;
                }
                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();
            }else if(pilih == 2){
                int b;
                cout << "Anda ingin menghapus data pertama atau terakhir " << endl;
                cout << "1. pertama" << endl;
                cout << "2. terakhir\n" << endl;
                cout << "Masukan Pilihan Anda: ";
                cin >> b;
                if(b == 1){
                    deleteFirstDsn(D,R);
                }else if(b == 2){
                    deleteLastDsn(D,R);
                }
                cout << "Tekan Enter untuk kembali ke menu utama ";
                cin.ignore();
                cin.get();
            }
        }else if(isi == 4){
            int subOption;
            cout << "Pilih salah satu opsi untuk melihat data: " << endl;
            cout << "1. Lihat Dosen" << endl;
            cout << "2. Lihat Mahasiswa" << endl;
            cout << "3. Lihat Semua (Dosen & Mahasiswa)" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> subOption;

            if(subOption == 1){
                printAllDataDsn(D, R, true);
            } else if(subOption == 2){
                printAllDataMhs(M, R);
            } else if(subOption == 3){
                printAllDataMhs(M, R);
                printAllDataDsn(D, R, true);
            } else {
                cout << "Pilihan Tidak Ada!" << endl;
            }
        }else if(isi == 5){
            int pilih;
            cout << "Pilih opsi untuk melihat hubungan:" << endl;
            cout << "1. Berdasarkan Kode Dosen" << endl;
            cout << "2. Berdasarkan NIM Mahasiswa" << endl;
            cout << "Masukkan pilihan Anda: ";
            cin >> pilih;

            if (pilih == 1) {
                string kode;
                cout << "Masukkan Kode Dosen untuk melihat mahasiswa yang terhubung: ";
                cin >> kode;
                findRelasiDosen(R, kode);
            } else if (pilih == 2) {
                int NIM;
                cout << "Masukkan NIM Mahasiswa untuk melihat dosen yang terhubung: ";
                cin >> NIM;
                findRelasiMhs(R, NIM);
            } else {
                cout << "Pilihan tidak valid!" << endl;
            }
        }else if(isi == 0){
            break;
        }
    }
    return 0;
}
