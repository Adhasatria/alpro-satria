#include <iostream>
#include <cstdlib>
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




struct Karakter{
    char nama[50];
    int maxhp = 1500;
    int hp= maxhp;
    int atk=10;
    int def=10;
    int agi =12;
    int maxmp= 100;
    int mp=maxmp;
    int level=1;
    int maxexp= 150;
    int exp=0;

    void level_up(){
        while(exp>=maxexp){
            exp-= maxexp;
            level++;

            atk = atk * 130/ 100;
            agi= agi * 130 / 100;
            def= def * 130 / 100;
            maxhp= maxhp * 150 / 100;
            maxmp= maxmp * 150 / 100;

            hp=maxhp;
            mp=maxmp;

            cout<<"=================================================="<<endl;
            cout<<"     SELAMAT   "<<nama<<" KAMU TELAH NAIK LEVEL!!!"<<endl;
            cout<<"=================================================="<<endl;
        }
    }

};

struct Musuh{
    char nama[50];
    int maxhp;
    int hp;
    int atk;
    int def;
    int agi;
    bool hidup= true;

};

Musuh wilayahPride[4] = {
    {"Arrogant Soldier", 80, 80, 15, 5, 8},
    {"Noble Knight", 130, 130, 18, 7, 6},
    {"Fallen Champion", 160, 160, 22, 9, 10},
    {"King of Pride (Boss)", 450, 450, 30, 12, 12}
};

Musuh wilayahGreed[4] = {
    {"Gold Hoarder", 230, 230, 26, 10, 12},
    {"Corrupt Merchant", 240, 240, 30, 12, 15},
    {"Living Treasure", 300, 300, 24, 18, 5},
    {"Dragon of Greed (Boss)", 850, 850, 45, 25, 14}
};

Musuh wilayahWrath[4] = {
    {"Furious Beast", 380, 380, 50, 12, 18},
    {"Berserker", 450, 450, 60, 10, 17},
    {"Flame Demon", 420, 420, 62, 15, 16},
    {"Avatar of Wrath (Boss)", 1400, 1400, 90, 20, 24}
};

Musuh wilayahSloth[4] = {
    {"Lazy Undead", 600, 600, 42, 22, 4},
    {"Sleeping Giant", 950, 950, 65, 30, 2},
    {"Dream Spirit", 550, 550, 48, 18, 8},
    {"Lord of Sloth (Boss)", 2500, 2500, 75, 45, 5}
};

Musuh wilayahGluttony[4] = {
    {"Hungry Slime", 800, 800, 55, 30, 14},
    {"Devourer Beast", 1100, 1100, 70, 32, 16},
    {"Endless Maw", 1400, 1400, 65, 45, 10},
    {"Lord of Gluttony (Boss)", 3800, 3800, 95, 60, 15}
};

Musuh wilayahEnvy[4] = {
    {"Shadow Copy", 1600, 1600, 85, 40, 28},
    {"Mirror Spirit", 1400, 1400, 80, 48, 32},
    {"Shapeshifter", 1900, 1900, 90, 35, 26},
    {"Embodiment of Envy (Boss)", 5500, 5500, 120, 65, 35}
};

Musuh wilayahLust[4] = {
    {"Charming Spirit", 2400, 2400, 110, 45, 38},
    {"Siren", 2900, 2900, 105, 50, 39},
    {"Succubus", 3300, 3300, 115, 58, 42},
    {"Queen of Lust (Final Boss)", 10000, 10000, 160, 80, 50}
};

Karakter ksatria;

bool randomisasi(int agi){
    int acak = rand () % 100;
    return(acak < agi);
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
    cout << "+=============================================================================+\n";
    cout << "|                   Welcome to Abyssal Realm, adventurer.                     |\n";
    cout << "|                   The seven deadly sins await your challenge.               |\n";
    cout << "+=============================================================================+\n";

    cout << "[Enter your name]: ";
    cin >> ksatria.nama;
    cin.ignore(); 
    pressEnter();

}

void menu_utama(){
    int pilihan_stage;
    cout << "+=============================================================================+\n";
    cout << "|                         THE 7 DEADLY SINS ARE WAITING FOR YOU               |\n";
    cout << "+=============================================================================+\n";
    cout << "|                                   1. Pride                                  |\n";
    cout << "|                                   2. Greed                                  |\n";
    cout << "|                                   3. Wrath                                  |\n";
    cout << "|                                   4. Sloth                                  |\n";
    cout << "|                                   5. Gluttony                               |\n";
    cout << "|                                   6. Envy                                   |\n";
    cout << "|                                   7. Lust                                   |\n";
    cout << "|                                   8. EXIT                                   |\n";
    cout << "+=============================================================================+\n";
    cout << "[Choose your desired stage]: ";
}

