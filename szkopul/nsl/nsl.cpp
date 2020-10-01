#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int naj = 0;

    int p;
    cin >> p;
    while(p--){
        string s;
        cin >> s;
        int dl = s.length();
        naj = max(naj, dl);

    }

    cout << naj;
    return 0;
}