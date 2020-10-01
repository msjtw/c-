#include <iostream>
#include <vector>

using namespace std;

int main(){
    short mac[101][100];
    short st_w[100] = {};

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int sta, sto;
        cin >> sta >> sto;
        mac[sta][st_w[sta]] = sto;
        st_w[sta]++;
    }

    for(int ij = 1; ij <= v; ij++){
        bool odw[100] = {};
        vector <int> nodes;
        nodes.push_back(ij);
        
        while(nodes.size() > 0){
            odw[nodes[0]] = true;
            for(int i = 0; i < st_w[nodes[0]]; ++i){
                int do_odw = mac[nodes[0]][i];
                if(odw[do_odw] == false)
                    nodes.push_back(do_odw);
            }
            nodes.erase(nodes.begin());
        }

        int s = 0;
        for(int i = 1; i <= v; i++){
            s += odw[i];
        }

        if(s == v){
            cout << "TAK";
            return 0;
        }
    }

    cout << "NIE";

    return 0;
}