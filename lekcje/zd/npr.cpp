#include <iostream>
#include <string>

using namespace std;

struct litera{
    int r;
    int c;
};

char tab_szyfr[5][5] {};

bool bylo[256] {};

litera pozycje[256] {};

int main(){
    bylo['J'] = true;
    string tekst;
    string a;
    getline(cin, a);
    getline(cin ,tekst);

    int nr = 0;

    for(int i = 0; nr < 25 && i < a.size(); i++){
        a[i] = toupper(a[i]);
        if(a[i] == 'J') a[i] == 'I';
        if(a[i] >= 'A' && a[i] <= 'Z'){
            if(!bylo[a[i]]){
                bylo[a[i]] = true;
                tab_szyfr[nr/5][nr%5] = a[i];
                pozycje[a[i]].r=nr/5;
                pozycje[a[i]].c=nr%5;
                nr++;
            }
        }
    }
    for(int i = 'A'; i <= 'Z' && nr < 25; i++){
        if(!bylo[i]){
            tab_szyfr[nr/5][nr%5] = char(i);
            pozycje[i].r=nr/5;
            pozycje[i].c=nr%5;
            nr++;
        }
    }

    for(int i =0; i < tekst.size(); i++){
        tekst[i] = toupper(tekst[i]);
        if(tekst[i] > 'Z' || tekst[i] < 'A'){
            tekst.erase(tekst.begin()+i);
            i--;
        }
        if(tekst[i] == 'J')
            tekst[i] = 'I';
    }

    if(tekst.size()%2 == 1)
        tekst = tekst + "X";

    for(int i = 0; i < tekst.size()-1; i+=2){
        litera pier, druga;
        pier = pozycje[tekst[i]];
        druga = pozycje[tekst[i+1]];
        if(pier.r != druga.r){
            if(pier.c != druga.c){
                int temp = pier.c;
                pier.c = druga.c;
                druga.c = temp;
            }
            else{
                pier.r = (pier.r+1)%5;
                druga.r = (druga.r+1)%5;
            }
        }
        else{
            if(pier.c != druga.c){
                pier.c = (pier.c+1)%5;
                druga.c = (druga.c+1)%5;
            }
        }
        tekst[i] = tab_szyfr[pier.r][pier.c];
        tekst[i+1] = tab_szyfr[druga.r][druga.c];
    }

    std::cout << tekst;

    return 0;
}