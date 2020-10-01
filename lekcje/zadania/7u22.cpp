#include <bits/stdc++.h>

using namespace std;

int main (){

    string liczba;
    cin >> liczba;

    if(liczba[0] == '1'){
        int liczba_dz = 0;
        int pot = 1;
        for(int i = liczba.size()-1 ; i > 0; --i){
            liczba_dz += (liczba[i]-'0')*pot;
            pot *= 2;
        }
        
        int n = 1;
        for(int i =0 ; i < liczba.size()-1; ++i){
            n*=2;
        }

        cout << -1*(n-liczba_dz);
    }
    else{
        int liczba_dz = 0;
        int pot = 1;
        for(int i = liczba.size()-1 ; i > 0; --i){
            liczba_dz += (liczba[i]-'0')*pot;
            pot *= 2;
        }

        cout << liczba_dz;
    }

    return 0;
}