#include <iostream>
using namespace std;

void banner(string judul){
    cout<<"#=============================#"<<endl;
    cout<<"|          "<<judul<<"         |"<<endl;
    cout<<"#=============================#"<<endl;
}
void garis_dua(){
    cout<<"==============================="<<endl;
}
void garis_satu(){
    cout<<"-------------------------------"<<endl;
}
void modul4(){
        cout<<"|==================================|"<<endl;
        cout<<"|                                  |"<<endl;
        cout<<"[       MODULE 4 - FUNCTION        ]"<<endl;
        cout<<"|                                  |"<<endl;
        cout<<"|==================================|"<<endl;
        cout<<" 1. TIVAIZ Store"<<endl;
        cout<<" 2. Kalkulator Tivaiz"<<endl;
        cout<<" 0. Keluar"<<endl;
}
void penjumlahhan(int angka1, int angka2, int hasil){
    hasil= angka1+angka2;
    cout<<angka1<<"+"<<angka2<<"="<<hasil;
}
void pengurangan(int angka1, int angka2, int hasil){
    hasil= angka1-angka2;
    cout<<angka1<<"-"<<angka2<<"="<<hasil;
}
void perkalian(int angka1, int angka2, int hasil){
    hasil= angka1*angka2;
    cout<<angka1<<"*"<<angka2<<"="<<hasil;
}
void pembagian( double angka1, double angka2, double hasil){
    hasil= angka1/angka2;
    if(angka2==0){
        cout<<"[Gagal] Tidak bis dibagi nol!"<<endl;
    }
    else{
    cout<<angka1<<"/"<<angka2<<"="<<hasil;
    }
}
int faktorial(int angka1){
    if (angka1==0) return 1;
    return angka1*faktorial(angka1-1);
}


int main(){
    int pilihan_awal;
    int pilihan_kalulator;
    do{
        banner("KALKUL4TOR");
    }while()
    return 0;
}