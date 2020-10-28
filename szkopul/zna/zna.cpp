#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

string imiona [301];

short mac[301][301] {};
short il[301] {};

struct boop{
    int n;
    vector <short> steps;
    int len = 0;
};

bool odw [301] {};

boop dp(int pocz, int kon){
    queue <boop> as;
    boop poc;
    poc.n = pocz;
    as.push(poc);
    while(as.front().n != kon){
        odw[as.front().n] = true;
        for(int i = 0; i < il[as.front().n]; i++){
            boop df;
            df.n = mac[as.front().n][i];
            df.steps = as.front().steps;
            df.steps.push_back(mac[as.front().n][i]);
            df.len = as.front().len+1;
            if(!odw[df.n])
                as.push(df);
        }
        as.pop();
        if(as.size() == 0){
            boop gh;
            gh.n = -420;
            return gh;
        }
    }
    return as.front();
}


int main(){
    
    int ilosc;
    cin >> ilosc;
    cin.ignore(1);
    for(int i = 0; i < ilosc; i++){
        string a;
        getline(cin, a);
        int j =0;
        while(a[j] != ' '){
            imiona[i] += a[j];
            j++;
        }
        j++;
        while(j < a.size()){
            int hcp = 0;
            while(a[j] != ' ' && j < a.size()){
                hcp *= 10;
                hcp += (a[j]-'0');
                j++;
            }
            hcp--;
            mac[i][il[i]] = hcp;
            il[i]++;
            j++;
        }
    }
    string a, b;
    cin >> a >> b;
    int po, ko;
    for(int i = 0;i < ilosc; i++){
        if(imiona[i] == a)
            po = i;
        if(imiona[i] == b)
            ko = i;
    }

    boop wynik = dp(po, ko);

    if(wynik.n == -420){
        cout << "BRAK";
    }
    else{
        if(wynik.steps.size() == 2){
            cout << "ZNAJOMI";
        }
        else{
            for(int i = 1; i < wynik.steps.size()-1; i++){
                cout << imiona[wynik.steps[i]] << " ";
            }
        }
    }
    


    return 0;
}