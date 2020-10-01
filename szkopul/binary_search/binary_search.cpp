#include <bits/stdc++.h>

using namespace std;

int main(){
    int liczb;
    cin >> liczb;
    int liczby[liczb];
    for(int i = 0; i< liczb; ++i){
        cin >> liczby[i];
    }
    int p;
    cin >> p;

    bool nima = false;

    while(p--){
        nima = false;
        int search;
        cin >> search;
        int przes = liczb/2;
        int i = przes;
        
        if(search < liczby[0] || liczby[liczb-1] < search){
            nima = true;
        }
        else{
            while(search != liczby[i] && !nima){
                przes  = max(1, przes/= 2);
                if(search < liczby[i]){
                    i -= przes;
                }
                else{
                    i += przes;
                }
                if(przes == 1 && liczby[i] < search &&  search < liczby[i+1]){
                    nima = true;
                }
            }
        }

        if(nima)
            cout << "X" << endl;
        else
            cout << i << endl;
        
    }
    return 0;
}