#include <iostream>
using namespace std;

struct Tanggal_masuk{
    int hari;
    int bulan;
    int tahun;
    };
struct Tanggal_lahir{
        int tanggal;
        int bulan;
        int tahun;
    };
    
struct Alergi{
        string alergen[5];
        string reaksi[5];
    };
    
struct Alamat{
    string jalan;
    string kelurahan;
    string kota;
    string provinsi;
    string kode_pos;
    };


struct Identitas{
    int id;
    string nik;
    string nama;
    char jenis_kelamin;
    char gol_darah;
    string no_telpon;
    char bpjs;
    Tanggal_lahir tgl;
    Alamat alamat;
    Alergi alergi;
    int jumlah_alergi;
    Tanggal_masuk tgl_masuk;
};

const int MAX=100;
int jumlah_pasien_aktif=0;
Identitas database_rs[MAX];
int counter_id_pasien=1;
int pilihan_menu;


void clearScreen() {
    cout << "\033[2J\033[H";
}

void pressEnter() {
    cout << "Press ENTER to continue...";
    cin.ignore();
    cin.get();
}
void pendaftaran_pasien(Identitas &pasien, int id_sekarang){
    pasien.id=id_sekarang;
    
    cout << "=== PENDAFTARAN PASIEN BARU ===" << endl;
    cout<<"NIK (16 digit)   :";cin>>pasien.nik;
    cout<<"Nama             :";getline(cin >> ws, pasien.nama);
    cout<<"Tgl Lahir "<<endl;
    cout<<"      Tanggal :";cin>>pasien.tgl.tanggal;
    cout<<"      Bulan :";cin>>pasien.tgl.bulan;
    cout<<"      Tahun :";cin>>pasien.tgl.tahun;
    cout<<"Jenis Kelamin    (l/p):";cin>>pasien.jenis_kelamin;
    cout<<"Gol. Darah    :";cin>>pasien.gol_darah;
    cout<<"No. Telp      :";cin>>pasien.no_telpon;
    cout<<"Alamat    "<<endl;
    cout<<"     Jalan    :";cin>>pasien.alamat.jalan;
    cout<<"     Kelurahan    :";cin>>pasien.alamat.kelurahan;
    cout<<"     Kota    :";cin>>pasien.alamat.kota;
    cout<<"     provinsi    :";cin>>pasien.alamat.provinsi;
    cout<<"     Kode Pos    :";cin>>pasien.alamat.kode_pos;
    cout<<"Peserta BPJS (y/n)    :";cin>>pasien.bpjs;

    cout<<"      Tanggal Masuk :";cin>>pasien.tgl_masuk.hari;
    cout<<"      Bulan Masuk:";cin>>pasien.tgl_masuk.bulan;
    cout<<"      Tahun MAsuk:";cin>>pasien.tgl_masuk.tahun;
    cout<<"Jumlah Alergi (0-5)    :";cin>>pasien.jumlah_alergi;
    
    cin.ignore();
    for(int i=0; i<pasien.jumlah_alergi; i++){
        cout << "[Alergi " << i+1 << "]" << endl;
        cout << " Alergen:   ";getline(cin, pasien.alergi.alergen[i]);
        cout << " Reaksi:   ";getline(cin, pasien.alergi.reaksi[i]);

    }
    cout << "[OK] Pasien ID-" << pasien.id << " berhasil didaftarkan!" << endl;
}   
int tampilan_awal(){
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
    cout<<"Masukkan Pilihan :";cin>>pilihan;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        pilihan=-1;
    }
    return pilihan;
}
void lihat_pasien(Identitas daftar_pasien[], int jumlah_aktif){
    cout<<"========================================================="<<endl;
    cout<<"                      LIHAT SEMUA PASIEN                 "<<endl;
    cout<<"========================================================="<<endl;
    if (jumlah_pasien_aktif==0){
        cout<<"Saat Ini Sedang Tidak Ada Pasien!!"<<endl;
    }else{
        for(int i=0; i<jumlah_aktif; i++){
            cout<<"NIK (16 Digit):\t"<<daftar_pasien[i].nik<<endl;
            cout<<"Nama \t:"<<daftar_pasien[i].nama<<endl;
            cout<<"Tgl Lahir "<<endl;
            cout<<"      Tanggal :"<<daftar_pasien[i].tgl.tanggal<<endl;
            cout<<"      Bulan :"<<daftar_pasien[i].tgl.bulan<<endl;
            cout<<"      Tahun :"<<daftar_pasien[i].tgl.tahun<<endl;
            cout<<"Jenis Kelamin    :"<<daftar_pasien[i].jenis_kelamin<<endl;
            cout<<"Gol. Darah    :"<<daftar_pasien[i].gol_darah<<endl;
            cout<<"No. Telp      :"<<daftar_pasien[i].no_telpon<<endl;
            cout<<"Alamat    "<<endl;
            cout<<"     Jalan    :"<<daftar_pasien[i].alamat.jalan<<endl;
            cout<<"     Kelurahan    :"<<daftar_pasien[i].alamat.kelurahan<<endl;
            cout<<"     Kota    :"<<daftar_pasien[i].alamat.kota<<endl;
            cout<<"     provinsi    :"<<daftar_pasien[i].alamat.provinsi<<endl;
            cout<<"     Kode Pos    :"<<daftar_pasien[i].alamat.kode_pos<<endl;
            cout<<"Peserta BPJS (y/n)    :"<<daftar_pasien[i].bpjs<<endl;
            cout<<"      Tanggal Masuk :"<<daftar_pasien[i].tgl_masuk.hari<<endl;
            cout<<"      Bulan Masuk:"<<daftar_pasien[i].tgl_masuk.bulan<<endl;
            cout<<"      Tahun MAsuk:"<<daftar_pasien[i].tgl_masuk.tahun<<endl;
            cout<<"Jumlah Alergi (0-5)    :"<<daftar_pasien[i].jumlah_alergi<<endl;
            
        for(int j=0; j<daftar_pasien[i].jumlah_alergi; j++){
        cout << "[Alergi " << j+1 << "]" << endl;
        cout << " Alergen :   "<<daftar_pasien[i].alergi.alergen[j]<<endl;
        cout << " Reaksi :   "<<daftar_pasien[i].alergi.reaksi[j]<<endl;
            }
        cout << "--------------------------------------------------" << endl;
        }
    }
}

