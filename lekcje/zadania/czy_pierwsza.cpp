#include <iostream>
#include <math.h> 

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p--){
        int a;
        cin >> a;
        if(a != 0 && a!=1){
            bool pierwsza = true;
            for(int i = 2; i <= sqrt(a); ++i){
                if(a % i == 0){
                    pierwsza = false;
                    break;
                }
            }
            if(pierwsza)
                cout << "TAK" << endl;
            else 
                cout << "NIE" << endl;
        }
        else{
            cout << "NIE" << endl;
        }
    }
    return 0;
}