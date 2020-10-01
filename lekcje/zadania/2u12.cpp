#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string liczba;
    cin >> liczba;

    bool dod = true;

    if(liczba[0] == '0'){
        dod = true;
    }
    else{
        dod = false;
        for(int i = 0 ; i < liczba.length(); i++){
            if(liczba[i] == '0')
                liczba[i] = '1';
            else
                liczba[i] = '0';
        }
    }
    int liczb = 0;
    int pot = 1;
    for(int i = liczba.length()-1; i >= 0 ; --i){
        liczb += ((liczba[i]-'0')*pot);
        pot *= 2;
    }

    if(dod)
        cout << liczb;
    else
        cout << liczb * -1;

    return 0;
}