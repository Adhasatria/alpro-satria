#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_RED "\033[1;31m"
#define COLOR_CYAN "\033[1;36m"
#define COLOR_GRAY "\033[0;90m"
#define COLOR_WHITE "\033[1;37m"
#define COLOR_MAGENTA "\033[1;35m"

string generateShortHash(int commitId) {
    const char hexChars[] = "0123456789abcdef";
    string hash="";
    int value = commitId * 2654435761u;
    if (value < 0) value = - value;
    for (int i = 0; i < 7; i++) {
    hash = hexChars[value & 0xF] + hash;
    value >>= 4;
    }
    return hash;
}
string getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buffer [20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H: %M", localtime (&now));
    return string(buffer);
}
struct Commit{
    string message;
    string hash;
    string author;
    string time;
    Commit* parent=nullptr;
};
struct Branch{
    string nama;
    Commit* head_commit=nullptr;
    int commit_count;
};
struct Repository{
    string name;
    Branch brach;
    Commit commit;
    int banyak_brach;
    int idx_branch_active;
};


void commit(Repository* repo, string author){
    Branch* branch_aktif = &(repo->brach);
    string pesan_sementara;
    char konfirmasi; 
    Commit waktu;

    cout << "git commit [" << branch_aktif->nama << "]" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Message : ";
    getline(cin, pesan_sementara);

    cout << "Push commit? (y/n) ";
    cin >> konfirmasi;
    cin.ignore(); 
    if(konfirmasi == 'y' || konfirmasi == 'Y'){
        waktu.time= getCurrentTimestamp();
        Commit* new_commit = new Commit;
        new_commit->message = pesan_sementara;
        new_commit->author = string();
        new_commit->hash = generateShortHash(branch_aktif->commit_count + 1);
        
        new_commit->parent = branch_aktif->head_commit;
        
        branch_aktif->head_commit = new_commit;
        branch_aktif->commit_count++;

        cout << COLOR_GREEN << "[" << branch_aktif->nama << " " << new_commit->hash << "] " << COLOR_RESET << pesan_sementara << endl;
        cout << COLOR_GREEN << branch_aktif->nama << " -> origin/" << branch_aktif->nama << COLOR_RESET << endl;
        cout << " $ git push origin " << branch_aktif->nama << endl;
    } else {
        cout << COLOR_RED << "[BATAL] Commit dibatalkan." << COLOR_RESET << endl;
    }
}


int main(int argc, char *argv[])
{   Repository* repo =  new Repository;
    string nama_sementara;
    string nama_author=argv[1];


    cout<<COLOR_CYAN " GITSIM "<<COLOR_RESET<<"- Lightweight Git Simulator"<<endl;    
    cout<<COLOR_GRAY<<"Author :"<<COLOR_RESET<<nama_author<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"git init"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<COLOR_CYAN " Repository name :"<<COLOR_RESET;cin.ignore(); getline(cin, nama_sementara);
    if(nama_sementara.empty()){
        repo->name= "my-repo";
    }else{
        repo->name= nama_sementara;
    }
    cout<<COLOR_GREEN "[OK]" COLOR_RESET<<"Initialized empty repository: "<<repo->name;
    
    repo->brach.nama = "main";
    repo->brach.head_commit = nullptr;
    repo->brach.commit_count = 0;

    cout << COLOR_GREEN "[OK] " COLOR_RESET << "Initialized empty repository: " << repo->name << endl;
    cout << "On branch: main\n" << endl;
    
    commit(repo, argv[1]);
    return 0;
}
