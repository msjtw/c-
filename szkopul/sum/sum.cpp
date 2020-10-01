#include <bits/stdc++.h>

using namespace std;

vector <short> stov(string a){
    vector <short> b;
    for(char znak : a){
        b.push_back(int(znak-'0'));
    }
    return b;
}

vector <short> nadod(vector <short> a){
    for(int i = 0; i < a.size(); i++){
        if(a[i] < 0){
            a[i+1] -= 1;
            a[i] += 10;
        }
    }
    return a;
}

vector <short> nauje(vector <short> a){
    for(int i = 0; i < a.size(); i++){
        if(a[i] > 0){
            a[i+1] += 1;
            a[i] -= 10;
        }
        a[i] *= -1;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector <short> wynik;
    wynik.resize(210);

    int p;
    cin >> p;
    string a;
    while(p--){
        cin >> a;
        bool dodatnia = true;
        if(a[0] == '-')
            dodatnia = false;
        if(a[0] == '-' || a[0] == '+')
            a.erase(a.begin());
        auto przecinek = a.find(',');
        if(przecinek != string::npos)
            a.erase(a.begin() + przecinek);
        else 
            przecinek = a.size();

        int ile_dodac = 100-(a.size()-przecinek);
        for(int i = 0; i < ile_dodac; i++){
            a = a + "0";
        }

        while(a.size() < 200)
            a = "0" + a;

        vector <short> av = stov(a);

        if(dodatnia){
            for(int i = 0; i < wynik.size(); i++){
                wynik[i+10] += av[i];
            }
        }
        else{
            for(int i = 0; i < wynik.size(); i++){
                wynik[i+10] -= av[i];
            }
        }
    }

    reverse(wynik.begin(), wynik.end());

    for(int i = 0; i < wynik.size()-1; ++i){
        if(wynik[i] > 9){
            wynik[i+1] += wynik[i]/10;
            wynik[i] -= int(wynik[i]/10)*10;
        }
        else if(wynik[i] < -9){
            wynik[i+1] += wynik[i]/10;
            wynik[i] -= int(wynik[i]/10)*10;
        }
    }

    int najcyf = wynik.size()-1;
    while(wynik[najcyf] == 0)
        najcyf--;

    if(wynik[najcyf] > 0){
        wynik = nadod(wynik);
    }
    else{
        wynik = nauje(wynik);
        cout << "-";
    }

    int zernakoncu = 0;
    while(wynik[zernakoncu] == 0)
        zernakoncu++;

    zernakoncu = min(zernakoncu, 100);

    reverse(wynik.begin(), wynik.end());

    //cout << zernakoncu << endl;

    int cojest = 0;
    while(wynik[cojest] == 0 && cojest < 109)
        cojest++;
    
    while(cojest < wynik.size()-100){
        cout << wynik[cojest];
        cojest++;
    }
    
    if(zernakoncu < 100){
        cout << ",";
        while(cojest < wynik.size()-zernakoncu){
            cout << wynik[cojest];
            cojest++;
        }
    }


    return 0;
}