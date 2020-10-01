#include <iostream>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int wyd[200001] = {};
    wyd[0] = 0;
    int dni;
    cin >> dni;
    int osob;
    cin >> osob;
    for(int i = 1; i < dni+1; i++){
        int dzien;
        cin >> dzien;
        wyd[i] = wyd[i-1] + dzien;
        if(wyd[i] >= 0)
                wyd[i] %= osob;
            else
                wyd[i] = (wyd[i]%osob) + osob;
    }

    int naj =0;

    for(int i = 0; i < dni; i++){
        for(int j = i; j < dni; j++){
            int suma = wyd[j+1] - wyd[i];
            if(suma >= 0)
                naj = max(naj, suma%osob);
            else
                naj = max(naj, (suma%osob)+osob);
        }
    }

    cout << naj;
    
    return 0;
}