#include <iostream>
using namespace std;

void banner(string judul){
    cout<<"#=============================#"<<endl;
    cout<<"|          "<<judul<<"         |"<<endl;
    cout<<"#=============================#"<<endl;
}

void banner_store(){
    cout << "#=============================================#" << endl;
    cout << "[              TIVAIZ STORE                   ]" << endl;
    cout << "#=============================================#" << endl;
    cout << "1.Input barang" << endl;
    cout << "2.Hapus barang" << endl;
    cout << "3.Edit barang" << endl;
    cout << "4.Lihat barang" << endl;
    cout << "0.Kembali" << endl;
    cout <<"=====================================================" << endl;
    cout << "Pilih menu: ";
}

void garis_dua(){
    cout<<"==============================="<<endl;
}

void garis_satu(){
    cout<<"-------------------------------"<<endl;
}

void modul4(){
    cout << R"(
|==================================|
|                                  |
[       MODULE 4 - FUNCTION        ]
|                                  |
|==================================|
1. TIVAIZ Store
2. Kalkulator Tivaiz
0. Keluar )";
    cout<<endl;
}

void penjumlahhan(int angka1, int angka2){
    int hasil = angka1+angka2;
    cout<<angka1<<" + "<<angka2<<" = "<<hasil<<endl;
}

void pengurangan(int angka1, int angka2){
    int hasil = angka1-angka2;
    cout<<angka1<<" - "<<angka2<<" = "<<hasil<<endl;
}

void perkalian(int angka1, int angka2){
    int hasil = angka1*angka2;
    cout<<angka1<<" * "<<angka2<<" = "<<hasil<<endl;
}

void pembagian(double angka1, double angka2){
    if(angka2==0){
        cout<<"[Gagal] Tidak bisa dibagi nol!"<<endl;
    } else {
        double hasil = angka1/angka2;
        cout<<angka1<<" / "<<angka2<<" = "<<hasil<<endl;
    }
}

int faktorial(int angka1){
    if(angka1==0) return 1;
    return angka1*faktorial(angka1-1);
}

void tambah_barang(string daftar_barang[], int indeks_tambah, string input_nama){
    daftar_barang[indeks_tambah] = input_nama;
}

void harga_barang(int daftar_harga[], int indeks_harga, int input_harga){
    daftar_harga[indeks_harga] = input_harga;
}

void jumlah_barang(int daftar_stok[], int indeks_jumlah, int input_jumlah){
    daftar_stok[indeks_jumlah] = input_jumlah;
}

void hapus_barang(string daftar_barang[], int daftar_harga[], int daftar_stok[], int &total_data, int indeks_hapus){
    for(int i = indeks_hapus; i < total_data-1; i++){
        daftar_barang[i] = daftar_barang[i+1];
        daftar_harga[i]  = daftar_harga[i+1];
        daftar_stok[i]   = daftar_stok[i+1];
    }
    total_data--;
}

void editHarga(int &harga, string nama_barang){
    int harga_baru;
    cout<<"Harga baru (Rp): ";
    cin>>harga_baru;
    if(cin.fail()){
        cin.clear(); 
        cin.ignore(1000,'\n');
        cout<<"[Gagal] Input harus berupa angka!"<<endl;
        return;
    }
    cout<<"[Berhasil] Harga "<<nama_barang<<": Rp "<<harga<<" -> Rp "<<harga_baru<<endl;
    harga = harga_baru;
}

void tambah_stok(int &stok, string nama_barang){
    int tambah;
    cout<<"Jumlah tambah: ";
    cin>>tambah;
    if(cin.fail()){
        cin.clear(); cin.ignore(1000,'\n');
        cout<<"[Gagal] Input harus berupa angka!"<<endl;
        return;
    }
    int stok_lama = stok;
    stok += tambah;
    cout<<"[Berhasil] Stok "<<nama_barang<<": "<<stok_lama<<" -> "<<stok<<endl;
}