void cari_pasien(Identitas daftar_pasien[], int jumlah_pasien_aktif){
    string cari;
    bool ketemu=false;
    cout<<"========================================================="<<endl;
    cout<<"                      CARI PASIEN                 "<<endl;
    cout<<"========================================================="<<endl;
    if (jumlah_pasien_aktif==0){
        cout<<"Saat Ini Sedang Tidak Ada Pasien!!"<<endl;
    }else{
        cout<<"Masukkan Nama Pasien :";cin.ignore(); getline(cin, cari);
        for (int i = 0; i < jumlah_pasien_aktif; i++)
        {
               if(cari==daftar_pasien[i].nama){
                    cout<<"NIK (16 Digit):\t"<<daftar_pasien[i].nik<<endl;
                    cout<<"Nama \t:"<<daftar_pasien[i].nama<<endl;
                    cout<<"Tgl Lahir "<<endl;
                    cout<<"      Tanggal :"<<daftar_pasien[i].tgl.tanggal<<endl;
                    cout<<"      Bulan :"<<daftar_pasien[i].tgl.bulan<<endl;
                    cout<<"      Tahun :"<<daftar_pasien[i].tgl.tahun<<endl;
                    cout<<"Jenis Kelamin    :"<<daftar_pasien[i].jenis_kelamin<<endl;
                    cout<<"Gol. Darah    :"<<daftar_pasien[i].gol_darah<<endl;
                    cout<<"No. Telp      :"<<daftar_pasien[i].no_telpon<<endl;
                    cout<<"Alamat    "<<endl;
                    cout<<"     Jalan    :"<<daftar_pasien[i].alamat.jalan<<endl;
                    cout<<"     Kelurahan    :"<<daftar_pasien[i].alamat.kelurahan<<endl;
                    cout<<"     Kota    :"<<daftar_pasien[i].alamat.kota<<endl;
                    cout<<"     provinsi    :"<<daftar_pasien[i].alamat.provinsi<<endl;
                    cout<<"     Kode Pos    :"<<daftar_pasien[i].alamat.kode_pos<<endl;
                    cout<<"Peserta BPJS (y/n)    :"<<daftar_pasien[i].bpjs<<endl;
                    cout<<"Jumlah Alergi (0-5)    :"<<daftar_pasien[i].jumlah_alergi<<endl;
                    cout<<"      Tanggal Masuk :"<<daftar_pasien[i].tgl_masuk.hari<<endl;
                    cout<<"      Bulan Masuk:"<<daftar_pasien[i].tgl_masuk.bulan<<endl;
                    cout<<"      Tahun MAsuk:"<<daftar_pasien[i].tgl_masuk.tahun<<endl;
                    for(int j=0; j<daftar_pasien[i].jumlah_alergi; j++){
                        cout << "[Alergi " << j+1 << "]" << endl;
                        cout << " Alergen :   "<<daftar_pasien[i].alergi.alergen[j]<<endl;
                        cout << " Reaksi :   "<<daftar_pasien[i].alergi.reaksi[j]<<endl;
                    }
                    ketemu=true;
                system("pause");
                break;
               }
        }
        if(!ketemu){
                cout<<"Pasien yang anda cari sudah Meninggal!!!"<<endl;
                system("pause");
            }
        
    }
}
long hitung_hari(int hari, int bulan, int tahun){
    int hari_bulan[13] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    long total = tahun* 365 + hari;
    for(int i=0; i< bulan; i++){
        total += hari_bulan[i];
    }
    return total;
}
void hapus_pasien(Identitas daftar_pasien[]){
    int pass=0;
    char balik;
    int hari=21; int bulan=5; int tahun =2026;
    int tarif_perhari=75000;

    cout<<"========================================================="<<endl;
    cout<<"                      HAPUS/PULANGKAN PASIEN                 "<<endl;
    cout<<"========================================================="<<endl;
    if(jumlah_pasien_aktif==0){
        cout<<"Belum ad apasien yang terdaftar "<<endl;
        system("pause");
        return;
    }
    cout<<"Daftar Pasien "<<endl;
    cout<<"------------------------------------------------------"<<endl;
    for (int i=0; i<jumlah_pasien_aktif; i++){
        cout<<"ID ["<<i+1<<"]"<<daftar_pasien[i].nama<<endl;
    }
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Masukkan ID Pasien yang Ingin Dipulangkan "; cin>>pass;
    if(pass>0 && pass<=jumlah_pasien_aktif){
        cout<<"========================================================="<<endl;
        cout<<"                      RINCIAN TAGIHAN                 "<<endl;
        cout<<"========================================================="<<endl;
        int hari_masuk=hitung_hari(daftar_pasien[pass-1].tgl_masuk.hari, daftar_pasien[pass-1].tgl_masuk.bulan, daftar_pasien[pass-1].tgl_masuk.tahun);
        int hari_keluar=hitung_hari(hari, bulan, tahun);
        int lama_rawat=hari_keluar-hari_masuk;
        int total_biaya;
        cout<<"Nama :"<<daftar_pasien[pass-1].nama<<endl;
        cout<<"NIK :"<<daftar_pasien[pass-1].nik<<endl;
            if(daftar_pasien[pass-1].bpjs== 'y' || daftar_pasien[pass-1].bpjs== 'Y'){
                total_biaya=0;
                }
            else{
                total_biaya= tarif_perhari*lama_rawat;
                }
            if (daftar_pasien[pass-1].bpjs== 'y' || daftar_pasien[pass-1].bpjs== 'Y')
                {
                cout<<"BPJS: Menggunakan BPJS sehingga harga 0 rupiah"<<endl;
            }else{
            cout<<"BPJS: Tidak pakai BPJS"<<endl;
                }
            cout<<"Tanggal Masuk : "<<daftar_pasien[pass-1].tgl_masuk.hari<<"/"<<daftar_pasien[pass-1].tgl_masuk.bulan<<"/"<<daftar_pasien[pass-1].tgl_masuk.tahun<<endl;
            cout<<"Tanggal Keluar : "<<hari<<"/"<<bulan<<"/"<<tahun<<endl;
            cout<<"Lama Rawat : "<<lama_rawat<<" hari"<<endl;
            cout<<"Tarif Perhari : (Rp) "<<tarif_perhari<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"Total Biaya : (Rp) "<<total_biaya<<endl;
            cout<<"Pembayaran Harus Dilakukan Sebelum Memulangkan Pasien, Yakin Memulangkan Pasien? (y/n) ";cin>>balik;
                if(balik=='y'|| balik=='Y'){
                    for(int i=jumlah_pasien_aktif; i<jumlah_pasien_aktif-1; i++){
                        daftar_pasien[i]=daftar_pasien[i+1];
                    }
                    jumlah_pasien_aktif--;
                    cout<<"[OK] Pasien ID"<<pass<<" Telah Dpulangkan"<<endl;
                    cout<<"Sisa Pasien Terdaftar :"<<jumlah_pasien_aktif<<endl;
                }else{
                    cout<<"Pasien Tidak Jadi Dipulangkan"<<endl;
                }

    }else{
        cout<<"Pasien Tidak Ditemukan !!!"<<endl;
    }
}


int main(){

    string tgl=" Tanggal 21/5/2026";
    do{
        clearScreen();
        pilihan_menu=tampilan_awal();

        switch(pilihan_menu){
            case 1:
            clearScreen();
            if(jumlah_pasien_aktif< MAX){
                pendaftaran_pasien(database_rs[jumlah_pasien_aktif], counter_id_pasien);
                jumlah_pasien_aktif++;  
            }else{
            }
            break;
        
        case 2:
            clearScreen();
            lihat_pasien(database_rs, jumlah_pasien_aktif);
            pressEnter();
            break;

            case 3:
            clearScreen();
            cari_pasien(database_rs, jumlah_pasien_aktif);
            pressEnter();
            break;

            case 4:
            clearScreen();
            hapus_pasien(database_rs);

            pressEnter();
            break;

            case 0:
            cout<<"Keluar Dari Sistem Terimakasih"<<endl;
            break;

            default:
            cout<<"Pilihan Menu Tidak Valid!"<<endl;

        }
    }while(pilihan_menu !=0);
    return 0;
}