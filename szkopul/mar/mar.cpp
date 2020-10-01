#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> m >> n;

    int lyse_pole[201][200] = {};

    for(int i=0; i < m; i++){
        string a;
        cin >> a;
        for(int j = 0; j < n; j++){
            if(a[j] == '.'){
                lyse_pole[j+1][i] = lyse_pole[j][i] + 0;
            }
            if(a[j] == 'x'){
                lyse_pole[j+1][i] = lyse_pole[j][i] + 1;
            }
        }
    }

    int naj = 0;
    int ilosc = 0;

    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            int suma = 0;
            int roz = naj;
            while(suma == 0 && j+roz <= n+1 && i+roz <= m+1){
                for(int g = 0; g < roz; g++){
                    suma += lyse_pole[j+roz][i+g] - lyse_pole[j][i+g];
                }
                roz++;
            }
            roz-=2;
            if(roz > naj){
                ilosc = 1;
                naj = roz;
            }
            else if(roz == naj && roz > 0)
                ilosc++;
            
        }
    }

    cout << naj << ' ' << ilosc;

    return 0;
}