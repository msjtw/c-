#include <bits/stdc++.h>

using namespace std;

int main(){

    int maximum = 0;
    string to_slowo;

    int p = 1000;
    while(p--){
        int znakow[25] = {};
        string slowo;
        getline(cin, slowo);
        for(int i = 0; i < slowo.length(); i++)
            znakow[slowo[i]-'A']++;
        
        int ilosc = 0;
        for(int i = 0; i < 25; i++){
            if(znakow[i] > 0){
                ilosc++;
            }
        }
        if(ilosc > maximum){
            maximum = ilosc;
            to_slowo = slowo;
        }
    }

    cout << to_slowo << ' ' << maximum+1;

    return 0;
}