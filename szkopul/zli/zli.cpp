#include <bits/stdc++.h>

using namespace std;

int main(){
    int znaki[58] = {};
    int p;
    cin >> p;
    cin.ignore();
    while(p--){
        string a = "";
        getline(cin, a);
        vector <int> b;
        b.clear();
        for(int i = 0; i < a.length(); i++){
            if(a[i] != ' ')
                b.push_back(a[i]-'A');
        }
        for(int i = 0; i < b.size(); i++){
            znaki[b[i]]++;
        }
    }

    for(int i = 30; i < 58; i++){
        if(znaki[i] > 0)
            cout << char(i+'A') << " " << znaki[i] << endl;
    }
    for(int i = 0; i < 30; i++){
        if(znaki[i] > 0)
            cout << char(i+'A') << " " << znaki[i] << endl;
    }
    return 0;
}