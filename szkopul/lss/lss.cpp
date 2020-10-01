#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int krawedzi;
    cin >> krawedzi;

    int somsiedzi[100][100] = {};
    int po_ile_ten_ser[100] = {};

    int maxwierz = 0;

    while(krawedzi--){
        int a, b;
        cin >> a >> b;
        maxwierz = max(maxwierz, a);
        maxwierz = max(maxwierz, b);
        somsiedzi[a][po_ile_ten_ser[a]] = b;
        po_ile_ten_ser[a]++;

    }
    for(int i = 1; i <= maxwierz; i++){
        sort(somsiedzi[i], somsiedzi[i]+po_ile_ten_ser[i]);
    }

    for(int i = 1; i <= maxwierz; i++){
        cout << i << ": ";
        for(int j = 0; j < po_ile_ten_ser[i]; j++){
            cout << somsiedzi[i][j] << ",";
        }
        cout << endl;
    }

    return 0;
}