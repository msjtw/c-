#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int p;
    cin >> p;
    long long int prz = 0;
    long long int pr = 0, pp = 0, pd = 0;
    while(p--){
        long long int d, p, r;
        cin >> d >> p >> r;
        if(d+pd > p+pp && d+pd > r+pr){
            pd = 0;
            pr += r;
            pp += p;
            prz += (p+r);
        }
        else if(p+pp > d+pd && p+pp > r+pr){
            pp = 0;
            pd += d;
            pr += r;
            prz += (d+r);
        }
        else if(r+pr > d+pd && r+pr > p+pp){
            pr = 0;
            pd += d;
            pp += p;
            prz += (p+d);
        }
    }
    return 0;
}