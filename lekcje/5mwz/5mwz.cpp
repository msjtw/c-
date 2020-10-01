#include <iostream>

using namespace std;

int main(){
    int a1, b1, c1, a2, b2, c2;

    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    int w = a1*b2 - b1*a2;
    int wx = c1*b2 - b1*c2;
    int wy = a1*c2 - c1*a2;

    if(w != 0){
        cout << int(wx/w) << ' ' << int(wy/w);
    }
    else {
        if(wx == 0 && wy == 0){
        cout << "NIEOZNACZONY";
        }
        else{
            cout << "SPRZECZNY";
        }
    }

    return 0;
}