#include <bits/stdc++.h>

using namespace std;

int main(){

    int ilosc_bitow;
    cin >> ilosc_bitow;
    ilosc_bitow *= 8;

    int liczba;
    cin >> liczba;

    bool dodatnia = liczba > 0 ? true : false;
    liczba = abs(liczba);

    vector <int> u1;

    while(liczba != 0){
        u1.push_back(liczba%2);
        liczba /= 2;
    }

    if(u1.size() >= ilosc_bitow){
        cout << "ERROR";
        return 0;
    }
    else{
        while(u1.size() < ilosc_bitow){
            u1.push_back(0);
        }
    }

    reverse(u1.begin(), u1.end());

    if(dodatnia){
        for(int a : u1){
            cout << a;
        }
    }
    else{
        for(int a : u1){
            if(a == 1)
                cout << 0;
            else
                cout << 1;
        }

    }

    return 0;
}