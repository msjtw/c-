#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct skarbonka{
    int id;
    vector <int> klucze;
};

bool sor(skarbonka a, skarbonka b){
    return a.klucze.size()>b.klucze.size();
}

vector <skarbonka> skarbonki;

bool odw[1000010];
int nowe_id[100010];

int main(){
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
    }
    sort(skarbonki.begin(),skarbonki.end(),sor);
    for(int i = 0; i < skarbonki.size(); i++)
        nowe_id[skarbonki[i].id] = i;
    for(int i = 0; i < skarbonki.size(); i++){
        for(int j = 0; j < skarbonki[i].klucze.size(); j++){
            skarbonki[i].klucze[j] = nowe_id[skarbonki[i].klucze[j]];
        }
    }
    int odwiedzono = 0;
    int rozbito = 0;
    while(ile > odwiedzono){
        rozbito++;
        vector <int> do_odw;
        int as = 0;
        for(;odw[as];as++);
        do_odw.push_back(as);
        int j = 0;
        while(j < do_odw.size()){
            odwiedzono++;
            odw[do_odw[j]] = true;
            for(int i = 0; i < skarbonki[do_odw[j]].klucze.size(); i++){
                if(!odw[skarbonki[do_odw[j]].klucze[i]])
                    do_odw.push_back(skarbonki[do_odw[j]].klucze[i]);
            }
            j++;
        }
    }
    cout << rozbito;

    return 0;
}