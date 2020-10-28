#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct punkt{
    int x;
    int y;
};

struct pret{
    punkt a;
    punkt b;
    long double dlugosc;
};

struct pret_v2{
    pret rzebrowanie;
    int id;
};


int iloczyn(punkt a, punkt b, punkt c){
    return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}
bool pkt_na(punkt a, punkt b, punkt c){
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}
bool przecina(punkt a, punkt b, punkt c, punkt d){
    int il1 = iloczyn(c, d, a);
    int il2 = iloczyn(c, d, b);
    int il3 = iloczyn(a, b, c);
    int il4 = iloczyn(a, b, d);

    if((il1>0&&il2<0||il1<0&&il2>0)&&(il3>0&&il4<0||il3<0&&il4>0))
        return 1;
    if((il1 == 0 && pkt_na(c, d, a)) || (il2 == 0 && pkt_na(c, d, b)) || (il3 == 0 && pkt_na(a, b, c)) || (il4 == 0 && pkt_na(a, b, d)))
        return 1;

    return 0;
}

int main(){
    long long int wynik = 0;
    bool tura1 = true;

    vector <pret> prety;
    while(true){
        pret rzut;
        cin >> rzut.a.x >> rzut.a.y >> rzut.b.x >> rzut.b.y;
        if(rzut.a.x == 0 && rzut.a.y == 0 && rzut.b.x == 0 && rzut.b.y == 0)
            break;
        rzut.dlugosc = sqrt(pow(rzut.b.x-rzut.a.x, 2)+pow(rzut.b.y-rzut.a.y, 2));
        if(prety.size() > 0){
            vector <pret_v2> wspolne;
            for(int i = 0; i < prety.size(); i++){
                if(przecina(prety[i].a, prety[i].b, rzut.a, rzut.b)){
                    pret_v2 helpme;
                    helpme.rzebrowanie = prety[i];
                    helpme.id = i;
                    wspolne.push_back(helpme);
                }
            }
            if(wspolne.size() > 0){
                pret_v2 najdluzszy = wspolne[0];
                for(int i = 0; i < wspolne.size(); i++){
                    if(najdluzszy.rzebrowanie.dlugosc < wspolne[i].rzebrowanie.dlugosc){
                        najdluzszy = wspolne[i];
                    }
                }
                if(tura1){
                    wynik += najdluzszy.rzebrowanie.dlugosc*najdluzszy.rzebrowanie.dlugosc + rzut.dlugosc*rzut.dlugosc;
                    tura1 = false;
                }
                else{
                    wynik -= najdluzszy.rzebrowanie.dlugosc*najdluzszy.rzebrowanie.dlugosc + rzut.dlugosc*rzut.dlugosc;
                    tura1 = true;
                }

                prety.erase(prety.begin()+najdluzszy.id);
            }
            else{
                prety.push_back(rzut);
            }
        }
        else{
            prety.push_back(rzut);
        }

    }
    cout << abs(wynik);

    return 0;
}