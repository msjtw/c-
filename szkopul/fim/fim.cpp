#include <iostream>
#include <algorithm>

using namespace std;

int mac[2010];
int wart[2010];

int sfd(int a){
    if(a != -2)
        return sfd(mac[a])+1;
    else
        return 0;
}

int main(){
    int ilosc;
    cin >> ilosc;
    for(int i = 0; i< ilosc; i++){
        cin >> mac[i];
        mac[i]--;
    }
    for(int i =0; i < ilosc; i++){
        wart[i] = sfd(i);
    }
    int ma = wart[0];
    for(int i = 0; i < ilosc;i ++){
        ma = max(ma, wart[i]);
    }
    cout << ma;

    return 0;
}