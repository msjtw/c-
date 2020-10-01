#include <iostream>
#include <string>

using namespace std;

int main(){
    int p, b;
    int licznik = 0;
    cin >> p >> b;
    while (p--)
    {
        string a;
        cin >> a;
        if(a.length() > b)
            licznik++;
    }
    
    cout << licznik;

    return 0;
}