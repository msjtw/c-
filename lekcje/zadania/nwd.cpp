#include <iostream>

using namespace std;

int nwd_f(int a, int b){
    while(b != 0){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){

    int a, b;
    cin >> a >> b;

    int nwd =  nwd_f(a, b);

    cout << nwd;
    return 0;
}