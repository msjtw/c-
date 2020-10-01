#include <iostream>
#include <string>

using namespace std;

string fib(int slowo){
    string a = "b";
    string b = "a";

    if(slowo == 1){
        return a;
    }
    else if(slowo == 2){
        return b;
    }
    else{
        for(int i = 0; i < slowo - 2; ++i){
            string c = b + a;
            a = b;
            b = c;
        }
        return b;
    }
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string szukane;
    cin >> szukane;
    int slowo;
    cin >> slowo;

    string fibbo = fib(slowo);

    int licznik = 0;

    for(int i = 0 ; i < fibbo.length(); ++i){

        int pop = 0;

        for(int j = 0; j < szukane.length(); ++j){
            if(fibbo[i +j] == szukane[j]){
                pop++; 
            }
            else{
               break;
            }
            
        }

        if(pop == szukane.length()){
            licznik ++;
        }
    }

    cout << licznik;

    return 0;
}