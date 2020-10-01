#include <iostream>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int wierz, kraw;
    cin >> wierz >> kraw;

    int mac[101][101] {};

    while(kraw--){
        int a, b;
        cin >> a >> b;

        mac[a][b] = 1;
        mac[b][a] = 1;
    }

    for(int i = 1; i <= wierz; i++){
        for(int j = 1; j <= wierz; j++){
            cout << mac[i][j];
        }
        cout << endl;
    }

    return 0;
}