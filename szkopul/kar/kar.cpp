#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int no_nie_moge;
    cin >> no_nie_moge;
    
    string liczba;
    cin >> liczba;
    int jedynek = 0;
    int zer = 0;
    for(char c : liczba){
        if(c == 'n')
            jedynek++;
        else if(c == 'z')
            zer++;
    }

    int pot = 1;
    for(int i = 0; i < zer; i++){
        pot *= 2;
    }
    int dec = 0;
    for(int i = 0; i < jedynek; i++){
        dec += pot;
        pot *= 2;
    }

    string asa = "";

    while(jedynek--){
        asa += '1';
    }
    while(zer--){
        asa += '0';
    }
    cout << asa << ' ' << dec;
    return 0;
}