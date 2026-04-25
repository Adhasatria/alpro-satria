#include <iostream>
using namespace std;

int main(){
int UTS, UAS, Tugas;
int nim;
float nilai_akhir;
float bobot_uts=0.3;
float bobot_uas=0.4;
float bobot_tugas=0.3;
int sks=144;
int sks_ditempuh;
char kode_grade;
int semester_penuh;
int sks_sisa;
int hasil_enkripsi;


cout<<"Masukkan NIM :"<<endl;
cin>>nim;
cout<<"Masukkan nilai uts :"<<endl;
cin>>UTS;
cout<<"Masukkan nilai uas :"<<endl;
cin>>UAS;
cout<<"Masukkan nilai tugas :"<<endl;
cin>>Tugas;

(float)UTS;
(float)UAS;
(float)Tugas;

UTS=bobot_uts*(float)UTS;
UAS=bobot_uas*(float)UAS;
Tugas=bobot_tugas*(float)Tugas;

cout<<"nilai uts :"<<endl;
cout<<UTS<<endl;
cout<<"nilai uas :"<<endl;
cout<<UAS<<endl;
cout<<"nilai tugas :"<<endl;
cout<<Tugas<<endl;

nilai_akhir=(float)UTS+(float)UAS+(float)Tugas;
cout.precision(2);
cout<<fixed;
cout<<"Nilai akhir :";
cout<<nilai_akhir<<endl;
cout<<"Nilai bulat bawah :";
cout<<(int)nilai_akhir<<endl;
cout<<"Nilai bulat atas :";
cout<<(int)nilai_akhir+((int)nilai_akhir/100)/100<<endl;

cout<<"SKS Ditempuh: ";cin>>sks_ditempuh;
cout<<"sisa sks :"<<sks-sks_ditempuh<<endl; 
sks_sisa=sks-sks_ditempuh;
sks_sisa=sks_sisa%18;
cout<<"sks sisa :"<<sks_sisa<<endl;
cout<<"semester sisa"<<sks_sisa/2;


cout<<"kode Grade (lowercase)  "<<endl;cin>>kode_grade;
(int)kode_grade;
kode_grade=kode_grade-32;
cout<<"uppercase :"<<(char)kode_grade<<endl;
cout<<"Nilai ASCII :"<<(int)kode_grade<<endl;
int shift_nim=nim%10;
cout<<"Shift digit terakhir NIM :"<<nim%10;
cout<<"hasil enkripsi :"<<kode_grade;

}