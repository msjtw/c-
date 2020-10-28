#include <iostream>

using namespace std;

int main(){
    int a;
    cin >> a;
    int suma_dz = 0;
    for(int i = 1; i < a; i++){
        if(a%i==0)
            suma_dz += i;
    }
    cout << (suma_dz < a ? "TAK" : "NIE");

    return 0;
}