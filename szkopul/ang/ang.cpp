#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool czy_ana(string a, string b){
    if(a.length() == b.length()){
        bool popsuted = false;
        for(int i =0; i < a.length(); ++i){
            if(a[i] != b[i]){
                popsuted = true;
                break;
            }
        }
        if(popsuted)
            return false;
        else 
            return true;
    }
    else{
        return false;
    }
}

int main(){
    int p = 0;
    cin >> p;
    int licznik = 0;
    while(p--){
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(czy_ana(a, b)){
            licznik++;
        }
    }
    cout << licznik;

    return 0;
}