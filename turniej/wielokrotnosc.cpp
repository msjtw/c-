#include <iostream>

using namespace std;

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int a,b,k;
    cin >> a >> b >> k;
    k--;


    while(k--){
        long long c;
        c = b;
        b = a%100000007 * b%100000007;
        a = c;
    }

    cout << b;

    return 0;
}