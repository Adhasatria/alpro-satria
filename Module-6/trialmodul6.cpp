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

struct Commit{
    string message;
    string hash;
    char author[100];
};


void nama_author(const char *ikan){
    Commit author;
    cout<<COLOR_CYAN " GITSIM "<<COLOR_RESET<<"- Lightweight Git Simulator"<<endl;    
    cout<<COLOR_GRAY<<"Author :"<<COLOR_RESET;
    for(int i=0; i<ikan[i]; i++ ){
    author.author[i]=ikan[i];
    }
    cout<<author.author;
}
int main(int argc, char *argv[])
{
    nama_author(argv[1]);
    return 0;
}
