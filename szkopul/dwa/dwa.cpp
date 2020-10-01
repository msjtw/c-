#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dlugosc;
    cin >> dlugosc;
    string a, b;
    cin >> a >> b;

    int pytania;
    cin >> pytania;

    for(;pytania > 0; --pytania){
        int pierwsze, drugie;
        cin >> pierwsze >> drugie;
        swap(a[pierwsze], b[drugie]);
        if(a.compare(b) > 0)
            cout << 1 << endl;
        else if(a.compare(b) < 0)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}