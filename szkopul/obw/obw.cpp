#include <bits/stdc++.h>

struct kabel{
    int nap;
    int wyt;
};

bool por(kabel left, kabel right){
    return left.wyt-left.nap > right.wyt-left.nap;
}

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ilosc;
    cin >> ilosc;

    kabel kable[5000];

    for(int i = 0; i < ilosc; ++i){
        cin >> kable[i].wyt >> kable[i].nap;
    }

    sort(kable, kable+ilosc, por);

    int n_obw = 0;
    int w_obw = 0;
    for(int i = 0 ; i < ilosc; ++i){
        n_obw += kable[i].nap;
        w_obw += kable[i].wyt;
        if(n_obw > w_obw){
            cout << i+1;
            return 0;
        }
    }

    cout << ilosc;

    // for(int i = 0; i < ilosc; ++i){
    //     cout << "nap: " << kable[i].nap << " wyt: " << kable[i].wyt << endl;
    // }

    return 0;
}