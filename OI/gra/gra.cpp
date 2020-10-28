#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct dziura{
    bool up;
    bool down;
    bool down_end;
};

dziura plansza[10010][10010];
int odw[10010][10010];

int plat, len, p;

int dp(int row, int col){
    if(col == len){
        return 0;
    }
    else{
        int wynik;
        if(odw[row][col] == -1){
            if(plansza[row][col].up){
                wynik = min(dp(row-1, col+1)+1, dp(row,  col+1));
            }
            else if(plansza[row][col+1].down){
                wynik = min(dp(row, col+2)+1, dp(row+1,  col+1));
            }
            else if(plansza[row][col+1].down_end){
                wynik = dp(row, col+2)+1;
            }
            else{
                wynik = dp(row, col+1);
            }
            odw[row][col] = wynik;
        }
        else{
            wynik = odw[row][col];
        }
        return wynik;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> plat >> len >> p;
    for(int i = 0; i < plat; i++){
        int a;
        cin >> a;
        while(a--){
            int b;
            cin >> b;
            if(a != 1){
                plansza[i+1][b].down = true;
                plansza[i+2][b].up = true;   
            }
            else{
                plansza[i+1][b].down_end = true;
            }
            
        }
    }

    for(int i = 0; i <= plat; i++){
        for(int j = 0; j < len; j++){
            odw[i][j] = -1;
        }
    }

    while(p--){
        int a;
        cin >> a;
        cout << dp(a, 1) << endl;
    }
    return 0;
}