#include <bits/stdc++.h>

using namespace std;

struct punkt{
    int x;
    int y;
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
    if((il1 == 0 && pkt_na(c, d, a)) || (il2 == 0 && pkt_na(c, d, b)) || (il3 == 0 && pkt_na(a, b, c)) || (il4 == 0 && pkt_na(a, b, d)))
        return 1;

    return 0;
}

int main(){
    int p;
    cin >> p;
    while(p--){
        punkt a,b,c,d;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        cout << przecina(a,b,c,d) << endl;
    }
}