int Battle_screen(Musuh &target) {
    int action;
    target.hp = target.maxhp; 
    for (int turn = 1; turn < 10000; turn++) {
        cout << "+=============================================================================+\n";
        cout << "|  ABYSSAL REALM                                                 TURN   " << turn << "   |\n";
        cout << "+=============================================================================+\n";
        cout << "| [" << ksatria.nama << "]                                                      Level " << ksatria.level << "\n";
        cout << "|   HP  : " << ksatria.hp << " / " << ksatria.maxhp << "\n";
        cout << "|   MP  : " << ksatria.mp << " / " << ksatria.maxmp << "\n";
        cout << "|   AGI : " << ksatria.agi << "\n";
        cout << "|   EXP : " << ksatria.exp << " / " << ksatria.maxexp << "\n";
        cout << "+-----------------------------------------------------------------------------+\n";
        cout << "| [" << target.nama << "]\n";
        cout << "|   HP  : " << target.hp << " / " << target.maxhp << "\n";
        cout << "|   AGI : " << target.agi << "\n";
        cout << "+=============================================================================+\n";
        cout << "|  1. Basic Attack     (No MP  |  100% ATK)                                   |\n";
        cout << "|  2. Heavy Attack     (30 MP  |  160% ATK  |  lower accuracy)                |\n";
        cout << "|  3. Heal             (20 MP  |  Restore 200 HP)                             |\n";
        cout << "|  4. Run Away         (Exit battle)                                          |\n";
        cout << "+=============================================================================+\n";
        cout << "[Choose action]: "; cin >> action;
        cin.ignore(); 

        int damageToEnemy = 0;
        bool playerValidAction = true;

        if (action == 1) {
            damageToEnemy = (ksatria.atk - target.def) + (rand() % 6);
            if (damageToEnemy < 1) damageToEnemy = 1;
            
            target.hp -= damageToEnemy;
            cout << "[Basic Attack] " << ksatria.nama << " hits " << target.nama << " for " << damageToEnemy << " damage.\n";
            clearScreen();;
        } 
        else if (action == 2) {
            if (ksatria.mp >= 30) {
                ksatria.mp -= 30;
                if (randomisasi(70)) {
                    damageToEnemy = ((ksatria.atk * 160/100) - target.def) + (rand() % 6);
                    if (damageToEnemy < 1) damageToEnemy = 1;
                    
                    target.hp -= damageToEnemy;
                    cout << "[Heavy Attack] " << ksatria.nama << " hits " << target.nama << " hard for " << damageToEnemy << " damage!\n";
                } else {
                    cout << "[Heavy Attack] " << ksatria.nama << "'s attack MISSED!\n";
                }
            } else {
                cout << " MP tidak cukup untuk Heavy Attack!\n";
                playerValidAction = false;
            } 
        } 
        else if (action == 3) {
            if (ksatria.mp >= 20) {
                ksatria.mp -= 20;
                ksatria.hp += 200;
                if (ksatria.hp > ksatria.maxhp) ksatria.hp = ksatria.maxhp;
                cout << "[Heal] " << ksatria.nama << " restores 200 HP.\n";
            } else {
                cout << " MP tidak cukup untuk Heal!\n";
                playerValidAction = false;
            }
        } 
        else if (action == 4) {
            cout << "You ran away from the battle safely.\n";
            pressEnter();
            return 2; 
        } 
        else {
            cout << " Pilihan aksi tidak valid!\n";
            playerValidAction = false;
        }

        if (target.hp < 0) target.hp = 0;
        
        if (target.hp == 0) {
            cout << "\n " << target.nama << " telah dikalahkan!\n";
            
            target.hidup = false; 

            int expDiberikan = 160;
            if (target.maxhp >= 450) expDiberikan = 600; 

            cout << "Mendapatkan " << expDiberikan << " EXP.\n";
            ksatria.exp += expDiberikan;
            
            ksatria.level_up();
            pressEnter();
            return 1; 
        }

        if (playerValidAction) {
            cout << "\n[" << target.nama << "] turn!\n";
            int hitRateMusuh = 85 - (ksatria.agi - target.agi);
            
            if (randomisasi(hitRateMusuh)) {
                int damageFromEnemy = target.atk - ksatria.def;
                if (damageFromEnemy < 5) damageFromEnemy = 5;
                
                ksatria.hp -= damageFromEnemy;
                if (ksatria.hp < 0) ksatria.hp = 0;

                cout << "[" << target.nama << "] attacked " << ksatria.nama << " for " << damageFromEnemy << " damage.\n";
            } else {
                cout << "[" << target.nama << "] attacked, but " << ksatria.nama << " dodges!\n";
            }
        }
        if (ksatria.hp == 0) {
            cout << "\n " << ksatria.nama << " telah gugur... GAME OVER.\n";
            pressEnter();
            return 0; 
        }

        pressEnter();
    }
    return 2;
}
void menu_wilayah( char namaWilayah[], Musuh (&daftarMusuh)[4]) {
    cout << "+=============================================================================+\n";
    cout << "| Welcome to the Territory of " << namaWilayah << ".\n";
    cout << "+=============================================================================+\n";
    for (int i = 0; i < 4; i++) {
        cout << "|   " << (i + 1) << ". " << daftarMusuh[i].nama;
        if (!daftarMusuh[i].hidup) {
            cout << " [DEFEATED]"; 
        }
        cout << "\n";
    }
    cout << "|   5. Retreat\n";
    cout << "+=============================================================================+\n";
    cout << "[Which path will you take?]: ";
}


