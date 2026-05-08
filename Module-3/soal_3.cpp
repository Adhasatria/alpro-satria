#include <iostream>
using namespace std;

int main(){
    int key;
    const int max= 100;
    const int colom= 4;
    char teks [max];
    char input;
    int panjang=0;
    int kolom=4;
    cout<<"[TASK 1/3] DECODE SIGNAL - Communication Room"<<endl;
    cout<<"Kirim Sinyal terenkripsi dan deskripsi balasan dari bumi "<<endl<<endl;
    cout<<"[ ENKRIPSI ]"<<endl;
    do{
        cout<<"Masukkan Key         :";cin>>key;
        if(key<=0){
            cout<<"[!] Key harus bilangan bulat positif. Coba lagi."<<endl;
        }
    }while(key<=0);
    cin.ignore(max, '\n');
    do{
        cout<<"Masukkan Teks         :";
        cin.getline(teks, max);
        cout<<endl;

        if(teks [0]== '\0'){
        cout<<"input tidak boleh kosong. coba lagi "<<endl;
        }
    }while(teks[0] == '\0');
    
    
    while (teks[panjang] != '\0'){
     panjang++;
    }

    int baris = (panjang + 3) / 4;

    char matriks[baris][4];
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            matriks[i][j] = '_';
        }
    }
   
    int index = 0;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            if (index < panjang)
                matriks[i][j] = teks[index++];
        }
    }
 

    cout << endl << "Matriks enkripsi:"<<endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j];
            if (j < kolom - 1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;

     cout<<" enkripsi sebelum ditambahkan key : ";

    for(int i=0; i<4; i++){
        for(int j= 0; j<baris; j++){
            cout<<(char)matriks[j][i]<<" ";
            }
        }
    cout<<endl;
     cout<<" enkripsi setelah ditambahkan key : ";
    for(int i=0; i<4; i++){
        for(int j= 0; j<baris; j++){
            cout<<(char)(matriks[j][i] + key)<<" ";
            }
        }
    cout<<endl<<endl;

    char hasilenkripsi[max];
    do{
        cout<<"Masukkan Teks terenkripsi         :";
        cin.getline(hasilenkripsi, max);
        cout<<endl;

        if(hasilenkripsi [0]== '\0'){
        cout<<"input tidak boleh kosong. coba lagi "<<endl;
        }
    }while(hasilenkripsi[0] == '\0');

    int panjang_dekripsi=0;
    while(hasilenkripsi[panjang_dekripsi] !=0){
        panjang_dekripsi++;
    }

    char setelahShift[max];
    for (int i = 0; i < panjang_dekripsi; i++){
    setelahShift[i] = (char)(hasilenkripsi[i] - key);
    }
    setelahShift[panjang_dekripsi] = '\0';

    cout << "Teks setelah dikurangi key : " << setelahShift << endl;


    int barisD = (panjang_dekripsi + 3) / 4;


    char matriksD[25][4];
    for (int i = 0; i < barisD; i++){
        for (int j = 0; j < kolom; j++){
            matriksD[i][j] = '_';
        }
    }

    int indexD = 0;
    for (int j = 0; j < kolom; j++){
        for (int i = 0; i < barisD; i++){
            if (indexD < panjang_dekripsi)
                matriksD[i][j] = setelahShift[indexD++];
        }
    }

    cout << endl << "Matriks Dekripsi:" << endl;
    for (int i = 0; i < barisD; i++){
        for (int j = 0; j < kolom; j++){
            cout << matriksD[i][j];
            if (j < kolom - 1) cout << " ";
        }
        cout << endl;
    }


    cout << endl << "Hasil Dekripsi Final : ";
        for (int i = 0; i < barisD; i++){
        for (int j = 0; j < kolom; j++){
            if (matriksD[i][j] != '_')
            cout << matriksD[i][j];
            }
        }
    cout << endl;
    system("pause");
    system("cls");

    cout<<"[TASK 2/3] REPAIR TEXT CONSOLE - Captains's Bridge"<<endl;
    cout<<">> Konsol teks mengalami interferensi kosmik."<<endl;
    cout<<">> Verifikasi integritas data teks sebelum terlambat! "<<endl;
    cout<<"[ Verifikasi Teks ]"<<endl;
    char kalimat[100];
    char ulang;


    do{
        for (int perulangan = 1; perulangan <= 3; perulangan++){

        do{
            cout<<"masukkan kalimat ke"<<perulangan<<"  :";
            cin.getline(kalimat, 100);
            if(kalimat[0] == '\0')
                cout<<"input tidak boleh kosong. coba lagi"<<endl;
        }while(kalimat[0] == '\0');

        cout<<"---------------------------------------"<<endl;

        int panjang_kalimat= 0;
        while(kalimat[panjang_kalimat]!= '\0')
            panjang_kalimat++;

        cout<<"jumlah huruf :   "<<panjang_kalimat<<endl;
        cout<<"Asli: ";
        for(int i =0; i<panjang_kalimat; i++){
            if((int)kalimat[i] == 32) continue;
            cout<<kalimat[i]<<" "<<",";
        }
        cout<<endl;
        cout<<"inverse: ";
        for(int i= panjang_kalimat-1; i>=0; i--){
            if((int)kalimat[i] == 32) continue;
            cout<<kalimat[i]<<" "<<",";
        }
        cout<<endl;
        char tukar[panjang_kalimat];
        cout<<"swap awal akhir :";
        for(int i= 0; i<panjang_kalimat; i++ ){
            if(i == 0 ){
                tukar[0]=kalimat[0];
                kalimat[0]=kalimat[panjang_kalimat-1];
                kalimat[panjang_kalimat-1]=tukar[0];
            }
            cout<<kalimat[i]; 
        }
        cout<<endl;

        cout<<"PALINDROME :";
        bool palindrome = true;
        for(int i=0; i<panjang_kalimat/2; i++){
            if(kalimat[i] != kalimat[panjang_kalimat-1-i]){
                palindrome=false;
            }
        }
        if(palindrome== false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }

    do {
        cout << "Verifikasi Teks Lagi? (y/n): ";
        cin >> ulang;
        if (ulang != 'y' && ulang != 'n')
            cout << "  [!] Input tidak valid. Masukkan y atau n." << endl;
    } while (ulang != 'y' && ulang != 'n');
    cin.ignore(100, '\n');

    } while (ulang == 'y');
    system("pause");
    system("cls");

    int angka;

    cout << "[TASK 3/3] ALIGN NAVIGATION MATRIX - Engine Core" << endl;
    cout << ">> Sistem navigasi mati total akibat sabotase." << endl;
    cout << ">> Rekonstruksi matriks koordinat sekarang!" << endl << endl;
    cout << "[ MATRIX NAVIGATION ]" << endl;

    // Input Validation (Min 3, Max 5)
    while (true) {
        cout << "Masukkan ukuran Navigation Matrix (min 3, max 5): ";
        cin >> angka;

        if (angka >= 3 && angka <= 5) {
            break;
        } else {
            cout << " [!] Input tidak valid. Masukkan ukuran antara 3 sampai 5." << endl << endl;
        }
    }

    cout << "--------------------------------------------" << endl;

    int ganjil[5][5], genap[5][5], integrasi[5][5];
    int valGanjil = 1, valGenap = 2;

    cout << "Odd Coordinate Matrix (Ganjil):" << endl;
    for (int i = 0; i < angka; i++) {
        for (int j = 0; j < angka; j++) {
            ganjil[i][j] = valGanjil;
            if (ganjil[i][j] < 10) cout << "0";
            cout << ganjil[i][j] << " ";
            valGanjil += 2;
        }
        cout << endl;
    }

    cout << "\nEven Coordinate Matrix (Genap):" << endl;
    for (int i = 0; i < angka; i++) {
        for (int j = 0; j < angka; j++) {
            genap[i][j] = valGenap;
            if (genap[i][j] < 10) cout << "0";
            cout << genap[i][j] << " ";
            valGenap += 2;
        }
        cout << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << "\nMatriks koordinat telah dipulihkan" << endl;
    cout << "Lakukanlah proses-proses berikut ini!" << endl;
    cout << "1. Coordinate Matrix Integration\n2. Matrix Transpose\n3. Snake Traverse\n" << endl;

    cout << "Tekan ENTER untuk melanjutkan...";
    cin.ignore(); 
    cin.get();    

    cout << "\nCOORDINATE MATRIX INTEGRATION:" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < angka; i++) {
        for (int j = 0; j < angka; j++) {
            integrasi[i][j] = ganjil[i][j] + genap[i][j];
            if (integrasi[i][j] < 10) cout << "0";
            cout << integrasi[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMATRIX TRANSPOSE:" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < angka; i++) {
        for (int j = 0; j < angka; j++) {
            int temp = integrasi[j][i]; 
            if (temp < 10) cout << "0";
            cout << temp << " ";
        }
        cout << endl;
    }

    cout << "\nSNAKE TRAVERSE:" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < angka; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < angka; j++) {
                int val = integrasi[j][i]; 
                if (val < 10) cout << "0";
                cout << val << " ";
            }
        } else {

            for (int j = angka - 1; j >= 0; j--) {
                int val = integrasi[j][i];
                if (val < 10) cout << "0";
                cout << val << " ";
            }
        }
        cout << endl;
    }

    cout << "\n--------------------------------------------" << endl;
    cout << ">> [TASK 3/3] COMPLETE - Navigation matrix aligned." << endl;
    cout << "==========================================================" << endl;
    cout << "   ALL TASKS COMPLETE - SHIP SYSTEMS RESTORED" << endl;
    cout << "==========================================================" << endl;

    return 0;
}