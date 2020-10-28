#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int tab[10010] {};
    int w;
    cin >> w;
    int p, q, r;
    while(true){
        cin >> p >> q >> r;
        if(p == 0 && q == 0 && r == 0){
            break;
        }
        for(int i = p-1; i < q; i++){
            tab[i] = max(tab[i], r);
        }
    }
    int suma = 0;
    for(int i = 0; i <= w; i++){
        suma += tab[i];
    }
    cout << suma;

    return 0;
}