#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ilosc;
    cin >> ilosc;

    vector <int> szczyty;
    for(int i = 0 ;i < ilosc; i++){
        int a;
        cin >> a;
        szczyty.push_back(a);
    }

    int pn, wn;
    cin >> pn >> wn;

    szczyty[pn-1] = wn;

    int sernik_wiedenski = 0;
    for(int i = 0; i < pn-1; i++){
        szczyty[i] = szczyty[i] - sernik_wiedenski - wn;
        sernik_wiedenski = max(sernik_wiedenski, szczyty[i]);
    }
    sernik_wiedenski = 0;
    for(int i = szczyty.size()-1; i > pn-1; --i){
        szczyty[i] = szczyty[i] - sernik_wiedenski - wn;
        sernik_wiedenski = max(sernik_wiedenski, szczyty[i]);
    }

    for(auto a : szczyty){
        cout << a << ' ';
    }
    return 0;
}