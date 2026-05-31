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
    Branch* branches= nullptr;
    Commit commit;
    int banyak_brach;
    int idx_branch_active;
};


void commit(Repository* repo, string author){
    Branch* branch_aktif = &(repo->branches[repo->idx_branch_active]);
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
    Branch* branch_aktif = &(repo->branches[repo->idx_branch_active]);
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

    repo->branches = new Branch[1];
    repo->branches[0].nama = "main";
    repo->branches[0].head_commit = nullptr;
    repo->branches[0].commit_count = 0;
}

void buat_branch(Repository* repo, string author) {
    cout << "git branch" << endl;
    cout << "--------------------------------------------" << endl;
    for(int i = 0; i < repo->banyak_brach; i++) {
        if(i == repo->idx_branch_active) {
            cout << COLOR_GREEN << "* " << repo->branches[i].nama << " (" << repo->branches[i].commit_count << " commits)" << COLOR_RESET << endl;
        } else {
            cout << "  " << repo->branches[i].nama << " (" << repo->branches[i].commit_count << " commits)" << endl;
        }
    }
    cout << "--------------------------------------------" << endl;

    cout << "New branch name: ";
    string nama_baru;
    getline(cin, nama_baru);

    if(nama_baru.empty()) {
        cout << COLOR_RED << "[ERROR] Branch name cannot be empty!" << COLOR_RESET << endl;
        return;
    }

    for(int i = 0; i < repo->banyak_brach; i++) {
        if(repo->branches[i].nama == nama_baru) {
            cout << COLOR_RED << "[ERROR] Branch '" << nama_baru << "' already exists!" << COLOR_RESET << endl;
            return;
        }
    }

    Branch* branches_baru = new Branch[repo->banyak_brach + 1];

    for(int i = 0; i < repo->banyak_brach; i++) {
        branches_baru[i].nama = repo->branches[i].nama;
        branches_baru[i].head_commit = repo->branches[i].head_commit;
        branches_baru[i].commit_count = repo->branches[i].commit_count;
    }

    Branch* branch_sekarang = &(repo->branches[repo->idx_branch_active]);
    branches_baru[repo->banyak_brach].nama = nama_baru;
    branches_baru[repo->banyak_brach].head_commit = branch_sekarang->head_commit; 
    branches_baru[repo->banyak_brach].commit_count = branch_sekarang->commit_count;

    delete[] repo->branches;

    repo->branches = branches_baru;
    repo->banyak_brach++;

    cout << COLOR_GREEN << "[OK] Branch '" << nama_baru << "' created from '" << branch_sekarang->nama << "'" << COLOR_RESET << endl;
}

void checkout(Repository* repo, string author) {
    cout << "git checkout" << endl;
    cout << "--------------------------------------------" << endl;
    for(int i = 0; i < repo->banyak_brach; i++) {
        if(i == repo->idx_branch_active) {
            cout << COLOR_GREEN << "* " << repo->branches[i].nama << COLOR_RESET << endl;
        } else {
            cout << "  " << repo->branches[i].nama << endl;
        }
    }
    cout << "--------------------------------------------" << endl;
    cout << "Switch to branch: ";
    string target;
    getline(cin, target);

    int target_idx = -1;
    for(int i = 0; i < repo->banyak_brach; i++) {
        if(repo->branches[i].nama == target) {
            target_idx = i;
            break;
        }
    }

    if(target_idx == -1 || target_idx == repo->idx_branch_active) {
        cout << COLOR_RED << "[ERROR] Invalid branch name or already active!" << COLOR_RESET << endl;
    } else {
        repo->idx_branch_active = target_idx;
        cout << COLOR_GREEN << "[OK] Switched to branch '" << target << "'" << COLOR_RESET << endl;
    }
}


