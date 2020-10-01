#include <iostream>

using namespace std;

int main(){

    int j = 0;
    int a;
    while(true){
        cin >> a;
        if(a != 0)
            j++;
        else{
            j++;
            break;
        }
    }
    for(int i = 1; i <= j; ++i){
        cout << i << endl;
    }
}