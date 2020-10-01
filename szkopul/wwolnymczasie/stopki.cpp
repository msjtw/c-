#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int odl, k, a;
    cin >> odl >> k >> a;

    int pk = 0;
    int pa = odl+1;

    bool koz = true;

    while(pa > pk){
        if(koz){
            koz = false;
            pk += k;
        }
        else{
            koz = true;
            pa -= a;
        }
    }

    if(koz) 
        cout << 0;
    else 
        cout << 1;

    return 0;
}