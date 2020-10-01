#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int size, d;
    cin >> size >> d;

    string a;
    cin >> a;

    unsigned int memoo[1000000] = {};
    memoo[0] = 1;

    for(int i = 1; i < size; i++){
        if(a[i] == '1'){
            int j = min(6, i);
            for(; j > 0; j--){
                memoo[i] += memoo[i-j];
            }
        }
        memoo[i]%=d;
    }

    cout << memoo[size-1];

    return 0;
}