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
    char author[100];
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


void nama_author(const char *ikan){
    Commit author;
    cout<<COLOR_CYAN " GITSIM "<<COLOR_RESET<<"- Lightweight Git Simulator"<<endl;    
    cout<<COLOR_GRAY<<"Author :"<<COLOR_RESET;
    for(int i=0; ikan[i]!='\0' ; i++ ){
    author.author[i]=ikan[i];
    }
    cout<<author.author<<endl;
}
void commit(Repository* repo, const char *ikan){
    Commit* new_commit = new Commit;
    Branch* new_commit = new Branch;
    cout<<COLOR_CYAN " GITSIM "<<COLOR_RESET<<"- Lightweight Git Simulator"<<endl;    
    cout<<COLOR_GRAY<<"Author :"<<COLOR_RESET;
    nama_author(ikan);
    new_commit.
}

int main(int argc, char *argv[])
{   Repository* repo =  new Repository;
    string nama_sementara;

    nama_author(argv[1]);
    cout<<"--------------------------------------------"<<endl;
    cout<<"git init"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<COLOR_CYAN " Repository name :"<<COLOR_RESET;getline(cin, nama_sementara);
    if(nama_sementara.empty()){
        repo->name= "my-repo";
    }else{
        repo->name= nama_sementara;
    }
    cout<<COLOR_GREEN "[OK]" COLOR_RESET<<"Initialized empty repository: "<<repo->name;
    return 0;
}
