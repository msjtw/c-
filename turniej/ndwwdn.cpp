#include <iostream>

using namespace std;

int nwd(int a, int b){

    int c;

    while(b != 0){
        c = b;
        b = a%b;
        a =c;
    }
    return a;
}

int main(){

    int liczb;
    cin >> liczb;

    int tab[500000] {};

    for(int i =0; i < liczb; ++i){
        cin >> tab[i];
    }

    int ndw = nwd(tab[0], tab[1]);

    for(int i = 2; i < liczb; ++i){
        ndw = nwd(ndw, i);
    }

    cout << ndw;

    return 0;
}