int main(int argc, char *argv[])
{   Repository* daftar_repo =  new Repository[1];
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
        init_repository(&(daftar_repo[0]), "my-repo");
    }else{
        init_repository(&(daftar_repo[0]), nama_sementara);
    }
    
    cout << COLOR_GREEN "[OK] " COLOR_RESET << "Initialized empty repository: " << daftar_repo[0].name << endl;
    cout << "On branch: main\n" << endl;
    system("pause");

    while(pilihan != 0) {

        Repository* repo_aktif = &(daftar_repo[idx_repo_active]);
        Branch* branch_aktif = &(repo_aktif->branches[repo_aktif->idx_branch_active]);

        cout << COLOR_CYAN " GITSIM Git Simulator" << COLOR_RESET << endl;
        cout << COLOR_GRAY << "Author : " << COLOR_RESET << nama_author
             << COLOR_GRAY << " | Repo : " << COLOR_RESET << repo_aktif->name
             << COLOR_GRAY << " | HEAD : " << COLOR_GREEN << branch_aktif->nama << COLOR_RESET
             << COLOR_GRAY << " | [" << COLOR_RESET << (idx_repo_active + 1) << COLOR_GRAY << "/" << total_repo << "]" << COLOR_RESET << endl;
        cout << "--------------------------------------------------------" << endl;

        cout << "[1] git commit" << endl;
        cout << "[2] git log" << endl;
        cout << "[3] git branch" << endl;
        cout << "[4] git checkout" << endl;
        cout << "[5] new repository" << endl;
        cout << "[6] switch repository" << endl;
        cout << "[0] exit" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Pilih menu: "; cin >> pilihan;
        cin.ignore(); 

        switch (pilihan)
        {
        case 1:
            commit(repo_aktif, nama_author);
            cout << "\nPress Enter to return..."; cin.get();
            break;
        case 2:
            log(repo_aktif, nama_author);
            cout << "\nPress Enter to return..."; cin.get();
            break;
        case 3:
            buat_branch(repo_aktif, nama_author);
            cout << "\nPress Enter to return..."; cin.get();
            break;
        case 4:
            checkout(repo_aktif, nama_author);
            cout << "\nPress Enter to return..."; cin.get();
            break;
        case 5: {
            cout << "git init (new repository)" << endl;
            cout << "--------------------------------------------" << endl;
            cout << "New repository name: ";
            string repo_baru_name;
            getline(cin, repo_baru_name);

            if(repo_baru_name.empty()) {
                repo_baru_name = "repo-" + to_string(total_repo + 1);
            }

            bool duplikat_repo = false;
            for(int i = 0; i < total_repo; i++) {
                if(daftar_repo[i].name == repo_baru_name) {
                    duplikat_repo = true;
                    break;
                }
            }

            if(duplikat_repo) {
                cout << COLOR_RED << "[ERROR] Repository '" << repo_baru_name << "' already exists!" << COLOR_RESET << endl;
            } else {
                Repository* daftar_repo_baru = new Repository[total_repo + 1];
                for(int i = 0; i < total_repo; i++) {
                    daftar_repo_baru[i].name = daftar_repo[i].name;
                    daftar_repo_baru[i].branches = daftar_repo[i].branches; 
                    daftar_repo_baru[i].banyak_brach = daftar_repo[i].banyak_brach;
                    daftar_repo_baru[i].idx_branch_active = daftar_repo[i].idx_branch_active;
                }

                init_repository(&(daftar_repo_baru[total_repo]), repo_baru_name);

                delete[] daftar_repo; 
                daftar_repo = daftar_repo_baru;
                
                idx_repo_active = total_repo; 
                total_repo++;

                cout << COLOR_GREEN << "[OK] Repository '" << repo_baru_name << "' created and set as active." << endl;
                cout << "     On branch: main" << COLOR_RESET << endl;
            }
            cout << "\nPress Enter to return..."; cin.get();
            break;
        }
        case 6: {
            cout << "switch repository" << endl;
            cout << "--------------------------------------------" << endl;
            for(int i = 0; i < total_repo; i++) {
                Branch* br_head = &(daftar_repo[i].branches[daftar_repo[i].idx_branch_active]);
                if(i == idx_repo_active) {
                    cout << COLOR_GREEN << "* [" << (i + 1) << "] " << daftar_repo[i].name 
                         << " (" << daftar_repo[i].banyak_brach << " branch, " 
                         << br_head->commit_count << " commits at HEAD)" << COLOR_RESET << endl;
                } else {
                    cout << "  [" << (i + 1) << "] " << daftar_repo[i].name 
                         << " (" << daftar_repo[i].banyak_brach << " branch, " 
                         << br_head->commit_count << " commits at HEAD)" << endl;
                }
            }
            cout << "--------------------------------------------" << endl;
            cout << "Select repository number: ";
            int target_num;
            cin >> target_num;
            cin.ignore();

            int target_idx = target_num - 1;
            if(target_idx >= 0 && target_idx < total_repo) {
                idx_repo_active = target_idx;
                Branch* br_tujuan = &(daftar_repo[idx_repo_active].branches[daftar_repo[idx_repo_active].idx_branch_active]);
                cout << COLOR_GREEN << "[OK] Switched to repository '" << daftar_repo[idx_repo_active].name << "'" << endl;
                cout << "     HEAD: " << br_tujuan->nama << COLOR_RESET << endl;
            } else {
                cout << COLOR_RED << "[ERROR] Invalid repository number!" << COLOR_RESET << endl;
            }
            cout << "\nPress Enter to return..."; cin.get();
            break;
        }
        case 0:
            cout << "Session Ended" << endl;
            cout << "Author: " << nama_author << endl;
            cout << COLOR_MAGENTA << "Goodbye!" << COLOR_RESET << endl;

            for(int i = 0; i < total_repo; i++) {
                Commit* current = daftar_repo[i].branches[0].head_commit;
                while(current != nullptr) {
                    Commit* temp = current->parent;
                    delete current;
                    current = temp;
                }
                delete[] daftar_repo[i].branches;
            }
            delete[] daftar_repo;
            break;

        default:
            cout << COLOR_RED << "Pilihan menu tidak valid!" << COLOR_RESET << endl;
            cout << "\nPress Enter to return..."; cin.get();
            break;
        }
    }


    return 0;
}
