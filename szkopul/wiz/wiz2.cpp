#include <iostream>
#include <algorithm>

using namespace std;

struct ciastko{
    int masa;
    int ilosc;
};

struct wizyta{
    int cel;
    int id;
};

bool por(ciastko lewe, ciastko prawe){
    return lewe.masa > prawe.masa;
}

bool por2(wizyta lewa, wizyta prawa){
    return lewa.cel < prawa.cel;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ciastko ciastka[200100] = {};

    int ilosc_roz;
    cin >> ilosc_roz;
    for(int i = 0; i < ilosc_roz; ++i){
        cin >> ciastka[i].masa;
    }
    for(int i = 0; i < ilosc_roz; ++i){
        cin >> ciastka[i].ilosc;
    }

    sort(ciastka, ciastka+ilosc_roz, por);

    wizyta wizyty[200100];

    int wizyt;
    cin >> wizyt;
    for(int i = 0; i < wizyt; ++i){
        cin >> wizyty[i].cel;
        wizyty[i].id = i;
    }

    sort(wizyty, wizyty+wizyt, por2);

    int wyniki[200100];

    long long int masa = 0;
    int j = 0;
    int zjedzono = 0;

    for(int i =0; i < wizyt; ++i){
        while(wizyty[i].cel > masa){
            if(wizyty[i].cel > ciastka[j].masa*ciastka[j].ilosc+masa){
                masa += ciastka[j].masa*ciastka[j].ilosc;
                zjedzono += ciastka[j].ilosc;
                ciastka[j].ilosc = 0;
                j++;
            }
            else{
                if(ciastka[j].ilosc > 0){
                    masa += ciastka[j].masa;
                    ciastka[j].ilosc--;
                    zjedzono++;
                }
                else{
                    j++;
                }
            }
        }
        wyniki[wizyty[i].id] = zjedzono;
    }

    for(int i = 0; i < wizyt; ++i){
        cout << wyniki[i] << endl;
    }

    return 0;
}