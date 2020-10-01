#include <iostream>
#include <algorithm>

using namespace std;

struct ludz{
    int poz;
    int wzrost;
};

bool por1(ludz left, ludz right){
    return left.wzrost < right.wzrost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int schodkow, lodzow;

    cin >> schodkow >> lodzow;

    int schodki[50000] = {};
    for(int i = 0; i < schodkow; i++){
        cin >> schodki[i];
    }

    ludz ludzie[50000] = {};
    for(int i = 0 ; i < lodzow; i++){
        ludzie[i].poz = i;
        cin >> ludzie[i].wzrost;
    }

    sort(ludzie, ludzie+lodzow, por1);

    int jak_wysoko = 0;
    int wyniki[50000] = {};

    for(int i = 0; i < lodzow; i++){
        while(ludzie[i].wzrost > schodki[jak_wysoko] && jak_wysoko < schodkow){
            jak_wysoko++;
        }
        wyniki[ludzie[i].poz] = jak_wysoko;
    }

    for(int i = 0; i < lodzow; i++){
        cout << wyniki[i] << ' ';
    }


    return 0;
}