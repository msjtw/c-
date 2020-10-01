#include <iostream>
#include <vector>
#include <math.h> 

using namespace std;

bool find(int a, vector <int> pierwsze){
    for(int i = 0; i < 25; ++i){
        if(a == pierwsze[i]){
            return true;
        }
    }
    return false;
}

vector <int> gen_l_p(int ilosc){
    vector <int> liczby;
    int i = 2;
    while(liczby.size() < ilosc){
        bool czy = true;
        for(int j = 2; j <= sqrt(i); ++j){
            if(i % j == 0){
                czy = false;
            }
        }
        if(czy)
            liczby.push_back(i);
        i++;
    }

    return liczby;
}

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector <int> pierwsze = gen_l_p(100);

    int a;
    cin >> a;

    while(not(find(a, pierwsze))){
        int i = 0;
        while(a%pierwsze[i] != 0){
            i++;
        }
        cout << pierwsze[i] << endl;
        a/=pierwsze[i];
        
    }

    cout << a << endl;

    return 0;
}