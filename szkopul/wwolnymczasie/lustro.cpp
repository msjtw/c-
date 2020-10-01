#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a;
    cin >> a;

    vector <int> b;

    while(a != 0){
        b.push_back(a % 10);
        a/=10;
    }

    bool samezera = true;

    for(auto d : b){

        if(samezera){
            if(d != 0){
                samezera = false;
                cout << d;
            }
        }
        else
            cout << d;
    }
    

    return 0;
}