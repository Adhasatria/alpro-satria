#include <iostream>
#include <climits>
using namespace std;



const int willpower=0;
const int thunder=1;

struct Neural_entry{
    int len;
    char type; 
    char nama[256];
    size_t offset;
    size_t ukuran;
    int int_data;
};

struct Neural_core{
    size_t kapasitas= 128;
    unsigned char* buffer= new unsigned char [kapasitas];
    size_t cursor=0;
};

Neural_core neural;
Neural_entry* entry[100000];
bool penghapusan [100000]={false};
size_t jumlah=0;

int stability(Neural_core* core){
    return 100-(100*core->cursor/core->kapasitas);
}

int panjang_nim( const char* ikan){
    int panjang=0;
    while(ikan[panjang]!= '\0'){
        panjang++;
        }
    return panjang;
    }

bool cek_nim( const char *ikan){
    int panjang=0;
    
    if(panjang_nim(ikan) != 11){
        cout<<"Error: Operator ID must be exactly 11 characters long."<<endl;
        return false;
    }
    if(ikan[0] != 'F' || ikan[1] != '1' || ikan[2] != 'D' || ikan[3] != '0' || ikan[4] != '2') {
        cout << "Error: ID Operator harus diawali dengan F1D02." << endl;
        return false;
    }
    return true;
} 
void banner(int &pilihan){
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"         CYRON TERMINAL: DIVINE SUPPRESSION             "<<endl;
    cout<<"--------------------------------------------------------"<<endl;

    if(pilihan==1){
        cout<<"Xelisa : Luar biasa... sinkronisasi terjalin sempurna "<<endl;
    }else if(pilihan==2){
        cout<<"Xelisa : Jangan dengarkan gema dari vessel. Efisiensi adalah kebenaran kita"<<endl;
    }else if(pilihan==3){
        cout<<"Xelisa : Setiap thread yang kita alokasikan membawa kita lebih dekat ke alam semesta yang terkelola"<<endl;
    }else if(pilihan==4){
        cout<<"Xelisa : Aku adalah keilahian CyroN yang teroptimasi"<<endl;
    }
        cout<<"CYRON TERMINAL: DIVINE SUPPRESSION"<<endl;            
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"1. Tampilkan Neural Map (Status)"<<endl;
    cout<<"2. Suntik Neural Thread (Tambah)"<<endl;
    cout<<"3. Bersihkan Link Terkorupsi (Hapus)"<<endl;
    cout<<"4. Perluas Willpower (Resize)"<<endl;
    cout<<"0. Menyerah (Keluar)"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    while (true) {
        cout << "Pilih Operasi: "; 
        cin >> pilihan;
        if (cin.fail()) {
            cout << "Input tidak valid! Masukkan angka." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        break;
    }
}


void add(Neural_core* core ){
    int pilihan;
    cout<<"Pilih tipe injeksi "<<endl;
    cout<<"[0] Willpower (Teks) "<<endl;
    cout<<"[1] Thunder (angka) "<<endl;
    cout<<"Pilih tipe sub vessel :";cin>>pilihan;
    cin.ignore();

    if(pilihan==0){
        entry[jumlah]= new Neural_entry;
        cout<<"Masukkan input Willpower :";cin.getline(entry[jumlah]->nama, 256 );
        size_t panjang_teks=0;
        while(entry[jumlah]->nama[panjang_teks] != '\0'){
            panjang_teks++;
        }
        panjang_teks++;

        if(core->cursor+ panjang_teks> core->kapasitas){
            cout<<"!! ERROR OPTIMALISASI !! Ego vessel menolak thread !"<<endl;
            return;
        }
        entry[jumlah]->type='0';
        entry[jumlah]->offset=core->cursor;
        entry[jumlah]->ukuran=panjang_teks;
        
        for(size_t i=0; i<panjang_teks; i++){
            core->buffer[core->cursor+i]=static_cast<unsigned char >(entry[jumlah]->nama[i]);
        }

        core->cursor += panjang_teks;
        jumlah++;

        cout<<"Perintah Cyron: Resistensi subjek terdeteksi. Mengesampingkan umpan balik."<<endl;
    }
    else if(pilihan==1){
        int thunder;
        while(true){
            cout<<"Masukkan jumlah thunder";
            cin>>thunder;
            if(cin.fail()){
                cout<<"[Gagal] Input Thunder berupa angka!"<<endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            break;
        }
        if(core->cursor + sizeof(int) > core->kapasitas){
            cout<<"!! ERROR OPTIMALISASI !! Burnout neural terdeteksi!"<<endl;
            return;
        }
        entry[jumlah]= new Neural_entry;
        entry[jumlah]->type='1';
        entry[jumlah]->offset=core->cursor;
        entry[jumlah]->ukuran= sizeof(int);
        entry[jumlah]->int_data= thunder;
    
    unsigned char* alamat_thunder = (unsigned char*)&thunder;
    for(size_t i=0; i<sizeof(int); i++){
        core->buffer[core->cursor+i]= alamat_thunder[i];
        
    }
    core->cursor+= sizeof(int);
    jumlah++;
    }else{
    cout<<"[Gagal] Opsi tidak valid! "<<endl;
    }
}

void view(){
    cout<<"========================================="<<endl;
    cout<<"NEURAL MAP HISTORIA KOURA [STABILITY "<<stability(&neural)<<"%]"<<endl;
    cout<<"========================================="<<endl;
    if(neural.cursor==0){
        cout<<"Data Kosong "<<endl;
    }
    for(size_t i=0; i<jumlah; i++){
        if(penghapusan[i])continue;
        void* address= (void*)(neural.buffer + entry[i]->offset);
        cout<<"| Indeks :"<<i<<"|"<<(entry[i]->type=='0' ? "[0] Willpower pulse" : "[1] Thunder discharge");
        cout<<"| Address: "<<address;
        cout<<"| Offset : "<<entry[i]->offset;
        cout<<"| Size :"<<entry[i]->ukuran<<"bytes";

        if(entry[i]->type=='1'){
            cout<<"| DATA: "<<entry[i]->int_data<<"MW";
        }else if(entry[i]->type=='0'){
            cout<<"| DATA: "<<(char*)(neural.buffer + entry[i]->offset);
        }
        cout<<endl;
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"   KURSOR:  "<<neural.cursor<<"/"<<neural.kapasitas;
    cout<<"-------------------------------------"<<endl;
}

void resize(){
    int input_baru;
    while(true){
        cout<<"Masukkan batas buffer baru: ";cin>>input_baru;
    if(input_baru<0){
        cout<<"Batas baru harus angka positif"<<endl;
        continue;
        }
    size_t kapasitas_baru = static_cast<size_t>(input_baru);

    if(kapasitas_baru>neural.kapasitas){
        unsigned char* buffer_baru= new unsigned char[kapasitas_baru];
        for(size_t i=0; i<neural.cursor; i++){
            buffer_baru[i]=neural.buffer[i];
        }
            delete[]neural.buffer;
            neural.buffer=buffer_baru;
            neural.kapasitas=kapasitas_baru;
            cout<<"Perintah CyroN: tabilitas meningkat. Vessel sekarang 100% patuh."<<endl;
            cout<<"Alamat frekuensi teralokasi bari"<<(void*)neural.buffer<<endl;
            break;
            
        }else{
            cout<<"Ekspansi harus lebih besar dari batas saat ini!"<<endl;
        }
    }
}

void hapus(Neural_core* core) {
    if (jumlah == 0) {
        cout << "Data kosong adek lagi bobok zzzzzzzzzzzzzzzzz......................" << endl;
        return; 
    }
    
    for (size_t i = 0; i < jumlah; i++) {
        if (penghapusan[i]) continue;
        void* address = (void*)(core->buffer + entry[i]->offset);
        cout << " | Indeks: "<< i << " | " << (entry[i]->type == '0' ? "[0] Willpower pulse" : "[1] Thunder discharged")
             << " | Address: " << address
             << " | Offset: " << entry[i]->offset 
             << " | Size: " << entry[i]->ukuran << " bytes";
             
        if (entry[i]->type == '1') {
            cout << " | DATA: " << entry[i]->type;
        } 
        else if (entry[i]->type == '0') {
            cout << " | DATA: " << (char*)(core->buffer + entry[i]->offset)<<"MW";
        }
        cout << endl;
    }

    int pass_input;
    cout << "Masukkan indeks link untuk dihapus: ";
    cin >> pass_input;

    if (cin.fail() || pass_input < 0 || static_cast<size_t>(pass_input) >= jumlah) {
        cout << "Indeks link tidak valid." << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        return;
    }

    size_t pass = static_cast<size_t>(pass_input);

    if (penghapusan[pass]) {
        cout << "Indeks link sudah dihapus sebelumnya." << endl;
        return;
    }

    penghapusan[pass] = true;
    cout << "Link " << pass << " berhasil dihapus." << endl;

    if (entry[pass]->offset + entry[pass]->ukuran == core->cursor) {
        core->cursor -= entry[pass]->ukuran; 
        if (pass > 0) {
            size_t j = pass - 1;
            while (penghapusan[j] && (entry[j]->offset + entry[j]->ukuran == core->cursor)) {
                core->cursor -= entry[j]->ukuran;
                if (j == 0) break;
                j--;
            }
        }

        cout << "Neural Core berhasil mengembalikan ruang memori. Ujung (Tail) saat ini di: " << core->cursor << endl;
    } 
    else {
        cout << "Fragmentasi terdeteksi. Memori belum dapat dikembalikan saat ini!" << endl;
    }
}

int main(int argc, char *argv[])
{
    Neural_core core;
    int pilihan=-1;
    bool cihuy=true;
    if(argc < 2){
        cout<<"Error: Neural Link requires an Operator ID (Student ID)."<<endl;
        return 1;
    }
    if(argc > 2){
        cout<<"Error: Too many parameters. Connection unstable."<<endl;
        return 1;
    }

    if(!cek_nim(argv[1])){
        return 1;
    }
    do{
    banner(pilihan);

    switch (pilihan)
    {
    case 1:
        view();
        system("pause");
        break;
    case 2:
        add(&neural);
        system("pause");
        break;
    case 3:
    system("cls");
        hapus(&neural);
        system("pause");
        break;
    case 4:
        resize();
        system("pause");
        break;
    case 0:
        cout<<"Realitas mulai tidak stabil..."<<endl;
        system("pause");
        cout<<"Koneksi terputus. Selamat tinggal, Operator 084."<<endl;
        cihuy=false;
        break;
    }
    }while(cihuy);

    for(size_t i = 0; i < jumlah; i++) {
        delete entry[i];
    }
    delete[] neural.buffer;

    return 0;
}
