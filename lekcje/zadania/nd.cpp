#include <bits/stdc++.h>

using namespace std;

string ND(string x){

    for(int i = 0; i < x.size(); ++i){
        x[i] = toupper(x[i]);
    }

    return x;
}

string BS(string x){

    for(int i = 0; i < x.length(); ++i){
        if(x[i] == ' '){
            x.erase(x.begin()+i);
            i--;
        }
    }

    return x;
}

int main(){
    string t;
    getline(cin, t);

    t = ND(t);
    t = BS(t);

    bool popsuted = false;


    for(int i = 0, j = t.size()-1; i < j; ++i, --j){
        //cout << t[i] << "   " << t[j] << endl;
        if(t[i] != t[j]){
            popsuted = true;
            break;
        }
    }

    if(popsuted)
        cout << "NIE";
    else
        cout << "TAK";

    return 0;
}