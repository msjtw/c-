#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >>p;
    while(p--){
        string a, b;
        cin >> a >> b;
        if(a.find(b) != string::npos){
            cout << a << endl;
        }
    }
    cout << 0;
    return 0;
}