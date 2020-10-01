#include <iostream>
#include <string>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a;
    cin >> a;

    for(int i = 0; i < a.length() - 1; i++){
        if(a[i] != a[i+1]){
            cout << a[i];
        }
    }

    //if(a[a.length()-2] != a[a.length()-1]){
        cout << a[a.length() -1];
    //}

    return 0;
}