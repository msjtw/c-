#include <bits/stdc++.h>

using namespace std;

int main(){
    int licznik = 0;
    string mks;
    int ma = INT_MIN;
    string mni;
    int mi = INT_MAX;

    string licz;
    while(cin >> licz){
        bool popsuted = false;
        for(int i = 1; i < licz.size(); ++i){
            if(licz[i] < licz[i-1]){
                popsuted = true;
                break;
            }
        }
        if(!popsuted){
            licznik++;
            int liczba = 0;
            int pot = 1;
            for(int i = licz.size()-1; i >= 0; --i){
                liczba += (licz[i]-'0')*pot;
                pot *= 8;
            }  
            if(liczba > ma){
                ma = liczba;
                mks = licz;
            }
            if(liczba < mi){
                mi = liczba;
                mni = licz;
            }
        }
    }

    cout << licznik << endl << mks << endl << mni;

    return  0;
}