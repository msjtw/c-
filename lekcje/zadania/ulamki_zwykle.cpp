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
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    a1 *= b2;
    a2 *= b1;
    b2 *= b1;
    a1 += a2;
    b1 = b2;

    int nwd = nwd_f(a1, b1);
    a1 /= nwd;
    b1 /= nwd;

    int cal = a1/b1;
    a1 -= cal*b1;

    if(cal > 0)
        cout << cal << ' ' << a1 << '/' << b1 << endl;
    else 
        cout <<  a1 << '/' << b1 << endl;

    return 0;
}