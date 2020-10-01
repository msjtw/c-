#include <iostream>

using namespace std;

int silnia(int n){
    int wynik = 1;
    while(n > 0){
        wynik *= n;
        n--;
    }
    return wynik;
    
}

int main(){
    int n = 1;
    int a = silnia(n);
    int b = silnia(n+1);

    while(a < b){
        n++;
        a = silnia(n);
        b = silnia(n+1);
    }

    cout << n+1 << ":  " << a;

    

    return  0;
}