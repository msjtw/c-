#include <bits/stdc++.h>

using namespace std;

vector <int> dodawanie(vector <int> a, vector <int> b){
    if(b.size() > a.size()){
        swap(b, a);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int przezut = 0;
    for(int i = 0; i < b.size(); ++i){
        a[i] += b[i] + przezut;
        przezut = a[i]/10;
        a[i] %= 10;
    }
    if(przezut > 0){
        for(int i = b.size(); i < a.size(); i++){
            a[i] += przezut;
            przezut = a[i]/10;
            a[i] %= 10;
        }
        if(przezut > 0)
            a.push_back(przezut);
    
    }
    
    reverse(a.begin(), a.end());

    return a;
}

vector <int> odejmowanie(vector <int> a, vector <int> b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    for(int i = 0; i < b.size(); ++i){
        a[i] -= b[i];
        if(a[i] < 0){
            a[i]+=10;
            a[i+1]-=1;
        }
    }

    for(int i = a.size()-1; a[i] == 0 && i > 0; --i){
        a.pop_back();
    }   

    reverse(a.begin(), a.end());

    return a;
}

vector <int> dzielenie(vector <int> a, int b){
    vector <int> wynik;
    int nosilwilkrazykilka = 0;
    for(int i = 0; i < a.size(); ++i){
        int burro = (a[i] + nosilwilkrazykilka*10)/b;
        wynik.push_back(burro);
        nosilwilkrazykilka = (nosilwilkrazykilka*10 + a[i])-(burro*b);
    }

    reverse(wynik.begin(), wynik.end());
    for(int i = wynik.size()-1; wynik[i] == 0 && i > 0; --i){
        wynik.pop_back();
    }   

    reverse(wynik.begin(), wynik.end());

    return wynik;
}

vector <int> stov(string a){
    vector <int> b;
    for(char znak : a){
        b.push_back(int(znak-'0'));
    }
    return b;
}

int main() {
    string as;
    string bs;

    cin >> as >> bs;

    vector <int> a = stov(as);
    vector <int> b = stov(bs);

    vector <int> pola = dzielenie(a, 2);

    vector <int> polb1 = dzielenie(b, 2);
    vector <int> polb2 = odejmowanie(b, polb1);

    vector <int> wys =  dodawanie(pola, polb2);

    for(auto cyfr : wys){
        cout << cyfr;
    }

    cout << endl;
    
    wys =  odejmowanie(pola, polb1);

    // vector <int> wys = odejmowanie(stov(as), stov(bs));

    for(auto cyfr : wys){
        cout << cyfr;
    }

    return 0;
}