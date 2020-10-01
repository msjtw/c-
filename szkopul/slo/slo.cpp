#include <bits/stdc++.h>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<string> s;
    
    while(true){
        string a;
        cin >> a;
        if(a == "prrr"){
            cout << s.size()+1;
            return 0;
        }
        s.insert(a);
    }

    return 0;
}