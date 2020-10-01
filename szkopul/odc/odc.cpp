#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int ilosc;
    cin >> ilosc;
    int dni[ilosc];
    for(int i = 0; i < ilosc; ++i){
        cin >> dni[i];
    }

    int pocz = 0;
    int maxim = 0;
    int malo = INT_MAX;

    for(int i = 0; i < ilosc -1; ++i){
        if(dni[i] > dni[pocz]){
            maxim = max(maxim, dni[pocz] - malo);
            pocz = i;
            malo = INT_MAX;
        }
        malo = min(malo, dni[i]);
    }
    malo = min(malo, dni[ilosc-1]);
    maxim = max(maxim, dni[pocz] - malo);
    cout << maxim;

    return 0;
}