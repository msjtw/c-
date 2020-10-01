#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct as{
    int w;
    vector <char> s;
};

int pole[2001][2001];
as memo[1501][1501];

as dp(int row, int col){
    as wynik;
    if(memo[row][col].w == -1){
        if(row == 0 || col == 0){
            wynik.w = 0;
            wynik.s.clear();
        }
        else if(row == 1){
            as p = dp(row,col-1);
            wynik.w = p.w + pole[row][col];
            wynik.s = p.s;
            wynik.s.push_back('>');
        }
        else if(col == 1){
            as p = dp(row-1,col);
            wynik.w = p.w + pole[row][col];
            wynik.s = p.s;
            wynik.s.push_back('v');
        }
        else{
            as p1 = dp(row,col-1);
            as p2 = dp(row-1,col);
            if(p1.w  + pole[row][col] > p2.w + pole[row][col]){
                wynik.w = p1.w  + pole[row][col];
                wynik.s = p1.s;
                wynik.s.push_back('>');
            }
            else{
                wynik.w = p2.w  + pole[row][col];
                wynik.s = p2.s;
                wynik.s.push_back('v');
            }
        }
        memo[row][col].w = wynik.w;
        memo[row][col].s = wynik.s;
    }
    else{
        wynik.w = memo[row][col].w;
        wynik.s = memo[row][col].s;
    }
    //cout << "r:" << row << "   c:" << col << "   r+c-2:" << row+col-2 << "   wynik.s.size():" << wynik.s.size() << "   " << row+col-2-wynik.s.size() << endl;
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int p;
    cin >> p;
    for(int i =0; i < p; i++){
        int col, row;
        cin >> col >> row;
        for(int i = 1 ; i <= row; ++i){
            for(int j = 1; j <= col; j++){
                cin >> pole[i][j];
            }
        }

        for(int i = 0; i <= 1500; i++){
            for(int j = 0; j <= 1500; j++){
                memo[i][j].w = -1;
            }
        }

        as wynik = dp(row, col);
        cout << wynik.w << ' ';
        for(int i = 1; i < wynik.s.size(); ++i){
            cout << wynik.s[i];
        }
        cout << endl;
    }

    return 0;
}