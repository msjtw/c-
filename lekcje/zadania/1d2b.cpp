#include <bits/stdc++.h>
using namespace std;

int bin2dec(string n){
    int wynik = 0;
    int potega = 1;
    reverse(n.begin(), n.end());
    
    for(auto a : n){
        if(a <= '9')
            wynik += (a-'0')*potega;
        else
            wynik += (a-'A'+10)*potega;

        potega *= 16;
    }

    return wynik;
}

int main(){
    string a;
    cin >> a;

    cout << bin2dec(a);

    return 0;
}

