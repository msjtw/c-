#include <bits/stdc++.h>

using namespace std;

long long all2dec(string liczba, int podstawa){
    long long wynik = 0;
    int potenga = 1;

    for(int i = liczba.length()-1; i >= 0; --i){
        if(liczba[i] > '9'){
            wynik += (liczba[i]-'A'+10)*potenga;
        }
        else{
            wynik += (liczba[i]-'0')*potenga;
        }
        potenga *= podstawa;
    }

    return wynik;
}

int main(){
    int podstawa;
    cin >> podstawa;
    string liczba;
    cin >> liczba;

    cout << all2dec(liczba,podstawa);


    return 0;
}