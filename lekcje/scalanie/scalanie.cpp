#include <iostream>

using namespace std;

const int ROZ = 10;

void sclanie(int p, int q, int k, int tab[]){
    int wynik[ROZ];
    for(int i = 0, pi = p, qi = q; i < k; i++){
        wynik[i] = tab[pi] > tab[qi] ? tab[qi++] : tab[pi++];
        pi = pi >= q ? qi : pi;
        qi = qi >= k || qi < pi ? pi : qi;
    }
    for(int i =0 ;i < k; i++)
        tab[i] = wynik[i];
}

int main(){
    int tab[ROZ] {};

    for(int i = 0; i < ROZ; i++){
        cin >> tab[i];
    }

    sclanie(0, ROZ/2, ROZ, tab);

    for(int i = 0; i < ROZ; i++){
        cout << tab[i] << endl;
    }

}