void kurangi_stok(int &stok, string nama_barang){
    int kurang;
    cout<<"Jumlah kurang: ";
    cin>>kurang;
    if(cin.fail()){
        cin.clear(); cin.ignore(1000,'\n');
        cout<<"[Gagal] Input harus berupa angka!"<<endl;
        return;
    }
    if(stok-kurang < 1){
        cout<<"[Gagal] Stok minimal 1!"<<endl;
        cout<<"Stok saat ini : "<<stok<<endl;
        cout<<"Maks dikurangi: "<<stok-1<<endl;
        return;
    }
    int stok_lama = stok;
    stok -= kurang;
    cout<<"[Berhasil] Stok "<<nama_barang<<": "<<stok_lama<<" -> "<<stok<<endl;
}

void tampilkan_konfirmasi_input(string nama_barang, int stok_barang, int harga_brang, int total_barang){
    cout << "#=======================================#" << endl;
    cout << "|            TIVAIZ STORE               |" << endl;
    cout << "#=======================================#" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "             INPUT BARANG                " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "NAMA BARANG   : " << nama_barang << endl;
    cout << "JUMLAH BARANG : " << stok_barang << endl;
    cout << "HARGA BARANG  : " << harga_brang << endl;
    cout << "-----------------------------------------" << endl;
    cout << "[BERHASIL!!] " << nama_barang << " ditambahkan! (Total: " << total_barang << ")" << endl;
}

