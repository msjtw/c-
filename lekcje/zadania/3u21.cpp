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

    if(u1.size() > ilosc_bitow){
        cout << "ERROR";
        return 0;
    }
    else{
        while(u1.size() < ilosc_bitow){
            u1.push_back(0);
        }
    }

    reverse(u1.begin(), u1.end());

    if(!dodatnia){
        for(int i = 0; i < u1.size(); ++i){
            u1[i] = u1[i] == 1 ? 0 : 1;
        }

        u1[u1.size()-1] += 1;
        int przenos = 0;

        for(int i = u1.size() ; i >= 0; --i){
            u1[i] += przenos;
            przenos = 0;
            if(u1[i] == 2){
                u1[i] = 0;
                przenos = 1;
            }
            else if(u1[i] == 3){
                u1[i] = 1;
                przenos = 1;
            }
        }
    }
    
    for(int a : u1){
        cout << a;
    }
    

    return 0;
}