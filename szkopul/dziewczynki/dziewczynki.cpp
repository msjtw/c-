#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> osoby;
    int ilosc, dz, ch = 0;
    cin >> ilosc >> dz;
    int licznik = 0;
    bool c = false;

    for(int i =0; i < ilosc ; ++i){
        bool o;
        cin >> o;
        if(o == 1){
            ch ++;
            c = true;
        }
        else{
            if(c == true && ch > 0)
                osoby.push_back(ch);
            ch = 0;
            osoby.push_back(o);
            licznik++;
        }
        
    }

    if(ch > 0)
        osoby.push_back(ch);

    /*for(int i : osoby){
        cout << i << ' ';
    }
    */
    if(licznik >= dz){
        int min = osoby.size();

        for(int i = 0; i < osoby.size(); ++i){
            if(osoby[i] == 0){
                int ch = 0;
                int dziew = 0;
                for(int j = i; j < osoby.size() && dziew < dz; ++j){
                    if(osoby[j] == 0)
                        dziew++;
                    else
                        ch += osoby[j];
                }
                if(dziew >= dz)
                    min = min > ch ? ch : min;
            }
        }
        cout << min;
    }
    else{
        cout << "NIE";
    }
    
    return 0;
}