int main(){
    int pilihan_awal;
    int pilihan_toko;
    int pilihan_kalulator;
    int pilihan_edit;
    char pilihan_kalkulator2;
    int angka_awal;
    int angka_akhir;
    bool ulang_utama = true;
    bool ulang_sub;
    bool ulang_edit;

    string daftar_barang[100];
    int daftar_harga[100];
    int daftar_stok[100];
    int total_data = 0;

    do {
        system("cls");
        modul4();
        cout<<"masukkan pilihan menu : ";
        cin>>pilihan_awal;

        if(cin.fail()){
            cin.clear(); cin.ignore(1000,'\n');
            cout<<"[Gagal] Input harus berupa angka!"<<endl;
            system("pause");
            continue;
        }

        if(pilihan_awal == 1){
            ulang_sub = true;
            do {
                system("cls");
                banner_store();
                cin>>pilihan_toko;

                if(cin.fail()){
                    cin.clear(); cin.ignore(1000,'\n');
                    cout<<"[Gagal] Input harus berupa angka!"<<endl;
                    system("pause");
                    ulang_sub = true;
                    continue;
                }

                if(pilihan_toko < 0 || pilihan_toko > 4){
                    cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 4."<<endl;
                    system("pause");
                    ulang_sub = true;
                    continue;
                }

                if(pilihan_toko == 0){
                    ulang_sub = false;

                } else if(pilihan_toko == 1){
                    system("cls");
                    cout<<"#=======================================#"<<endl;
                    cout<<"|            TIVAIZ STORE               |"<<endl;
                    cout<<"#=======================================#"<<endl;
                   garis_satu();
                    cout<<"             INPUT BARANG                "<<endl;
                    garis_satu();

                    string input_nama;
                    int input_stok, input_harga;

                    cout<<"Nama Barang  : ";
                    cin.ignore();
                    getline(cin, input_nama);

                    cout<<"Stok (unit)  : ";
                    cin>>input_stok;
                    if(cin.fail()){
                        cin.clear(); cin.ignore(1000,'\n');
                        cout<<"[Gagal] Stok harus berupa angka!"<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    cout<<"Harga (Rp)   : ";
                    cin>>input_harga;
                    if(cin.fail()){
                        cin.clear(); cin.ignore(1000,'\n');
                        cout<<"[Gagal] Harga harus berupa angka!"<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    tambah_barang(daftar_barang, total_data, input_nama);
                    jumlah_barang(daftar_stok,   total_data, input_stok);
                    harga_barang(daftar_harga,   total_data, input_harga);
                    total_data++;

                    tampilkan_konfirmasi_input(input_nama, input_stok, input_harga, total_data);
                    system("pause");
                    ulang_sub = true;

                } else if(pilihan_toko == 2){
                    system("cls");
                    cout<<"#=======================================#"<<endl;
                    cout<<"|            TIVAIZ STORE               |"<<endl;
                    cout<<"#=======================================#"<<endl;
                    cout<<"-----------------------------------------"<<endl;
                    cout<<"             HAPUS BARANG                "<<endl;
                    cout<<"-----------------------------------------"<<endl;

                    if(total_data == 0){
                        cout<<"[Info] Tidak ada barang di toko."<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    for(int i=0; i<total_data; i++){
                        cout<<endl;
                        cout<<"No           : "<<i+1<<endl;
                        cout<<"Nama Barang  : "<<daftar_barang[i]<<endl;
                        cout<<"Stok Barang  : "<<daftar_stok[i]<<endl;
                        cout<<"Harga/Stok   : Rp "<<daftar_harga[i]<<endl;
                        garis_satu();
                    }

                    int pilihan_hapus;
                    cout<<"Pilih nomor barang yang dihapus ";
                    cin>>pilihan_hapus;

                    if(cin.fail()){
                        cin.clear(); cin.ignore(1000,'\n');
                        cout<<"[Gagal] Input harus berupa angka!"<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    if(pilihan_hapus < 1 || pilihan_hapus > total_data){
                        cout<<"[Gagal] Nomor "<<pilihan_hapus<<" tidak valid! Pilih antara 1 sampai "<<total_data<<"."<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    string nama_hapus = daftar_barang[pilihan_hapus-1];
                    hapus_barang(daftar_barang, daftar_harga, daftar_stok, total_data, pilihan_hapus-1);
                    cout<<"[Berhasil] "<<nama_hapus<<" dihapus! (Total barang: "<<total_data<<")"<<endl;
                    system("pause");
                    ulang_sub = true;

                } else if(pilihan_toko == 3){
                    system("cls");
                    cout<<"#=======================================#"<<endl;
                    cout<<"|            TIVAIZ STORE               |"<<endl;
                    cout<<"#=======================================#"<<endl;
                    garis_satu();
                    cout<<"             EDIT BARANG                 "<<endl;
                    garis_satu();

                    if(total_data == 0){
                        cout<<"[Info] Tidak ada barang di toko."<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    for(int i=0; i<total_data; i++){
                        cout<<endl;
                        cout<<"No           : "<<i+1<<endl;
                        cout<<"Nama Barang  : "<<daftar_barang[i]<<endl;
                        cout<<"Stok Barang  : "<<daftar_stok[i]<<endl;
                        cout<<"Harga/Stok   : Rp "<<daftar_harga[i]<<endl;
                        garis_satu();
                    }

                    cout<<"Pilih nomor barang yang diedit : ";
                    cin>>pilihan_edit;

                    if(pilihan_edit < 1 || pilihan_edit > total_data){
                        cout<<"[Gagal] Nomor "<<pilihan_edit<<" tidak valid! Pilih antara 1 sampai "<<total_data<<"."<<endl;
                        system("pause");
                        ulang_sub = true;
                        continue;
                    }

                    int opsi;
                    ulang_edit = true;

                    do {
                        system("cls");
                        cout<<"#=======================================#"<<endl;
                        cout<<"|            TIVAIZ STORE               |"<<endl;
                        cout<<"#=======================================#"<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"             EDIT BARANG                 "<<endl;
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"Barang: "<<daftar_barang[ pilihan_edit-1]<<endl;
                        garis_satu();
                        cout<<"1. Edit Harga"<<endl;
                        cout<<"2. Tambah Stok"<<endl;
                        cout<<"3. Kurangi Stok"<<endl;
                        cout<<"0. Kembali"<<endl;
                        garis_satu();
                        cout<<"Pilih opsi: ";
                        cin>>opsi;

                        if(opsi < 0 || opsi > 3){
                            cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 3."<<endl;
                            system("pause");
                            continue;
                        }

                        garis_satu();
                        if(opsi == 1) 
                        editHarga(daftar_harga[ pilihan_edit-1], daftar_barang[ pilihan_edit-1]);
                        if(opsi == 2)
                        tambah_stok(daftar_stok[ pilihan_edit-1], daftar_barang[ pilihan_edit-1]);
                        if(opsi == 3)
                        kurangi_stok(daftar_stok[ pilihan_edit-1], daftar_barang[ pilihan_edit-1]);
                        if(opsi == 0) ulang_edit = false;

                        if(opsi != 0) 
                        system("pause");

                    } while(ulang_edit);

                    ulang_sub = true;

                } else if(pilihan_toko == 4){
                    system("cls");
                    cout<<"#=======================================#"<<endl;
                    cout<<"|            TIVAIZ STORE               |"<<endl;
                    cout<<"#=======================================#"<<endl;
                    cout<<"-----------------------------------------"<<endl;
                    cout<<"             LIHAT BARANG                "<<endl;
                    cout<<"-----------------------------------------"<<endl;

                    if(total_data == 0){
                        cout<<"[Info] Tidak ada barang di toko."<<endl;
                    } else {
                        for(int i=0; i<total_data; i++){
                            cout<<endl;
                            cout<<"No           : "<<i+1<<endl;
                            cout<<"Nama Barang  : "<<daftar_barang[i]<<endl;
                            cout<<"Stok Barang  : "<<daftar_stok[i]<<endl;
                            cout<<"Harga/Stok   : Rp "<<daftar_harga[i]<<endl;
                            cout<<"Total Harga  : Rp "<<daftar_stok[i]*daftar_harga[i]<<endl;
                            cout<<"-----------------------------------------"<<endl;
                        }
                        cout<<"Total barang : "<<total_data<<" jenis"<<endl;
                        cout<<"-----------------------------------------"<<endl;
                    }
                    system("pause");
                    ulang_sub = true;
                }

            } while(ulang_sub);

        } else if(pilihan_awal == 2){
            ulang_sub = true;
            do {
                system("cls");
                banner("KALKUL4TOR");
                cout<<"1. Operasi Dasar (+, -, *, /)"<<endl;
                cout<<"2. Faktorial "<<endl;
                cout<<"0. Kembali"<<endl;
                cout<<"Pilih menu: ";
                cin>>pilihan_kalulator;

                if(cin.fail()){
                    cin.clear(); cin.ignore(1000,'\n');
                    cout<<"[Gagal] Input harus berupa angka!"<<endl;
                    system("pause");
                    ulang_sub = true;

                }

                else if(pilihan_kalulator == 0){
                    ulang_sub = false;

                }

                else if(pilihan_kalulator == 1){
                    garis_satu();
                    cout<<"Operator (+, -, *, /) : ";
                    cin>>pilihan_kalkulator2;
                    cout<<"Angka pertama : "; cin>>angka_awal;
                    cout<<"Angka kedua   : "; cin>>angka_akhir;
                    garis_satu();

                    if(pilihan_kalkulator2 == '+')     
                    penjumlahhan(angka_awal, angka_akhir);

                    else if(pilihan_kalkulator2 == '-') 
                    pengurangan(angka_awal, angka_akhir);

                    else if(pilihan_kalkulator2 == '*') 
                    perkalian(angka_awal, angka_akhir);

                    else if(pilihan_kalkulator2 == '/') 
                    pembagian(angka_awal, angka_akhir);

                    else
                    cout<<"[Gagal] Operator tidak valid!"<<endl;

                    system("pause");
                    ulang_sub = true;

                }
                
                else if(pilihan_kalulator == 2){
                    garis_satu();
                    cout<<"N : "; cin>>angka_awal;
                    garis_satu();
                    if(angka_awal < 0)
                    cout<<"[Gagal] Faktorial tidak bisa untuk angka negatif!"<<endl;
                    else 
                    cout<<angka_awal<<"! = "<<faktorial(angka_awal)<<endl;
                    system("pause");
                    ulang_sub = true;

                } 
                
                else {
                    cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 2."<<endl;
                    system("pause");
                    ulang_sub = true;
                }

            } while(ulang_sub);

        } 
        
        else if(pilihan_awal == 0){
            ulang_utama = false;
        } 
        
        else {
            cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 2."<<endl;
            system("pause");
        }

    } while(ulang_utama);

    return 0;
}