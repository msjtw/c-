#include <iostream>
#include <queue>

struct punkt{
    int x;
    int y;
    int ilosc;
};

using namespace std;

bool plansza[1005][1005];

int main(){
    int rows, cols, p;
    cin >> rows >> cols >> p;
    while(p--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i = a; i <= c; i++){
            for(int j = b; j <= d; j++){
                plansza[i][j] = !plansza[i][j];
            }
        }
        // for(int i = 1; i <= rows; i++){
        //     for(int j = 1; j <= cols; j++){
        //         cout << plansza[i][j];
        //     }
        //     cout << endl;
        // }
        int zmian = 0;
        bool zmiana[1010] {};

        for(int row = rows; row > 0; --row){
            bool w_lini = false;
            for(int col = cols; col > 0; --col){
                bool stan = plansza[row][col];
                if(w_lini)
                    zmiana[col] = !zmiana[col];
                //cout << stan;
                if(zmiana[col])
                    stan = !stan;
                //cout << stan << "\n";
                if(stan){
                    zmian++;
                    zmiana[col] = !zmiana[col];
                    w_lini = !w_lini;
                }
            }
        }
        cout << zmian << "\n\r";


    }

    return 0;
}