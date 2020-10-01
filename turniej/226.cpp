#include <bits/stdc++.h>

using namespace std;

int main(){
    int ilosc, skok;
    cin >> ilosc >> skok;
    vector <int> tram;
    while (ilosc--)
    {
        int a;
        cin >> a;
        tram.push_back(a);
    }

    int pocz = tram[0];

    sort(tram.begin(), tram.end());


    int poppp = 0;

    int ii;
    for(int i = 0; i < tram.size(); i++){
        if(tram[i] == pocz)
            ii = i;
    }
    
    for(int i = ii ; i < tram.size()-1; ++i){
        if(tram[i] + skok >= tram[i+1]){
            poppp++;
        }
    }

    for(int i = ii; i > 0; i--){
        if(tram[i] + skok >= tram[i-1]){
            poppp++;
        }
    }

    cout << poppp;
    
    return 0;
}