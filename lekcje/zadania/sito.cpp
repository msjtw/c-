#include <bits/stdc++.h>

using namespace std;

int tab[1000001] = {};

int main (){
    int p, k;
    cin >> p >> k;
    
    int s = sqrt(k);

    for(int i = 2; i <= s; i++){
        int j = i * 2;
        while(j <= k){
            tab[j] = 1;
            j += i;
        }
    }

    

    bool pop = true;
    for(int i = p; i <= k; i++){
        if(tab[i] == 0){
            cout << i << ' ';
            pop = false;
        }
    }
    if(pop){
        cout << "BRAK";
    }

    return 0;
}