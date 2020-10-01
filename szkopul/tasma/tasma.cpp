#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int p;
    cin >> p;
    long long tab[p];
    for(int i =0 ; i < p; ++i){
        cin >> tab[i];
    }

    long long suma1 = tab[0];
    long long suma2;
    for(int i = 1; i < p; ++i) suma2 += tab[i];

    long long minu = abs(suma1 - suma2);


    for(int i = 1; i < p-1; ++i){
        suma1 += tab[i];
        suma2 -= tab[i];
        long long abss = abs(suma1-suma2);
        minu = minu < abss ? minu : abss;
    }

    cout << minu;

    return 0;
}