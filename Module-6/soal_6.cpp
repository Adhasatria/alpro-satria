#include <iostream>
#include <climits>
using namespace std;
 
int cek_nim(char *argv[]){
    int panjang=0;
    
    while(*argv[panjang]!= '\0'){
        panjang++;
    }
    
    if(panjang != 11){
        cout<<"Error: Operator ID must be exactly 11 characters long."<<endl;
    }else if(*argv[0]== 'F'){
        if(*argv[1]== '1'){
            if(*argv[2]== 'D'){
                if(*argv[3]== '0'){
                    if(*argv[4]== '2'){
                        system("clear");
                    }
                }else{
                    cout<<"Error: Operator ID must start with 'F1D02'."<<endl;
                    return 0;
                }
            }else{
                cout<<"Error: Operator ID must start with 'F1D02'."<<endl;
                return 0;
            }
        }else{
                cout<<"Error: Operator ID must start with 'F1D02'."<<endl;
                return 0;
            }
    }else{
                cout<<"Error: Operator ID must start with 'F1D02'."<<endl;
                return 0;
            }


}

int main(int argc, char const *argv[])
{
    if(argc < 2){
        cout<<"Error: Neural Link requires an Operator ID (Student ID)."<<endl;
    }else if(argc > 2){
        cout<<"Error: Too many parameters. Connection unstable."<<endl;
    }

    return 0;
}
