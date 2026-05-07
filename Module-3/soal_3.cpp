#include <iostream>
using namespace std;

int main(){
    int key;
    char teks [100];
    cout<<"[TASK 1/3] DECODE SIGNAL - Communication Room"<<endl;
    cout<<"Kirim Sinyal terenkripsi dan deskripsi balasan dari bumi "<<endl;
    cout<<"[ ENKRIPSI ]"<<endl;
    do{
        cout<<"Masukkan Key         :";cin>>key;
        if(key<=0){
            cout<<"[!] Key harus bilangan bulat positif. Coba lagi."<<endl;
        }
    }while(key<=0);
    do{
        cout<<"Masukkan Teks terenkripsi         :";
        cin.getline(teks, 100);
        if(teks [0]== '\0'){
        cout<<"input tidak boleh kosong. coba lagi "<<endl;
        }
    }while(teks[0] != '\0');
    system("pause");
    system("clear");

    cout<<"[TASK 2/3] REPAIR TEXT CONSOLE - Captains's Bridge"<<endl;
    cout<<">> Konsol teks mengalami interferensi kosmik."<<endl;
    cout<<">> Verifikasi integritas data teks sebelum terlambat! "<<endl;

    cout<<"[TASK 3/3] ALIGN NAVIGATION MATRIX - Engine Core"<<endl;
    cout<<">> Sistem navigasi mati total akibat sabotase "<<endl;
    cout<<">> Rekonstruksi matriks koordinat sekarang!"<<endl;
    cout<<"[ MATRIX NAVIGATION ]"<<endl;
    return 0;
}