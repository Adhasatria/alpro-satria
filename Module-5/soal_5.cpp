#include <iostream>
using namespace std;

const int MAX=100;

struct Tanggal_lahir{
        int tanggal;
        int bulan;
        int tahun;
    };
    
struct Alergi{
        string alergen;
        string reaksi;
    };
    
struct Alamat{
    string jalan;
    string kelurahan;
    string provinsi;
    string kode_pos;
    };


struct Identitas{
    string nik;
    string nama;
    char jenis_kelamin;
    char gol_darah;
    string no_telpon;
    char bpjs;
    Tanggal_lahir tgl;
    Alamat alamat;
    Alergi alergi;

};

void clearScreen() {
    cout << "\033[2J\033[H";
}

void banner(){
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|      _    _                         _   ____            _             |" << endl;
    cout << "|     / \\  | |__  _   _ ___ ___  __ _| | |  _ \\ ___  __ _| |_ __ ___    |" << endl;
    cout << "|    / _ \\ | '_ \\| | | / __/ __|/ _` | | | |_) / _ \\/ _` | | '_ ` _ \\   |" << endl;
    cout << "|   / ___ \\| |_) | |_| \\__ \\__ \\ (_| | | |  _ <  __/ (_| | | | | | | |  |" << endl;
    cout << "|  /_/   \\_\\_.__/ \\__, |___/___/\\__,_|_| |_| \\_\\___|\\__,_|_|_| |_| |_|  |" << endl;
    cout << "|                 |___/                                                 |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
}

void pressEnter() {
    cout << "Press ENTER to continue...";
    cin.ignore();
    cin.get();
}
void pendaftaran_pasien(Identitas id){
    cout<<"NIK (16 digit)   :";cin>>id.nik;
    cout<<"Nama             :";cin>>id.nama;
    cout<<"Tgl Lahir "<<endl;
    cout<<"      Tanggal :";cin>>id.
    cout<<"      Bulan :";
    cout<<"      Tahun :";
}
void tampilan_awal(){
    bool perulangan=false;
    cout<<"========================================================="<<endl;
    cout<<"            SISTEM MANAJEMEN RS GAZACARE PLUS             "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"                                           Tanggal 21/5/2026"<<endl;
    cout<<" [1]  Daftarkan Pasien Baru"<<endl;
    cout<<" [2]  Lihat Semua Pasien"<<endl;
    cout<<" [3]  Cari Pasien"<<endl;
    cout<<" [4]  Pulangkan Pasien"<<endl;
    cout<<" [0]  Keluar"<<endl;

    int pilihan;
    cout<<"Pilihan";cin>>pilihan;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '/n');
    }
}



int main(){
    string tgl=" Tanggal 21/5/2026";
    return 0;
}