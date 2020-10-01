#include <iostream>
#include <algorithm>

using namespace std;

int filary[100001];
int memo[100001][3];

int dp(int pozostalo, int z_kolei){
    int wynik;
    if(memo[pozostalo][z_kolei] == -1){
        if(pozostalo == 0){
            wynik = 0;
        }
        else if(z_kolei == 2){
            wynik = dp(pozostalo-1, 0);
        }
        else{
            wynik = max(dp(pozostalo-1, 0), dp(pozostalo-1, z_kolei+1) + filary[pozostalo]);
        }
        memo[pozostalo][z_kolei] = wynik;
    }
    else{
        wynik = memo[pozostalo][z_kolei];
    }
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(false);

    int ilosc;
    cin >> ilosc;
    for(int i = 1; i <= ilosc; i++){
        cin >> filary[i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 100001; j++){
            memo[j][i] = -1;
        }
    }

    cout << dp(ilosc, 0);
    return 0;
}