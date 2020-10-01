#include <bits/stdc++.h>

using namespace std;

int main(){
    int p;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    cin >> p;
    while(p--){
        int a;
        cin >> a;
        minimum = min(minimum, a);
        maximum = max(maximum, a);
    }

    cout << maximum - minimum;
    return 0;
}