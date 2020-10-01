#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cin >> m;

    if(m % 2 == 1){
        return 0;
    }

    int v = 0;

    for(int i = 1; i <= m/2; ++i){
        int fale, byk;
        cin >> fale >> byk;
        if(byk%2 != fale%2){
            int pop = fale;
            fale =byk;
            byk = pop;
        }
        fale = fale/10;
        byk = byk*byk*byk;
        if(byk == fale){
            v = v+1;
        }
    }
    cout << v;
    return 0;
}