#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;
    
    getline(cin, a);

    if(a[a.length()-1] == '.'){
        cout << a ;
    }
    else{
        cout << a << '.';
    }

    return 0;
}