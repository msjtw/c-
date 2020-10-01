#include <bits/stdc++.h>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int dw;
    int dt;
    cin >> dw >> dt;

    string wzorzec;
    string tekst;

    cin >> wzorzec >> tekst;

    string wynik = "";

    for(int i = 0; i < tekst.length()-1; ++i){
        if(tekst[i] == wzorzec[0] && tekst[i+1] == wzorzec[1]){
            int ii = i+2;
            int j = 0;
            while(tekst[ii+j]==wzorzec[j+2] && ii+j < tekst.length()-1 && j < wzorzec.length()){
                j++;
            }
            wynik += tekst[ii+j];
        }
    }

    cout << wynik;
    return 0;
}