#include <iostream>
#include <string>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int pole[1001][1001] = {};
    
    int n , m;
    cin >> n >> m;

    for(int i = 0 ; i < n; i++){
        string a;
        cin >> a;
        for(int j = 0; j < m; j++){
            if(a[j] == 'X')
                pole[i][j+1] = pole[i][j] + 1;
            else 
                pole[i][j+1] = pole[i][j];
        }
    }

    // for(int i = 0; i < n  ; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << pole[i][j];
    //     }
    //     cout << endl;
    // }

    int suma = 0;

    for(int i =0; i < n; i++){
        for(int j = 0; j <= m; j++){
            if(pole[i][j+1] > pole[i][j]){
                int sumrzeczny = 0;
                for(int ij = i; ij < n; ij++){
                    sumrzeczny += pole[ij][m] - pole[ij][j];
                }
                if(sumrzeczny == 1)
                    suma++;
            }
        }
    }

    cout << suma;
    
    return 0;
}