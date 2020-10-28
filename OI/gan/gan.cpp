#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct as{
    short int cel;
    short int numer;
};

struct miasto{
    short int ak;
    short int pop;
    vector <as> numery;
};

vector <vector<as>> lis;

short int gnomy[150010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int miast, gnomow, p;
    cin >> miast >> gnomow >> p;
    lis.resize(miast+10);

    for(int i = 1; i < miast; i++){
        int a, b, c;
        cin >> a >> b >> c;
        gnomy[i] = c;
        as d;
        d.cel = b;
        d.numer = i;
        lis[a].push_back(d);
        d.cel = a;
        lis[b].push_back(d);
    }

    queue <miasto> koej;
    miasto pier;
    pier.ak = 1;
    koej.push(pier);
    while(koej.size() > 0){
        for(int i = 0; i < lis[koej.front().ak].size(); i++){
            if(lis[koej.front().ak][i].cel != koej.front().pop){
                miasto b;
                b.ak = lis[koej.front().ak][i].cel;
                b.pop = koej.front().ak;
                b.numery = koej.front().numery;
                as temp;
                temp.numer = lis[koej.front().ak][i].numer;
                b.numery.push_back(temp);
                koej.push(b);
            }   
        }
        lis[koej.front().ak] = koej.front().numery;
        koej.pop();
    }


    while(p--){
        char op;
        cin >> op;
        if(op == 'Z'){
            int cel;
            cin >> cel;
            short int moze_kupic[150010] {};
            int ilosc = 0;
            for(auto a : lis[cel]){
                moze_kupic[gnomy[a.numer]]++;
                if(moze_kupic[gnomy[a.numer]] == 1)
                    ilosc++;
            }
            cout << ilosc << "\n";
        }
        else{
            int num, na_co;
            cin >> num >> na_co;
            gnomy[num] = na_co;
        }
    }

    return 0;
}