#include <iostream>
#include <vector>

using namespace std;

struct punkt{
    int x;
    int y;
};

struct linia{
    punkt p;
    punkt q;
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

    if((il1 > 0 && il2 < 0 || il1 < 0 && il2 > 0) && (il3 > 0 && il4 < 0 || il3 < 0 && il4 > 0))
        return 1;
    // if((il1 == 0 && pkt_na(c, d, a)) || (il2 == 0 && pkt_na(c, d, b)) || (il3 == 0 && pkt_na(a, b, c)) || (il4 == 0 && pkt_na(a, b, d)))
    //     return 1;

    return 0;
}


int main(){
    vector <punkt> punkty;
    punkt srodek;
    int ilosc_bokow;
    cin >> ilosc_bokow;
    while(ilosc_bokow--){
        punkt a;
        cin >> a.x >> a.y;
        punkty.push_back(a);
    }
    punkty.push_back(punkty[0]);

    int w = 0;
    int ochrona;
    cin >> ochrona;
    for(int j = 0; j < ochrona; j++){
        punkt ochroniarz;
        cin >> ochroniarz.x >> ochroniarz.y;
        bool pa = false;
        bool pb = false;
        for(int i = 0; i < punkty.size()-1; i++){
            punkt a, b;
            a.x = 30000;
            a.y = 30000;
            b.x = -30000;
            b.y = -30000;

            if(!pa && przecina(ochroniarz, a, punkty[i], punkty[i+1])){
                pa = true;
            }
            else if(!pb && przecina(ochroniarz, b, punkty[i], punkty[i+1])){
                pb = true;
            }

        }
        if(pa && pb)
            w++;
    }
    cout << ochrona-w;

    return 0;
}