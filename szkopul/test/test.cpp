#include <bits/stdc++.h>

using namespace std;

int main(){

    int ilosc;
    cin >> ilosc;

    int liczby[1000000] = {};

    for(int i = 0; i < ilosc; ++i){
        int a;
        cin >> a;
        if(a > ilosc){
            cout << "NIE";
            return 0;
        }
        else{
            liczby[a]++;
        }
    }

    bool popsuted = false;

    for(int i = 0; i < ilosc; ++i){
        if(liczby[i] != 1){
            popsuted = true;
            break;
        }
    }

    if(popsuted){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }

    return 0;
}