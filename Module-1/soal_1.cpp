#include <iostream>
using namespace std;

int main(){
    int beras,telur,minyak;
    float pajak= 0.25;
    int total_harga;
    int harga_pajak;
    int nominal_uang;
    int kembalian;

    cout<<"==============================="<<endl;
    cout<<"|    TOKO SEMBAKO JAYA ABADI   | "<<endl;
    cout<<"==============================="<<endl;
    cout<<"[Bina]: Than masukin harga barangnya Rendy di program ini"<<endl;
    cout<<"harga beras (Rp.) :";
    cin>>beras;
    cout<<"harga telur (Rp.) :";
    cin>>telur;
    cout<<"harga minyak (Rp.) :";
    cin>>minyak;

    harga_pajak=pajak*(beras+telur+minyak);
    total_harga=harga_pajak+beras+telur+minyak;
    cout<<"total belanja (+ PPN 25%): "<<total_harga<<endl;

    cout<<"Nominal uang Rendy (Rp.) :";
    cin>>nominal_uang;
    kembalian=nominal_uang-total_harga;

    cout<<"==============================="<<endl;
    cout<<"|       STRUK KEMBALIAN        | "<<endl;
    cout<<"==============================="<<endl;
    cout<<"[Bina]: Nih Than Rincian kemabliannya"<<endl;
    cout<<"total kembalian :"<<kembalian<<endl;
    cout<<"-----------------------------------"<<endl;


    int hundred = 100000, fifty = hundred/2, twt = hundred/5, ten=twt/2, five=hundred/20, one = five/5, coin1=one/2, coin2=(coin1/5)*2, coin3=coin1/5; 
    int indikasi1, indikasi2, indikasi3, indikasi4, indikasi5, indikasi6, indikasi7, indikasi8, indikasi9;

    indikasi1 = kembalian/hundred;
    kembalian %=hundred; 
    
    indikasi2 =kembalian/fifty;
    kembalian %=fifty; 
    
    indikasi3 =kembalian/twt;
    kembalian %=twt; 
    
    indikasi4 =kembalian/ten;
    kembalian %=ten; 

    indikasi5 =kembalian/five;
    kembalian %=five; 
    
    indikasi6 =kembalian/one;
    kembalian %=one; 

    indikasi7 =kembalian/coin1;
    kembalian %=coin1; 
    
    indikasi8 =kembalian/coin2;
    kembalian %=coin2; 
    
    indikasi9 = kembalian/coin3;
    kembalian %=coin3; 
   

    cout<<"Rp 100.000:    "<<indikasi1 <<" Lembar"<<endl;
    cout<<"Rp 50.000      "<<indikasi2<<" Lembar"<<endl;
    cout<<"Rp 20.000      "<<indikasi3<<" Lembar"<<endl;
    cout<<"Rp 10.000      "<<indikasi4<<" Lembar"<<endl;
    cout<<"Rp 5.000       "<<indikasi5<<" Lembar"<<endl;
    cout<<"Rp 1.000       "<<indikasi6<<" Lembar"<<endl;
    cout<<"Rp 1.000       "<<"   0   "<<" koin"<<endl;
    cout<<"Rp 500         "<<indikasi7<<" Koin"<<endl;
    cout<<"Rp 200         "<<indikasi8<<" Koin"<<endl;
    cout<<"Rp 100         "<<indikasi9<<" Koin"<<endl;

    cout << "[Fathan] : Aman ! sisa receh tak terpecahnya : Rp " << kembalian << endl;
	cout << "Mau di diansikan ga ren , Ren? " << endl;
	cout << "[Rendy] : Gas " << endl;
	cout << "============================" << endl;
    

    return 0;
}