#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >> p;

    int i = 1;
    while(p--){
        int a;
        cin >> a;
        if(i == a){
            cout << a;
            return 0;
        }
        i++;
    }
    cout << 0;

    return 0;
}

