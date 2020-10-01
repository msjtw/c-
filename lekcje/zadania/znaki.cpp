#include <iostream>

using namespace std;

void pisz(char c, int i){
    while(i--){
        cout << c;
    }
    cout << '\n';
}

int main(){
    char c;
    int a;

    cin >> c >> a;

    for(int i = 1 ;i <= a; ++i){
        pisz(c, i);
    }

    return 0;
}