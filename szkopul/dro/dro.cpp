#include <bits/stdc++.h>

using namespace std;

bool odw[100] = {};
short mac[101][100];
short st_w[100] = {};

void dfs(int cur, int final){
    if(odw[u] == 0){
        for(int i = 0; i < st_w[u]; ++i){
            dfs(mac[u][i]);
        }
        odw[u] = 1;
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    int start, stop;
    cin >> v >> e;
    cin >> start >> stop;

    for(int i = 0; i < e; i++){
        int sta, sto;
        cin >> sta >> sto;
        mac[sta][st_w[sta]] = sto;
        st_w[sta]++;
    }
    

    dfs(start, stop);

    return 0;
}