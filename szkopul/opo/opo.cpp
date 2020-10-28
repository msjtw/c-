#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct opona{
    int wew;
    int zew;
};


int main(){
    int tab[10010] {};

    vector <opona> opony;
    int ilosc, szukana;
    cin >> ilosc >> szukana;
    szukana--;
    for(int i = 0; i < ilosc; i++){
        opona a;
        cin >> a.wew >> a.zew;
        opony.push_back(a);
    }
    
    for(int i = 1; i <= szukana; i++){
        int j = i-1;
        while(j >= 0 && opony[j].wew >= opony[i].zew || opony[j].zew <= opony[i].wew)
            j--;
        if(j >= 0)
            tab[i] = tab[j]+1;
    }
    int lewo = tab[szukana];

    reverse(opony.begin(), opony.end());

    szukana += szukana-(ilosc/2);
    for(int i = 0 ; i < ilosc+2; i++){
        tab[i] = 0;
    }

    for(int i = 1; i <= szukana; i++){
        int j = i-1;
        while(j >= 0 && opony[j].wew >= opony[i].zew || opony[j].zew <= opony[i].wew)
            j--;
        if(j >= 0)
            tab[i] = tab[j]+1;
    }
    int prawo = tab[szukana];

    cout << min(prawo, lewo);

    return 0;
}