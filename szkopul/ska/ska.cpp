#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct skarbonka{
    int id;
    vector <int> klucze;
};

bool odwedz[1010] {};




int main(){
    vector <skarbonka> skarbonki;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ile;
    cin >> ile;
    for(int i = 0 ; i < ile; i++){
       skarbonka a;
        a.id = i;
        skarbonki.push_back(a);
    }
    for(int i = 0; i < ile; i++){
        int a;
        cin >> a;
        skarbonki[a-1].klucze.push_back(i);
        skarbonki[i].klucze.push_back(a-1);
    }
    int odwiedzono = 0;
    int us = 0;
    while(odwiedzono < ile){
        us++;
        queue <int> do_odw;
        int as = 0;
        while(odwedz[as])   as++;
        do_odw.push(as);
        while(do_odw.size() > 0){
            odwedz[do_odw.front()] = true;
            odwiedzono++;
            for(int i = 0; i < skarbonki[do_odw.front()].klucze.size(); i++){
                if(!odwedz[skarbonki[do_odw.front()].klucze[i]])
                    //do_odw.push(skarbonki[do_odw.front()].klucze[i]);
            }
            do_odw.pop();
        }
    }
    cout << us;
    return 0;
}