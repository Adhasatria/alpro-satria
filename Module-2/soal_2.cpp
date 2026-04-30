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
cout<<"--- TUGAS 2 : DANAU HITAM ---"<<endl;
int pilihan2;
for(int menit  = 10; menit<60 ; menit+10){
    cout<<"menit "<<menit<<"ada grindlow! (l. lawan, h:Hindari )";cin>>pilihan2;
    switch (pilihan2){
        case 'l':
        cout<<"oksigen anda habis karena kelelahan bertarung !"<<endl;
        cout<<"Waktu/okdigen habis putri duyung membawa anda ke permukaan "<<endl;
        cout<<"mengulang tugas 2 dari awal"<<endl;
        break;
        case 'h':
        cout<<"Lolos dari grindlow!"<<endl;
        break;
        default:
        cout<<"Pilihan tidak valid Ulangi pilihan"<<endl;
        break;
    } 
}
}