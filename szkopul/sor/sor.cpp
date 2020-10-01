#include <bits/stdc++.h>

using namespace std;

bool porowanie(string lewo, string prawo){
    if(lewo.length() != prawo.length()){
        return lewo.length() > prawo.length();
    }
    else{
        for(int i = 0 ; i < lewo.length(); ++i){
            if(lewo[i] != prawo[i]){
                return lewo[i] > prawo[i];
            } 
        }
    }
}

int main(){
    int a;
    cin >> a;
    vector <string> b;
    while(a--){
        string c;
        cin >> c;
        b.push_back(c);
    }

    sort(b.begin(), b.end(), porowanie);

    for(int i = b.size()-1; i >= 0; i-=1){
        cout << b[i] << endl;
    }

    return 0;
}