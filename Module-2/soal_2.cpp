#include <iostream>
using namespace std;

int main(){
    cout<<"=== GOBLET OF FIRE: TURNAMEN TRIWIZARD ==="<<endl;
    int usia;
    int perlindungan_sihir = 3;
    char pilihan;
    cout<<"Masukkan umur anda :";
    cin >> usia;
if (usia<17){
    cout<<"Piala Api Menolak Anda Umur Anda Terlalu Kecil! "<<endl;
    system("pause");
    return 0;

}
else{
    cout<<"Piala Api Menyala! Anda terpilih sebagai Triwizard Champions."<<endl;
}

cout<<"--- Tugas 1: NAGA HUNGARIAN HORNTAIL ---"<<endl;
while(perlindungan_sihir>0 ){
    cout<<"Sisa perlindungan sihir: "<<perlindungan_sihir<<" kali"<<endl;
    cout<<"pilih strattegi (a.Sembunyi, b: panggil sapu)";cin>>pilihan;
    switch (pilihan){
       case 'a':
       cout<<"naga menyemburkan api! anda terluka"<<endl;
       perlindungan_sihir--;
        if(perlindungan_sihir==0){
            cout<<">>  KESEMPATAN HABIS! Anda ditarik keluar arena oleh pawang naga"<<endl;
            cout<<"MENGULANG TUGAS 1 DARI AWAL"<<endl;
            perlindungan_sihir=3;
            system("pause");
        }
       break;
       case 'b':
            cout<<"berhasil! anda mengambil telur emas"<<endl;
            perlindungan_sihir= perlindungan_sihir-3;
            break;
       default:
            cout<<"pilihan tidak valid ulangi pilihan"<<endl;
            break;

    }
}
system("cls");
    int menit = 10;
    int menit_akhir=60;
    char pilihan2;
while(menit<menit_akhir){
    cout<<"--- TUGAS 2 : DANAU HITAM ---"<<endl;
    cout<<"Menit "<<menit<<"... Ada Grindlow! (l: lawan, h: hindari)";cin>>pilihan2;
    if(pilihan2 == 'h' ){
        cout<<"Lolos dari Grindlow"<<endl;
        menit+= 10;
        if(menit== 60){
            cout<<"Tepat "<<menit<<" Anda menyelamatkan sandera"<<endl;
        }
    }
    else if(pilihan2 == 'l'){
        cout<<"Waktu/Oksigen anda habis karena kelelahan bertarung !"<<endl;
        cout<<"putri duyung membawa anda ke permukaan"<<endl;
        menit=10;
    }
    else{
        cout<<"pilihan tidak valid, ulangi pilihan"<<endl;
        }
    }
system("pause");
system("cls");


    int kanan;
    int kiri;
    int lurus;
    int tol_kesalahan = 2;
    int langkah_batas = 3;
    int langkah_sekarang = 0;
    int arah;
    while(langkah_sekarang<langkah_batas) {
        cout<<"--- TUGAS 3: LABIRIN ---"<<endl;
        cout<<"Sisa toleransi kesalahan: "<<tol_kesalahan<<endl;
        cout<<"langkah ditempuh: "<<langkah_sekarang<<endl;
        cout<<"pilih arah : (1: Kiri, 2: Kanan, 3: Lurus)";cin>> arah;
        if(arah==3){
            cout<<"Anda melihat cahaya... Oh tunggu, apa itu...";
            langkah_sekarang=3;
            system("pause");
            system("cls");
        }
        else if(arah== 2){
            langkah_sekarang++;
            cout<<"jalan aman, anda semakin dalam."<<endl;
        }
        else if(arah==1){
            tol_kesalahan--;
            if(tol_kesalahan<=0){
                langkah_sekarang=0;
                tol_kesalahan=2;
                cout<<"Kesempatan habis labirin berubah bentuk dan menedang andak ke pintu masuk"<<endl;
                cout<<"MENGULANG TUGAS 3 DARI AWAL"<<endl;
                system("pause");
                system("cls");
            }
        }
        else{
            cout<<"Anda tidak berada di jalur pilihan! Ulangi pilihan!"<<endl;
        }
    }
    cout<<endl;
cout<<"--- JALAN KELUAR --- "<<endl;
int angka;
cout<<"anda melihat sesuatu yang bersinar di tengah arena ..."<<endl;
cout<<"Terdapat sesuatu yang terkurung di dalamnya, dan terdapat mesin yang meinta anda untuk memasukkan sebuah angka... "<<endl;
cout<<"masukkan angka(minimal 5) :";cin>>angka;
cout<<"sebuah cahaya bersinar dan ditanganmu kini terdapat sebuah diamond besar!"<<endl;
for(int i=1; i<=angka; i++){
    for(int j=1; j<=angka-i; j++){
        cout<<" ";
    }
    for(int k = 1; k<=(2*i-1); k++){
        cout<<"*";
    }
    cout<<endl;
    }
for (int i = angka - 1; i >= 1; i--) {
    for (int j = 1; j <= angka - i; j++) {
        cout << " ";
    }
    for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
    }
    cout << endl;
    }
} 