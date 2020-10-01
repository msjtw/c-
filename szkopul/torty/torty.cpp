#include <iostream>

using namespace std;

    int m , l ;

void skracanie(){
    int a = m, b = l;
    while(b != 0){
        int p = a;
        a = b;
        b = p % b;
    }

    m /= a;
    l /= a;
    //cout << a << endl;
}

int main(){
    int ilosc;
    cin >> ilosc;
    ilosc--;


    cin >> l >> m;
    skracanie();

    while(ilosc--){
        int l1, m1;
        cin >> l1 >> m1;
        l *= m1;
        l1 *= m;
        
        l += l1;
        m *= m1;
        skracanie();
    }

    while(l > m)
        l -= m;
    if( l != m)
        cout << m - l << '/' << m << endl;
    else 
        cout << 1 << endl;

    return 0;
}