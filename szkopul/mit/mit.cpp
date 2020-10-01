#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int wysp, mostow;
    cin >> wysp >> mostow;

    int wyspy[1000001] = {};

    while(mostow--){
        int a, b;
        cin >> a >> b;
        wyspy[a]++;
        wyspy[b]++;
    }

    int slabe_wyspy = 0;

    for(int i = 1; i < wysp+1; i++){
        if(wyspy[i] < 2)
            slabe_wyspy++;
    }

    cout << slabe_wyspy;

    return 0;
}