int main(){

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
            system("pause");
            break;

            default:
            cout<<"Pilihan Menu Tidak Valid!"<<endl;

        }
    }while(pilihan_menu !=0);

    clearScreen();
    banner();
    int pilihan1;
    bool status_game = true;
    int perhitungan;

    while (status_game)
    {
        menu_utama();
        cin >> pilihan1;
        cin.ignore(); 
        clearScreen();;
        
        if (pilihan1 >= 1 && pilihan1 <= 7) {
            int pilihan2;
            if (pilihan1 == 1) menu_wilayah("Pride", wilayahPride);
            else if (pilihan1 == 2) menu_wilayah("Greed", wilayahGreed);
            else if (pilihan1 == 3) menu_wilayah("Wrath", wilayahWrath);
            else if (pilihan1 == 4) menu_wilayah("Sloth", wilayahSloth);
            else if (pilihan1 == 5) menu_wilayah("Gluttony", wilayahGluttony);
            else if (pilihan1 == 6) menu_wilayah("Envy", wilayahEnvy);
            else if (pilihan1 == 7) menu_wilayah("Lust", wilayahLust);

            cin >> pilihan2;
            cin.ignore();
            clearScreen();;

            if (pilihan2 >= 1 && pilihan2 <= 4) {
                int hasilBattle = 2;
                bool musuhSudahMati = false;
                if (pilihan1 == 1) {
                    if (!wilayahPride[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahPride[pilihan2 - 1]);
                }
                else if (pilihan1 == 2) {
                    if (!wilayahGreed[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahGreed[pilihan2 - 1]);
                }
                else if (pilihan1 == 3) {
                    if (!wilayahWrath[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahWrath[pilihan2 - 1]);
                }
                else if (pilihan1 == 4) {
                    if (!wilayahSloth[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahSloth[pilihan2 - 1]);
                }
                else if (pilihan1 == 5) {
                    if (!wilayahGluttony[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahGluttony[pilihan2 - 1]);
                }
                else if (pilihan1 == 6) {
                    if (!wilayahEnvy[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahEnvy[pilihan2 - 1]);
                }
                else if (pilihan1 == 7) {
                    if (!wilayahLust[pilihan2 - 1].hidup) musuhSudahMati = true;
                    else hasilBattle = Battle_screen(wilayahLust[pilihan2 - 1]);
                }

                if (musuhSudahMati) {
                    cout << "---------------------------------------------------------\n";
                    cout << " Musuh tersebut sudah mati! Silakan pilih tantangan lain.\n";
                    cout << "---------------------------------------------------------\n";
                    pressEnter();
                    continue;
                }
                
                if (hasilBattle == 0) {
                    status_game = false; 
                }
                clearScreen();;
            } else if (pilihan2 == 5) {
                cout << "Retreating to main menu...\n";
                pressEnter();
            } else {
                cout << " Pilihan jalan tidak valid!\n";
                pressEnter();
            }
        } 
        else if (pilihan1 == 8) {
            cout << "Keluar dari game. Sampai jumpa, Adventurer!\n";
            return 0;
        } 
        else {
            cout << " Pilihan stage tidak valid!\n";
            pressEnter();
        }

    }
    
    return 0;
}