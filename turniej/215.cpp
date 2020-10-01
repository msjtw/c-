#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector <bool> ks;
    int k;
    cin >> k;
    while(k--){
        bool a;
        cin >> a;
        ks.push_back(a);
    }

    int z = 0;
    int j = 0;
    for(auto a : ks){
        if(a == 0){
            z++;
        }
        else{
            j++;
        }
    }

    if(j-1 > z){
        cout << -1;
        return 0;
    }

    int licznik = 0;

    for(size_t i = 0; i < ks.size()-1; i++){
        if(ks[i] == 1 && ks[i+1] == 1){
            licznik++;
        }
    }
    cout << licznik;
    return 0;
}