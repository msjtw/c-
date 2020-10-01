#include <iostream>
#include <string>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a;
    string b;

    cin >> a >> b;

    int naj = 0;

    for(int i = 0; i < a.length(); i++){
        int licznik = 0;
        int j = i;
        for(int ii = 0; ii < b.length(); ii++){
            if(a[j] == b[ii]){
                j++;
                licznik++;
            }
            else{
                j = i;
                licznik = 0;
            }
            naj = licznik > naj ? licznik : naj;
        }
    }

    cout << naj;

    return 0;
}