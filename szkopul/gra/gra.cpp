#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int zaw;
    cin >> zaw;
    int zawodnicy[zaw];
    for(int i = 0; i < zaw; ++i){
        cin >> zawodnicy[i];
    }

    sort(zawodnicy, zawodnicy+zaw);

    int punkty[zaw/2];
    for(int i = 0, j = zaw -1; i < zaw/2; ++i, --j){
        punkty[i] = zawodnicy[i] + zawodnicy[j];
    }
    sort(punkty, punkty + zaw/2);

    int suma = 0;

    for(int i = zaw/2 -2; i >= 0; --i){
        suma += punkty[zaw/2-1] - punkty[i];
    }

    cout << suma;

    return 0;
}