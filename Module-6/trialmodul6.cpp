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
    Branch* brach= nullptr;
    Commit commit;
    int banyak_brach;
    int idx_branch_active;
};


void commit(Repository* repo, string author){
    Branch* branch_aktif = &(repo->brach[repo->idx_branch_active]);
    string pesan_sementara;
    char konfirmasi; 

    cout << "git commit [" << branch_aktif->nama << "]" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Message : ";
    getline(cin, pesan_sementara);

    cout << "Push commit? (y/n) ";
    cin >> konfirmasi;
    cin.ignore(); 
    if(konfirmasi == 'y' || konfirmasi == 'Y'){
        Commit* new_commit = new Commit;
        new_commit->message = pesan_sementara;
        new_commit->author = string();
        new_commit->time=getCurrentTimestamp();
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

void log(Repository* repo, string author){
    Branch* branch_aktif = &(repo->brach[repo->idx_branch_active]);
    cout << "git log [" << branch_aktif->nama << "]" << endl;
    cout << "--------------------------------------------" << endl;

    if(branch_aktif->head_commit == nullptr) {
        cout << "(No commits on this branch)" << endl;
    } else {
        Commit* penelusur = branch_aktif->head_commit;
        while(penelusur != nullptr) {
            cout << COLOR_YELLOW << "commit " << penelusur->hash << COLOR_RESET << endl;
            cout << "Author: " << penelusur->author << endl;
            cout << "Date  : " << penelusur->time << endl;
            cout << "\n    " << penelusur->message << "\n" << endl;
            penelusur = penelusur->parent;
        }
    }
    cout << "--------------------------------------------" << endl;
}

void init_repository(Repository* repo, string repo_name) {
    repo->name = repo_name;
    repo->banyak_brach = 1;
    repo->idx_branch_active = 0;

    repo->brach = new Branch[1];
    repo->brach[0].nama = "main";
    repo->brach[0].head_commit = nullptr;
    repo->brach[0].commit_count = 0;
}


int main(int argc, char *argv[])
{   Repository* repo =  new Repository;
    string nama_sementara;
    string nama_author=argv[1];
    int pilihan=-1;
    int total_repo = 1;
    int idx_repo_active = 0;


    cout<<COLOR_CYAN " GITSIM "<<COLOR_RESET<<"- Lightweight Git Simulator"<<endl;    
    cout<<COLOR_GRAY<<"Author :"<<COLOR_RESET<<nama_author<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"git init"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<COLOR_CYAN " Repository name :"<<COLOR_RESET; getline(cin, nama_sementara);
    if(nama_sementara.empty()){
        repo->name= "my-repo";
    }else{
        repo->name= nama_sementara;
    }
    cout<<COLOR_GREEN "[OK]" COLOR_RESET<<"Initialized empty repository: "<<repo->name;
    
    

    cout << COLOR_GREEN "[OK] " COLOR_RESET << "Initialized empty repository: " << repo->name << endl;
    cout << "On branch: main\n" << endl;
    system("pasue");

    cout<<COLOR_CYAN " GITSIM "<<COLOR_RESET;  
    cout<<COLOR_GRAY<<"Author :"<<COLOR_RESET<<nama_author<<" | "<<COLOR_GRAY<<"Repo : "<<COLOR_RESET<<repo->name<<" | "<<COLOR_GRAY<<"HEAD : "<<COLOR_RESET<<repo->brach.nama<<" | "<<COLOR_GRAY<<"["<<COLOR_RESET<<repo->idx_branch_active<<COLOR_GRAY<<"]"<<COLOR_RESET;

    cout << "[1] git commit" << endl;
    cout << "[2] git log" << endl;
    cout << "[3] git branch" << endl;
    cout << "[4] git checkout" << endl;
    cout << "[0] exit" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Pilih menu: ";cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        commit(repo, nama_author);
        break;
    case 2:
        
        break;
    
    default:
        break;
    }
    return 0;
}
