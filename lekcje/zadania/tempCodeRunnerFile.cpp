#include <iostream>
#include <string>

using namespace std;

int main(){
    string tekst;
    getline(cin, tekst);
    for(auto a : tekst){
        cout << a;
    }

    return 0;
}