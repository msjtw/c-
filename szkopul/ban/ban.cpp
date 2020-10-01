#include <iostream>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ilosc;
    cin >> ilosc;
    int goscie[ilosc+1];
    goscie[0] = 0;
    for(int i = 1; i < ilosc+1; ++i){
        cin >> goscie[i];
    }
    int przydzieleni = 0;

    int i = 0;
    int stoly = 0;

    while(przydzieleni < ilosc){
        for(int iii = 0; iii < ilosc && goscie[iii] == 0; ++iii){
            i = iii+1;
        }
        int ii = goscie[i];
        goscie[i] = 0;
        przydzieleni++;
        while(0 != goscie[ii]){
            int help = ii;
            ii = goscie[ii];
            goscie[help] = 0;
            przydzieleni++;
        }
        stoly++;
    }

    cout << stoly;

    return 0;
}