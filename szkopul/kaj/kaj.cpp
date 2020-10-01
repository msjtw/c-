#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int maxkajaka;
    cin >> maxkajaka;

    int ilosc;
    cin >> ilosc;
    int osoby[30000] = {};
    for(int i = 0; i < ilosc; i++){
        cin >> osoby[i];
    }

    sort(osoby, osoby+ilosc);

    int kajakow = 0;
    for(int i = 0, j = ilosc-1; i <= j;){
        if(osoby[i]+osoby[j] <= maxkajaka || i == j)
            i++;
        kajakow++;
        j--;
    }

    cout << kajakow;

    return 0;
}