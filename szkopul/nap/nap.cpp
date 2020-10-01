#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> zuzia;
    vector <int> antek;

    bool antekk = false;
    int il;
    cin >> il;
    while(il--){
        int a;
        cin >> a;
        if(antekk == true){
            antek.push_back(a);
            antekk = false;
        }
        else{
            zuzia.push_back(a);
            antekk = true;
        }

    }

    for(int a : zuzia)
        cout << a << ' ';

    cout << endl;

    for(int a : antek)
        cout << a << ' ';
    return 0;
}