#include <iostream>
#include <algorithm>

using namespace std;

int m[1001];
int w[1001];

int memo[1001][1001];

int dp(int przedmiotow, int masa, int wa){
    int wynik = 0;
    if(memo[przedmiotow][masa] == -1){
        if(przedmiotow == 0 || masa == 0){
            wynik =  wa;
        }
        else if(m[przedmiotow] > masa){
            wynik = dp(przedmiotow-1, masa, wa);
        }
        else{
            wynik = max(dp(przedmiotow-1, masa, wa), dp(przedmiotow-1, masa-m[przedmiotow], wa + w[przedmiotow]) );
        }
        memo[przedmiotow][masa] = wynik;
    }
    else 
        wynik = memo[przedmiotow][masa];
    
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(false);

    int tower, astrovan;
    cin >> tower >> astrovan;
    for(int i = 1; i <= tower; i++){
       cin >> m[i] >> w[i];
    }

    for(int i = 0; i <= tower; i++){
        for(int j = 0; j <= astrovan; j++){
            memo[i][j] = -1;
        }
    }

    cout << dp(tower, astrovan, 0);

    return 0;
}