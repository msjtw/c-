#include <iostream>

using namespace std;

long long int pot(long long int x, long long int n){
    if(x == 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(n % 2 == 1)
        return x*(pot(x, n-1)%1000000007);
    else{
        long long int a = pot(x, n/2)%1000000007;
        return a*a;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >> p;
    while(p--){
        long long int a;
        cin >> a;

        long long wynik = pot(a, a)%1000000007;
        wynik -= a;
        wynik += 1000000007;
        wynik %= 1000000007;
        cout << wynik << endl;
    }

    return 0;
}