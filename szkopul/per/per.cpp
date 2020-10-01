#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ilosc;
    cin >> ilosc;

    int liczby[1000001] = {};

    for(int i = 0; i < ilosc; ++i){
        int a;
        cin >> a;
        if(a > ilosc){
            cout << "NIE";
            return 0;
        }
        else{
            //cout << a << ": " << liczby[a] << " -> ";
            liczby[a]++;
            //cout << liczby[a] << endl;
        }
    }

    bool popsuted = false;

    for(int i = 1; i < ilosc+1; ++i){
        //cout << liczby[i] << endl;
        if(liczby[i] != 1){
            popsuted = true;
            break;
        }
    }

    if(!popsuted){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }

    return 0;
}