#include <bits/stdc++.h>
using namespace std;

string dec2hex(int);

int main(){
    int a;
    cin >> a;

    cout << dec2hex(a);

    return 0;
}

string dec2hex(int a){
    string wynik = {};

    while(a != 0){
        int adc = a%16;
        if(adc > 9){
            char c = 'A'+adc-10;
            wynik += c;
        }
        else{
            char c = '0'+adc;
            wynik += c;
        }
        a /= 16;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}