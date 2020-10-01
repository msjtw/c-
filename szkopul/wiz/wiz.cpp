#include <bits/stdc++.h>

using namespace std;

struct cookie
{
    int quan;
    int value;
    int pom;
};

bool por(cookie left, cookie right){
    return left.value > right.value;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ilosc;
    cin >> ilosc;

    cookie cookies[200000] = {};

    for(int i = 0; i < ilosc; ++i){
        cin >> cookies[i].value;
    }
    for(int i = 0; i < ilosc; ++i){
        cin >> cookies[i].quan;
    }

    sort(cookies, cookies+ilosc, por);

    int p;
    cin >> p;
    while(p--){
        int waga;
        cin >> waga;
        int licznik = 0;
        while (waga > 0)
        {
            int i = 0;
            while(cookies[i].quan == 0)
                i++;
            waga-=cookies[i].value;
            cookies[i].quan--;
            licznik++;
        }
        cout << licznik << endl;
    }
   return 0;
}
